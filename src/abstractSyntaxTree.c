/* ==============================================================
/* This file contains the implementation for abstractSyntaxTree.h
/* See that file for more information about the functions and 
/* structs.
/* 
/* Author: Gabe Ambrosio
/* ============================================================== */

#include "compiler.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include "abstractSyntaxTree.h"

static void freeNode(AstNode* node);

static AstNode* initNode(NodeType type, int tokenIndex) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->type = type;
    newNode->tokenInfoIndex = tokenIndex;
    newNode->isFloaty = 0;

    return newNode;
}

/* ==============================================================
/* All the functions to create AstNodes
/* ============================================================== */
AstNode* makeReturnNode(int tokenInfoIndex, AstNode* expr, char* funcName) {
    AstNode* newNode = initNode(RETURN_NODE, tokenInfoIndex);
    newNode->as.returnNode = malloc(sizeof(ReturnNode));
    newNode->as.returnNode->expr = expr;
    newNode->as.returnNode->funcName = funcName;

    return newNode;
}

AstNode* makeEndOfFunctionNode(int tokenInfoIndex, char* funcName) {
    AstNode* newNode = initNode(END_OF_FUNCTION_NODE, tokenInfoIndex);
    newNode->as.endOfFunction = malloc(sizeof(EndOfFunctionNode));
    newNode->as.endOfFunction->funcName = funcName;

    return newNode;
}

AstNode* makeFunctionCallNode(int tokenInfoIndex, char* funcName, AstNode* variableList) {
    AstNode* newNode = initNode(FUNCTION_CALL_NODE, tokenInfoIndex);
    newNode->as.functionCall = malloc(sizeof(FunctionCallNode));
    newNode->as.functionCall->funcName = funcName;
    newNode->as.functionCall->variableList = variableList;

    return newNode;
}

AstNode* makeFunctionNode(int tokenInfoIndex) {
    AstNode* newNode = initNode(FUNCTION_NODE, tokenInfoIndex);
    return newNode;
}

AstNode* makeCountingLoopNode(int tokenInfoIndex, AstNode* variable, int isUpward, AstNode* startExpr, AstNode* endExpr, AstNode* body) {
    if (variable->as.variable.type == REAL) {
        yyerrorInfo("Counting loops must have an integer variable!", tokenTable.table[variable->tokenInfoIndex]);
    }

    AstNode* newNode = initNode(COUNTING_LOOP_NODE, tokenInfoIndex);
    
    // Initialize easy stuff
    newNode->as.countingLoop = malloc(sizeof(CountingLoop));
    newNode->as.countingLoop->variable = variable;
    newNode->as.countingLoop->body = body;

    // Synthesize an assignment of the start expression to the variable
    newNode->as.countingLoop->synthesizedAssignment = makeAssignmentNode(variable->tokenInfoIndex, variable->as.variable.name, startExpr);

    // Create a valueOne node containing 1, or -1, for incrementing or decrementing the variable
    AstNode* valueOne = NULL;
    if (isUpward) valueOne = makeIntValueNode(tokenInfoIndex, 1);
    else          valueOne = makeIntValueNode(tokenInfoIndex, -1);

    // Synthesize an add operation to increment or decrement variable in the loop
    AstNode* addOperation = makeExprNode(tokenInfoIndex, PLUS_OP, variable, valueOne);
    newNode->as.countingLoop->synthesizedIncrement = makeAssignmentNode(variable->tokenInfoIndex, variable->as.variable.name, addOperation);

    // Create a variable to hold the endExpression value and insert in symbol table
    char* varBuffer = malloc(sizeof(char) * 10);
    snprintf(varBuffer, sizeof(char) * 10, "%d", tokenInfoIndex);
    insertSymbolTable(INT, varBuffer, SCALAR, 1);
    AstNode* newVariable = makeVariableNode(tokenInfoIndex, varBuffer);

    // Synthesize an assignment to that variable, and a check if the startVariable is greater than this variable
    newNode->as.countingLoop->synthesizedEndValue = makeAssignmentNode(tokenInfoIndex, newVariable->as.variable.name, endExpr);
    if (isUpward)
        newNode->as.countingLoop->synthesizedCheckExpr = makeExprNode(tokenInfoIndex, LESS_THAN_EQUAL_OP, variable, newVariable);
    else 
        newNode->as.countingLoop->synthesizedCheckExpr = makeExprNode(tokenInfoIndex, GRT_THAN_EQUAL_OP, variable, newVariable);

    return newNode;
}

AstNode* makeWhileLoopNode(int tokenInfoIndex, AstNode* conditionExpr, AstNode* whileBlock) {
    AstNode* newNode = initNode(WHILE_LOOP_NODE, tokenInfoIndex);
    newNode->as.whileLoop = malloc(sizeof(WhileLoop));
    newNode->as.whileLoop->conditionExpression = conditionExpr;
    newNode->as.whileLoop->whileBlock = whileBlock;

    return newNode;
}

AstNode* makeIfStatement(AstNode* ifBlock, AstNode* ifCondition, AstNode* elseBlock) {
    AstNode* newNode = initNode(IF_STMT_NODE, ifBlock->tokenInfoIndex);
    newNode->as.ifStmt = malloc(sizeof(IfStmt));
    newNode->as.ifStmt->ifBlock = ifBlock;
    newNode->as.ifStmt->conditionStatement = ifCondition;
    newNode->as.ifStmt->elseBlock = elseBlock;

    return newNode;
}

AstNode* makeReadNode(int tokenInfoIndex, char* name) {
    AstNode* newNode = initNode(READ_NODE, tokenInfoIndex);
    newNode->as.readArrayNode = malloc(sizeof(ReadArrayNode));
    newNode->as.readArrayNode->variable = makeVariableNode(tokenInfoIndex, name);
    newNode->as.readArrayNode->expr = NULL;

    return newNode;
}

AstNode* makeReadArrayNode(int tokenInfoIndex, char* name, AstNode* expr) {
    AstNode* newNode = initNode(READ_ARRAY_NODE, tokenInfoIndex);

    newNode->as.readArrayNode = malloc(sizeof(ReadArrayNode));
    newNode->as.readArrayNode->variable = makeVariableNode(tokenInfoIndex, name);
    newNode->as.readArrayNode->expr = expr;

    return newNode;
}

AstNode* makeAssignmentNode(int tokenInfoIndex, char* name, AstNode* expr) {
    if (!IS_TYPE_OF_EXPR(*expr)) {
        yyerrorInfo("You can only assign an expression to a variable!", tokenTable.table[expr->tokenInfoIndex]);
    }

    AstNode* newNode = initNode(ASSIGN_STMT_NODE, tokenInfoIndex);
    newNode->as.assignStmt = malloc(sizeof(AssignStmt));
    AstNode* varNode = makeVariableNode(tokenInfoIndex, name);
    newNode->as.assignStmt->variableNode = varNode;
    newNode->as.assignStmt->exprNode = expr;
    newNode->isFloaty = newNode->as.assignStmt->variableNode->as.variable.type == REAL;

    return newNode;
}

AstNode* makeArrayAssignmentNode(int tokenInfoIndex, char* name, AstNode* indexExpr, AstNode* valExpr) {
    if (!IS_TYPE_OF_EXPR(*indexExpr)) {
        yyerrorInfo("You can only use expressions as indices in arrays!", tokenTable.table[indexExpr->tokenInfoIndex]);
    }
    if (!IS_TYPE_OF_EXPR(*valExpr)) {
        yyerrorInfo("You can only assign expressions to variables!", tokenTable.table[valExpr->tokenInfoIndex]);
    }

    AstNode* newNode = initNode(ARRAY_ASSIGN_STMT_NODE, tokenInfoIndex);
    AstNode* varNode = makeVariableNode(tokenInfoIndex, name);
    newNode->as.arrayAssignStmt = malloc(sizeof(ArrayAssignStmt));
    newNode->as.arrayAssignStmt->variableNode = varNode;
    newNode->as.arrayAssignStmt->indexExpr = indexExpr;
    newNode->as.arrayAssignStmt->valExpr = valExpr;
    newNode->isFloaty = newNode->as.arrayAssignStmt->variableNode->as.variable.type == REAL;

    return newNode;
}

AstNode* makeExprNode(int tokenInfoIndex, ExprOp op, AstNode* leftExpr, AstNode* rightExpr) {
    AstNode* newNode = initNode(EXPR_NODE, tokenInfoIndex);
    newNode->as.expression = malloc(sizeof(Expr));
    newNode->as.expression->op = op;
    newNode->isFloaty = leftExpr->isFloaty | rightExpr->isFloaty;

    if (!IS_TYPE_OF_EXPR(*leftExpr) || !IS_TYPE_OF_EXPR(*rightExpr)) {
        yyerrorInfo("You can only have a variable, literal, or expression inside an expression!", tokenTable.table[leftExpr->tokenInfoIndex]);
    }
    newNode->as.expression->leftExpr = leftExpr;
    newNode->as.expression->rightExpr = rightExpr;

    return newNode;
}

AstNode* makePrintExpr(int tokenIndex, AstNode* expr) {
    AstNode* newNode = initNode(PRINT_EXPRESSION_NODE, tokenIndex);
    newNode->as.printExpr = malloc(sizeof(PrintExpr));
    newNode->as.printExpr->printExpr = expr;

    return newNode;
}

AstNode* makePrintListNode(int tokenInfoIndex, AstNode* firstItem) {
    AstNode* newNode = initNode(PRINT_LIST_NODE, tokenInfoIndex);
    newNode->as.printList = malloc(sizeof(PrintListNode));
    newNode->as.printList->firstItem = firstItem;

    return newNode;
}

AstNode* makeUnaryExprNode(int tokenInfoIndex, ExprOp op, AstNode* expr) {
    AstNode* newNode = initNode(UNARY_EXPR_NODE, tokenInfoIndex);
    newNode->as.unaryExpr = malloc(sizeof(UnaryExpr));
    newNode->as.unaryExpr->op = op;
    newNode->as.unaryExpr->expr = expr;
    newNode->isFloaty = expr->isFloaty;

    return newNode;
}

AstNode* makeFloatValueNode(int tokenInfoIndex, float value) {
    AstNode* newNode = initNode(VALUE_NODE, tokenInfoIndex);
    newNode->as.value = malloc(sizeof(Value));

    newNode->as.value->type = REAL;
    newNode->as.value->as.rVal = value;
    newNode->isFloaty = 1;

    return newNode;
}

AstNode* makeIntValueNode(int tokenInfoIndex, int value) {
    AstNode* newNode = initNode(VALUE_NODE, tokenInfoIndex);
    newNode->as.value = malloc(sizeof(Value));

    newNode->as.value->type = INT;
    newNode->as.value->as.iVal = value;
    newNode->isFloaty = 0;

    return newNode;
}

AstNode* makeStringNode(int tokenInfoIndex, char* string) {
    AstNode* newNode = initNode(STRING_VALUE_NODE, tokenInfoIndex);
    newNode->as.string = string;

    return newNode;
}

AstNode* makeNewlineNode(int tokenInfoIndex) {
    AstNode* newNode = initNode(NEWLINE_NODE, tokenInfoIndex);    
    return newNode;
}

AstNode* makeVariableNode(int tokenInfoIndex, char* name) {
    SymbolTableEntry symEntry = getSymbol(name);
    if (symEntry.address == 65535) {
        yyerrorInfo("Undeclared variable!", tokenTable.table[tokenInfoIndex]);
    }

    AstNode* newNode = initNode(VARIABLE_NODE, tokenInfoIndex);
    if (symEntry.isParameter == 0) {
        symEntry.address = symEntry.address - getParameterLength(functionSymbolTable->functionName);
    }
    newNode->as.variable = symEntry;
    newNode->isFloaty = symEntry.type == REAL;

    return newNode;
}

AstNode* makeExitNode(int tokenInfoIndex) {
    AstNode* newNode = initNode(EXIT_NODE, tokenInfoIndex);
    return newNode;
}

AstNode* makeArrayLoadNode(int tokenInfoIndex, char* name, AstNode* indexExpr) {
    SymbolTableEntry symEntry = getSymbol(name);
    if (symEntry.address == 65535) {
        yyerrorInfo("Undeclared variable!", tokenTable.table[tokenInfoIndex]);
    }

    AstNode* newNode = initNode(ARRAY_LOAD_NODE, tokenInfoIndex);
    newNode->as.arrayLoad = malloc(sizeof(ArrayLoad));
    newNode->isFloaty = symEntry.type == REAL;

    newNode->as.arrayLoad->symEntry = symEntry;
    newNode->as.arrayLoad->indexExpr = indexExpr;

    free(name);
    return newNode;
}




/*===========================================================================
/ Functions to free all the memory for an AstNode
/ ===========================================================================*/
static void freeVariableNode(AstNode* node);
static void freeExprNode(AstNode* node);
static void freeValueNode(AstNode* node);
static void freeUnaryExprNode(AstNode* node);
static void freeAssignmentStatement(AstNode* node);
static void freeArrayAssignmentStatement(AstNode* node);
static void freeArrayLoadNode(AstNode* node);
static void freeIfStmtNode(AstNode* node);
static void freeStringNode(AstNode* node);
static void freeNewlineNode(AstNode* node);
static void freePrintExprNode(AstNode* node);
static void freePrintListNode(AstNode* node);
static void freeWhileLoop(AstNode* node);
static void freeCountingLoop(AstNode* node);
static void freeReadNode(AstNode* node);
static void freeReadArrayNode(AstNode* node);
static void freeExitNode(AstNode* node);
static void freeFunctionNode(AstNode* node);
static void freeEndOfFunctionNode(AstNode* node);
static void freeFunctionCallNode(AstNode* node);
static void freeReturnNode(AstNode* node);

static void freeNode(AstNode* node) {
    switch(node->type) {
        case VALUE_NODE:
            freeValueNode(node);
            break;
        case EXPR_NODE:
            freeExprNode(node);
            break;
        case VARIABLE_NODE:
            freeVariableNode(node);
            break;
        case UNARY_EXPR_NODE:
            freeUnaryExprNode(node);
            break;
        case ASSIGN_STMT_NODE:
            freeAssignmentStatement(node);
            break;
        case ARRAY_ASSIGN_STMT_NODE:
            freeArrayAssignmentStatement(node);
            break;
        case ARRAY_LOAD_NODE:
            freeArrayLoadNode(node);
            break;
        case IF_STMT_NODE:
            freeIfStmtNode(node);
            break;
        case STRING_VALUE_NODE:
            freeStringNode(node);
            break;
        case NEWLINE_NODE:
            freeNewlineNode(node);
            break;
        case PRINT_EXPRESSION_NODE:
            freePrintExprNode(node);
            break;
        case PRINT_LIST_NODE:
            freePrintListNode(node);
            break;
        case WHILE_LOOP_NODE:
            freeWhileLoop(node);
            break;
        case COUNTING_LOOP_NODE:
            freeCountingLoop(node);
            break;
        case READ_NODE:
            freeReadNode(node);
            break;
        case READ_ARRAY_NODE:
            freeReadArrayNode(node);
            break;
        case EXIT_NODE:
            freeExitNode(node);
            break;
        case FUNCTION_NODE:
            freeFunctionNode(node);
            break;
        case END_OF_FUNCTION_NODE:
            freeEndOfFunctionNode(node);
            break;
        case FUNCTION_CALL_NODE:
            freeFunctionCallNode(node);
            break;
        case RETURN_NODE:
            freeReturnNode(node);
            break;
        default:
            printf("Do not know how to free memory for: %d", node->type);
            break;
    }
}


void freeAst() {
    if (astRootNode == NULL) {
        return;
    }

    AstNode* currentNode = astRootNode;
    while (currentNode != NULL) {
        AstNode* tmp = currentNode->next;
        freeNode(currentNode);
        currentNode = tmp;
    }
}

static void freeReturnNode(AstNode* node) {
    freeNode(node->as.returnNode->expr);
    free(node->as.returnNode);
    free(node);
    node = NULL;
}

static void freeFunctionNode(AstNode* node) {
    free(node);
    node = NULL;
}

static void freeFunctionCallNode(AstNode* node) {
    AstNode* current = node->as.functionCall->variableList;
    while (current != NULL) {
        AstNode* tmp = current->next;
        freeNode(current);
        current = tmp;
    }
    free(node->as.functionCall);

    free(node);
    node = NULL;
}

static void freeEndOfFunctionNode(AstNode* node) {
    free(node->as.endOfFunction);
    free(node);
    node = NULL;
}

static void freeExitNode(AstNode* node) {
    free(node);
    node = NULL;
}

static void freeReadNode(AstNode* node) {
    freeNode(node->as.readArrayNode->variable);
    free(node->as.readArrayNode);

    free(node);
    node = NULL;
}

static void freeReadArrayNode(AstNode* node) {
    freeNode(node->as.readArrayNode->variable);
    freeNode(node->as.readArrayNode->expr);

    free(node);
    node = NULL;
}

static void freePrintListNode(AstNode* node) {
    AstNode* current = node->as.printList->firstItem;
    while (current != NULL) {
        AstNode* tmp = current->next;
        freeNode(current);
        current = tmp;
    }

    free(node->as.printList);
    free(node);
    node = NULL;
}

static void freeWhileLoop(AstNode* node) {
    freeNode(node->as.whileLoop->conditionExpression);
    AstNode* current = node->as.whileLoop->whileBlock;
    while (current != NULL) {
        AstNode* tmp = current->next;
        freeNode(current);
        current = tmp;
    }

    free(node->as.whileLoop);
    free(node);
    node = NULL;
}

static void freeCountingLoop(AstNode* node) {
    freeNode(node->as.countingLoop->synthesizedIncrement);
    freeNode(node->as.countingLoop->synthesizedAssignment);
    freeNode(node->as.countingLoop->synthesizedEndValue);
    freeNode(node->as.countingLoop->synthesizedCheckExpr->as.expression->rightExpr);

    AstNode* current = node->as.countingLoop->body;
    while (current != NULL) {
        AstNode* tmp = current->next;
        freeNode(current);
        current = tmp;
    }

    free(node->as.countingLoop);
    free(node);
    node = NULL;
}

static void freeIfStmtNode(AstNode* node) {
    freeNode(node->as.ifStmt->conditionStatement);

    AstNode* current = node->as.ifStmt->ifBlock;
    while (current != NULL) {
        AstNode* tmp = current->next;
        freeNode(current);
        current = tmp;
    }
    
    current = node->as.ifStmt->elseBlock;
    while (current != NULL) {
        AstNode* tmp = current->next;
        freeNode(current);
        current = tmp;
    }
    free(node->as.ifStmt);

    free(node);
    node = NULL;
}

static void freeStringNode(AstNode* node) {
    free(node->as.string);
    free(node);
    node = NULL;
}

static void freeNewlineNode(AstNode* node) {
    free(node);
    node = NULL;
}

static void freeVariableNode(AstNode* node) {
    free(node);
    node = NULL;
}

static void freeArrayLoadNode(AstNode* node) {
    free(node->as.arrayLoad);

    free(node);
    node = NULL;
}

static void freeAssignmentStatement(AstNode* node) {
    freeNode(node->as.assignStmt->variableNode);
    freeNode(node->as.assignStmt->exprNode);

    free(node->as.assignStmt);
    free(node);
    node = NULL;
}

static void freeArrayAssignmentStatement(AstNode* node) {
    freeNode(node->as.arrayAssignStmt->variableNode);
    freeNode(node->as.arrayAssignStmt->indexExpr);
    freeNode(node->as.arrayAssignStmt->valExpr);

    free(node->as.arrayAssignStmt);
    free(node);
    node = NULL;
}

static void freeExprNode(AstNode* node) {
    Expr* expr = node->as.expression;
    freeNode(expr->leftExpr);
    freeNode(expr->rightExpr);

    free(expr);
    free(node);
}

static void freePrintExprNode(AstNode* node) {
    freeNode(node->as.printExpr->printExpr);
    free(node->as.printExpr);
    free(node);
    node = NULL;
}

static void freeUnaryExprNode(AstNode* node) {
    UnaryExpr* expr = node->as.unaryExpr;
    freeNode(expr->expr);
    free(node->as.unaryExpr);

    free(node);
    node = NULL;
}

static void freeValueNode(AstNode* node) {
    Value* value = node->as.value;

    free(value);
    free(node);
    node = NULL;
}