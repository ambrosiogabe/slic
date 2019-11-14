/* ==============================================================
/* This file contains all of the implementations for the header,
/* as well as several static functions that are meant to be 
/* helpers private to this file.
/*
/* Author: Gabe Ambrosio
/* ============================================================== */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#include "compiler.h"

/* ==============================================================
/* Instruction container inserter deleter etc
/* ============================================================== */
void initInstructionContainer() {
    instructions.capacity = 8;
    instructions.size = 0;
    instructions.instructions = malloc(sizeof(Instruction) * 8);
}

static void insertInstruction(Instruction instruction) {
    if (instructions.size + 1 >= instructions.capacity) {
        instructions.capacity *= 2;
        instructions.instructions = realloc(instructions.instructions, sizeof(Instruction) * instructions.capacity);
    }

    instructions.instructions[instructions.size] = instruction;
    instructions.size++;
}

void insertFloatInstruction(InstructionType type, float operand) {
    Instruction instruction;
    instruction.line = instructions.size + 1;
    instruction.operand.fval = operand;
    instruction.type = type;
    instruction.hasOperand = 1;
    instruction.operandIsFloat = 1;

    insertInstruction(instruction);
}

void insertIntInstruction(InstructionType type, int operand) {
    Instruction instruction;
    instruction.line = instructions.size + 1;
    instruction.operand.ival = operand;
    instruction.type = type;
    instruction.hasOperand = 1;
    instruction.operandIsFloat = 0;

    insertInstruction(instruction);
}

void insertEmptyInstruction(InstructionType type) {
    Instruction instruction;
    instruction.line = instructions.size + 1;
    instruction.type = type;
    instruction.hasOperand = 0;
    instruction.operandIsFloat = 0;

    insertInstruction(instruction);
}

/* ==============================================================
/* Helper methods to walk individual nodes of the AST and 
/* output GSTAL code.
/* ============================================================== */
static void walkNode(AstNode* node);
static void walkVariableNode(AstNode* node, int loadVal);
static void generateCode();

static void walkCountingLoop(AstNode* node) {
    // Initialize the variable to start expression
    // and the generated variable to end expression
    walkNode(node->as.countingLoop->synthesizedAssignment);
    walkNode(node->as.countingLoop->synthesizedEndValue);

    // Keep track of top of loop and walk checking expression
    int topOfLoop = instructions.size;
    walkNode(node->as.countingLoop->synthesizedCheckExpr);
    int jmpToBottomLoop = instructions.size;
    insertIntInstruction(JPF, -1);

    AstNode* current = node->as.countingLoop->body;
    while (current != NULL) {
        walkNode(current);
        current = current->next;
    }
    walkNode(node->as.countingLoop->synthesizedIncrement);
    insertIntInstruction(JMP, topOfLoop);

    instructions.instructions[jmpToBottomLoop].operand.ival = instructions.size;
}

static void walkWhileLoop(AstNode* node) {
    int topOfLoop = instructions.size;
    walkNode(node->as.whileLoop->conditionExpression);
    int jmpPastLoopBody = instructions.size;
    insertIntInstruction(JPF, -1);

    AstNode* current = node->as.whileLoop->whileBlock;
    while (current != NULL) {
        walkNode(current);
        current = current->next;
    }
    insertIntInstruction(JMP, topOfLoop);

    instructions.instructions[jmpPastLoopBody].operand.ival = instructions.size;
}

static void walkIfStmtNode(AstNode* node) {
    walkNode(node->as.ifStmt->conditionStatement);
    int jmpPastIf = instructions.size;
    insertIntInstruction(JPF, -1);

    AstNode* current = node->as.ifStmt->ifBlock;
    while (current != NULL) {
        walkNode(current);
        current = current->next;
    }

    if (node->as.ifStmt->elseBlock != NULL) {
        int jmpPastElse = instructions.size;
        insertIntInstruction(JMP, -1);
        instructions.instructions[jmpPastIf].operand.ival = instructions.size;

        current = node->as.ifStmt->elseBlock;
        while (current != NULL) {
            walkNode(current);
            current = current->next;
        }
        instructions.instructions[jmpPastElse].operand.ival = instructions.size;
    } else {
        instructions.instructions[jmpPastIf].operand.ival = instructions.size;
    }
}

static void walkAssignmentNode(AstNode* node) {
    walkVariableNode(node->as.assignStmt->variableNode, 0);
    walkNode(node->as.assignStmt->exprNode);

    if (!node->as.assignStmt->exprNode->isFloaty && node->as.assignStmt->variableNode->isFloaty) {
        insertEmptyInstruction(ITF);
    } else if (node->as.assignStmt->exprNode->isFloaty && !node->as.assignStmt->variableNode->isFloaty) {
        insertEmptyInstruction(FTI);
    }

    insertEmptyInstruction(STO);
}

static void walkArrayAssignmentNode(AstNode* node) {
    walkVariableNode(node->as.arrayAssignStmt->variableNode, 0);
    walkNode(node->as.arrayAssignStmt->indexExpr);

    if (node->as.arrayAssignStmt->indexExpr->isFloaty) {
        insertEmptyInstruction(FTI);
    }

    insertEmptyInstruction(ADI);
    walkNode(node->as.arrayAssignStmt->valExpr);

    if (!node->as.arrayAssignStmt->valExpr->isFloaty && node->as.arrayAssignStmt->variableNode->isFloaty) {
        insertEmptyInstruction(ITF);
    } else if (node->as.arrayAssignStmt->valExpr->isFloaty && !node->as.arrayAssignStmt->variableNode->isFloaty) {
        insertEmptyInstruction(FTI);
    }

    insertEmptyInstruction(STO);
}

static void walkArrayLoadNode(AstNode* node) {
    insertIntInstruction(LAA, node->as.arrayLoad->symEntry.address);
    walkNode(node->as.arrayLoad->indexExpr);

    if (node->as.arrayLoad->indexExpr->isFloaty) {
        insertEmptyInstruction(FTI);
    }

    insertEmptyInstruction(ADI);
    insertEmptyInstruction(LOD);
}

static void walkReadArrayNode(AstNode* node) {
    insertIntInstruction(LAA, node->as.readArrayNode->variable->as.variable.address);
    walkNode(node->as.readArrayNode->expr);

    if (node->as.readArrayNode->expr->isFloaty) {
        insertEmptyInstruction(FTI);
    }

    insertEmptyInstruction(ADI);
    if (node->as.readArrayNode->variable->as.variable.type == INT)
        insertEmptyInstruction(INI);
    else 
        insertEmptyInstruction(INF);
    
    insertEmptyInstruction(STO);
}

static void walkReadNode(AstNode* node) {
    insertIntInstruction(LAA, node->as.readArrayNode->variable->as.variable.address);
    if (node->as.readArrayNode->variable->as.variable.type == INT)
        insertEmptyInstruction(INI);
    else 
        insertEmptyInstruction(INF);
    insertEmptyInstruction(STO);
}

static void walkValueNode(AstNode* node) {
    if (node->isFloaty) {
        insertFloatInstruction(LLF, node->as.value->as.rVal);
    } else {
        insertIntInstruction(LLI, node->as.value->as.iVal);
    }
}

static void walkStringNode(AstNode* node) {
    char* string = node->as.string;

    for (char* c = string + 1; *c != '\"'; c++) {
        insertIntInstruction(LLI, *c);
        insertEmptyInstruction(PTC);
    }
}

static void walkNewlineNode(AstNode* node) {
    insertEmptyInstruction(PTL);
}

static void walkVariableNode(AstNode* node, int loadVal) {
    insertIntInstruction(LAA, node->as.variable.address);
    if (loadVal)
        insertEmptyInstruction(LOD);
}

static void walkUnaryNode(AstNode* node) {
    int isFloatExpr = node->isFloaty;
    walkNode(node->as.unaryExpr->expr);
    if (!node->as.unaryExpr->expr->isFloaty && isFloatExpr) {
        insertEmptyInstruction(ITF);
    } else if (node->as.unaryExpr->expr->isFloaty && !isFloatExpr) {
        insertEmptyInstruction(FTI);
    }

    switch (node->as.unaryExpr->op) {
        case MINUS_OP:   isFloatExpr ? insertEmptyInstruction(NGF) : insertEmptyInstruction(NGI); break;
        case NOT_OP:     {
            if (isFloatExpr) {
                insertFloatInstruction(LLF, 0.0f);
                insertEmptyInstruction(EQF);
            } else {
                insertIntInstruction(LLI, 0);
                insertEmptyInstruction(EQI);
            }
            node->isFloaty = 0; 
            break;
        }
    }
}

static void walkExprNode(AstNode* node) {
    int isFloatExpr = node->isFloaty;
    walkNode(node->as.expression->leftExpr);

    if (node->as.expression->leftExpr->isFloaty && !isFloatExpr && node->as.expression->op != MODULUS_OP) {
        insertEmptyInstruction(FTI);
    } else if (!node->as.expression->leftExpr->isFloaty && isFloatExpr && node->as.expression->op != MODULUS_OP) {
        insertEmptyInstruction(ITF);
    } else if (node->as.expression->leftExpr->isFloaty && node->as.expression->op == MODULUS_OP) {
        insertEmptyInstruction(FTI);
    }

    if (node->as.expression->op == OR_OP || node->as.expression->op == AND_OP) {
        insertIntInstruction(LLI, 0);
        insertEmptyInstruction(NEI);
    }

    walkNode(node->as.expression->rightExpr);

    if (node->as.expression->rightExpr->isFloaty && !isFloatExpr && node->as.expression->op != MODULUS_OP) {
        insertEmptyInstruction(FTI);
    } else if (!node->as.expression->rightExpr->isFloaty && isFloatExpr && node->as.expression->op != MODULUS_OP) {
        insertEmptyInstruction(ITF);
    } else if (node->as.expression->rightExpr->isFloaty && node->as.expression->op == MODULUS_OP) {
        insertEmptyInstruction(FTI);
    }

    if (node->as.expression->op == OR_OP || node->as.expression->op == AND_OP) {
        insertIntInstruction(LLI, 0);
        insertEmptyInstruction(NEI);
    }
    
    switch (node->as.expression->op) {
        case PLUS_OP:             isFloatExpr ? insertEmptyInstruction(ADF) : insertEmptyInstruction(ADI); break;
        case MINUS_OP:            isFloatExpr ? insertEmptyInstruction(SBF) : insertEmptyInstruction(SBI); break;
        case MULTIPLY_OP:         isFloatExpr ? insertEmptyInstruction(MLF) : insertEmptyInstruction(MLI); break;
        case DIVIDE_OP:           isFloatExpr ? insertEmptyInstruction(DVF) : insertEmptyInstruction(DVI); break;
        case MODULUS_OP:          {
            walkNode(node->as.expression->leftExpr);
            if (node->as.expression->leftExpr->isFloaty) {
                insertEmptyInstruction(FTI);
            }
            walkNode(node->as.expression->rightExpr);
            if (node->as.expression->rightExpr->isFloaty) {
                insertEmptyInstruction(FTI);
            }
            insertEmptyInstruction(DVI);
            insertEmptyInstruction(MLI);
            insertEmptyInstruction(SBI);
            node->isFloaty = 0;
            break;
        }
        case GRT_THAN_OP:         isFloatExpr ? insertEmptyInstruction(GTF) : insertEmptyInstruction(GTI); break;
        case GRT_THAN_EQUAL_OP:   isFloatExpr ? insertEmptyInstruction(GEF) : insertEmptyInstruction(GEI); break;
        case LESS_THAN_OP:        isFloatExpr ? insertEmptyInstruction(LTF) : insertEmptyInstruction(LTI); break;
        case LESS_THAN_EQUAL_OP:  isFloatExpr ? insertEmptyInstruction(LEF) : insertEmptyInstruction(LEI); break;
        case EQUAL_OP:            isFloatExpr ? insertEmptyInstruction(EQF) : insertEmptyInstruction(EQI); break;
        case NOT_EQUAL_OP:        isFloatExpr ? insertEmptyInstruction(NEF) : insertEmptyInstruction(NEI); break;
        case AND_OP: {
            insertEmptyInstruction(MLI);
            insertIntInstruction(LLI, 0);
            insertEmptyInstruction(NEI);
            node->isFloaty = 0;
            break;
        }
        case OR_OP: {
            insertEmptyInstruction(ADI);
            insertIntInstruction(LLI, 0);
            insertEmptyInstruction(NEI);
            node->isFloaty = 0;
            break;
        }
        default:                  yyerrorInfo("Error: Unknown binary operator!", tokenTable.table[node->tokenInfoIndex]); exit(-1);
    }
}

static void walkPrintExpr(AstNode* node) {
    walkNode(node->as.printExpr->printExpr);
    if (node->as.printExpr->printExpr->isFloaty) insertEmptyInstruction(PTF);
    else insertEmptyInstruction(PTI);
}

static void walkPrintListNode(AstNode* node) {
    AstNode* current = node->as.printList->firstItem;
    while (current != NULL) {
        walkNode(current);
        current = current->next;
    }
}


/* ==============================================================
/* Initialization function
/* ============================================================== */
void initSyntaxTree() {
    astRootNode = NULL;
}

/* ==============================================================
/* Function to walk the whole tree. It simply starts walking 
/* the rootNode, and continues to walk the next nodes until
/* there are no nodes left to walk.
/* ============================================================== */
void walkSyntaxTree() {
    if (astRootNode == NULL) {
        yyerrorInfo("Error: No syntax tree generated! You may have an empty data and algorithm section.", tokenTable.table[0]);
        exit(-1);
    }

    int offset = 0;
    for (int i=0; i < symbolTable.size; i++) {
        offset += symbolTable.symbols[i].size;
    }
    insertIntInstruction(ISP, offset);

    AstNode* currentNode = astRootNode;
    while (currentNode != NULL) {
        walkNode(currentNode);
        currentNode = currentNode->next;
    }
    insertEmptyInstruction(HLT);
    generateCode();
}

/* ==============================================================
/* Master helper function that determines which function 
/* to call depending on what type of AstNode it is dealing with
/* ============================================================== */
static void walkNode(AstNode* node) {
    switch(node->type) {
        case ASSIGN_STMT_NODE:
            walkAssignmentNode(node);
            break;
        case ARRAY_ASSIGN_STMT_NODE:
            walkArrayAssignmentNode(node);
            break;
        case EXPR_NODE:
            walkExprNode(node);
            break;
        case UNARY_EXPR_NODE:
            walkUnaryNode(node);
            break;
        case VALUE_NODE:
            walkValueNode(node);
            break;
        case VARIABLE_NODE:
            walkVariableNode(node, 1);
            break;
        case ARRAY_LOAD_NODE:
            walkArrayLoadNode(node);
            break;
        case IF_STMT_NODE:
            walkIfStmtNode(node);
            break;
        case STRING_VALUE_NODE:
            walkStringNode(node);
            break;
        case NEWLINE_NODE:
            walkNewlineNode(node);
            break;
        case PRINT_EXPRESSION_NODE:
            walkPrintExpr(node);
            break;
        case PRINT_LIST_NODE:
            walkPrintListNode(node);
            break;
        case WHILE_LOOP_NODE:
            walkWhileLoop(node);
            break;
        case COUNTING_LOOP_NODE:
            walkCountingLoop(node);
            break;
        case READ_NODE:
            walkReadNode(node);
            break;
        case READ_ARRAY_NODE:
            walkReadArrayNode(node);
            break;
        case EXIT_NODE:
            insertEmptyInstruction(HLT);
            break;
        default:
            printf("Do not know how to walk this! %d", node->type);
            exit(-1);
    }
}

void freeInstructionContainer() {
    free(instructions.instructions);
}

static void generateCode() {
    for (int i=0; i < instructions.size; i++) {
        Instruction instruction = instructions.instructions[i];
        switch(instruction.type) {
            case ADI: printf("ADI\n"); break;
            case ADF: printf("ADF\n"); break;
            case SBI: printf("SBI\n"); break;
            case SBF: printf("SBF\n"); break;
            case MLI: printf("MLI\n"); break;
            case MLF: printf("MLF\n"); break;
            case DVI: printf("DVI\n"); break;
            case DVF: printf("DVF\n"); break;
            case NGI: printf("NGI\n"); break;
            case NGF: printf("NGF\n"); break;
            case EQI: printf("EQI\n"); break;
            case EQF: printf("EQF\n"); break;
            case NEI: printf("NEI\n"); break;
            case NEF: printf("NEF\n"); break;
            case LTI: printf("LTI\n"); break;
            case LTF: printf("LTF\n"); break;
            case LEI: printf("LEI\n"); break;
            case LEF: printf("LEF\n"); break;
            case GTI: printf("GTI\n"); break;
            case GTF: printf("GTF\n"); break;
            case GEI: printf("GEI\n"); break;
            case GEF: printf("GEF\n"); break;
            case FTI: printf("FTI\n"); break;
            case ITF: printf("ITF\n"); break;
            case PTI: printf("PTI\n"); break;
            case PTF: printf("PTF\n"); break;
            case PTC: printf("PTC\n"); break;
            case PTL: printf("PTL\n"); break;
            case INI: printf("INI\n"); break;
            case INF: printf("INF\n"); break;
            case LLI: printf("LLI %d\n", instruction.operand.ival); break;
            case LLF: printf("LLF %f\n", instruction.operand.fval); break;
            case ISP: printf("ISP %d\n", instruction.operand.ival); break;
            case DSP: printf("DSP %d\n", instruction.operand.ival); break;
            case STO: printf("STO\n"); break;
            case STM: printf("STM\n"); break;
            case LOD: printf("LOD\n"); break;
            case LAA: printf("LAA %d\n", instruction.operand.ival); break;
            case LRA: printf("LRA %d\n", instruction.operand.ival); break;
            case JMP: printf("JMP %d\n", instruction.operand.ival); break;
            case JPF: printf("JPF %d\n", instruction.operand.ival); break;
            case PAR: printf("PAR %d\n", instruction.operand.ival); break;
            case CAL: printf("CAL %d\n", instruction.operand.ival); break;
            case RET: printf("RET\n"); break;
            case NOP: printf("NOP\n"); break;
            case HLT: printf("HLT\n"); break;
            default:
                printf("Unkonwn instruction! %d", instruction.type);
                exit(-1);
        }
    }
}