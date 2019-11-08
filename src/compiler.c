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
/* Helper methods to walk individual nodes of the AST and 
/* output GSTAL code.
/* ============================================================== */
static void walkNode(AstNode* node);
static void walkVariableNode(AstNode* node, int loadVal);

static void walkAssignmentNode(AstNode* node) {
    walkVariableNode(node->as.assignStmt->variableNode, 0);
    walkNode(node->as.assignStmt->exprNode);

    if (!node->as.assignStmt->exprNode->isFloaty && node->as.assignStmt->variableNode->isFloaty) {
        printf("ITF\n");
    } else if (node->as.assignStmt->exprNode->isFloaty && !node->as.assignStmt->variableNode->isFloaty) {
        printf("FTI\n");
    }

    printf("STO\n");
}

static void walkArrayAssignmentNode(AstNode* node) {
    walkVariableNode(node->as.arrayAssignStmt->variableNode, 0);
    walkNode(node->as.arrayAssignStmt->indexExpr);

    if (node->as.arrayAssignStmt->indexExpr->isFloaty) {
        printf("FTI\n");
    }

    printf("ADI\n");
    walkNode(node->as.arrayAssignStmt->valExpr);

    if (!node->as.arrayAssignStmt->valExpr->isFloaty && node->as.arrayAssignStmt->variableNode->isFloaty) {
        printf("ITF\n");
    } else if (node->as.arrayAssignStmt->valExpr->isFloaty && !node->as.arrayAssignStmt->variableNode->isFloaty) {
        printf("FTI\n");
    }

    printf("STO\n");
}

static void walkArrayLoadNode(AstNode* node) {
    printf("LAA %d\n", node->as.arrayLoad->symEntry.address);
    walkNode(node->as.arrayLoad->indexExpr);

    if (node->as.arrayAssignStmt->indexExpr->isFloaty) {
        printf("FTI\n");
    }

    printf("ADI\n");
    printf("LOD\n");
}

static void walkValueNode(AstNode* node) {
    if (node->isFloaty) {
        printf("LLF %f\n", node->as.value->as.rVal);
    } else {
        printf("LLI %d\n", node->as.value->as.iVal);
    }
}

static void walkVariableNode(AstNode* node, int loadVal) {
    printf("LAA %d\n", node->as.variable.address);
    if (loadVal)
        printf("LOD\n");
}

static void walkUnaryNode(AstNode* node) {
    int isFloatExpr = node->isFloaty;
    walkNode(node->as.unaryExpr->expr);
    if (!node->as.unaryExpr->expr->isFloaty && isFloatExpr) {
        printf("ITF\n");
    } else if (node->as.unaryExpr->expr->isFloaty && !isFloatExpr) {
        printf("FTI\n");
    }

    char* op;
    switch (node->as.unaryExpr->op) {
        case MINUS_OP:   op = isFloatExpr ? "NGF" : "NGI"; break;
        case NOT_OP:     op = isFloatExpr ? "LLF 0.0\nEQF" : "LLI 0\nEQI"; break;
    }
    printf("%s\n", op);
}

static void walkExprNode(AstNode* node) {
    int isFloatExpr = node->isFloaty;
    walkNode(node->as.expression->leftExpr);

    if (node->as.expression->leftExpr->isFloaty && !isFloatExpr && node->as.expression->op != MODULUS_OP) {
        printf("FTI\n");
    } else if (!node->as.expression->leftExpr->isFloaty && isFloatExpr && node->as.expression->op != MODULUS_OP) {
        printf("ITF\n");
    } else if (node->as.expression->leftExpr->isFloaty && node->as.expression->op == MODULUS_OP) {
        printf("FTI\n");
    }

    walkNode(node->as.expression->rightExpr);

    if (node->as.expression->rightExpr->isFloaty && !isFloatExpr && node->as.expression->op != MODULUS_OP) {
        printf("FTI\n");
    } else if (!node->as.expression->rightExpr->isFloaty && isFloatExpr && node->as.expression->op != MODULUS_OP) {
        printf("ITF\n");
    } else if (node->as.expression->rightExpr->isFloaty && node->as.expression->op == MODULUS_OP) {
        printf("FTI\n");
    }
    
    char* op;
    switch (node->as.expression->op) {
        case PLUS_OP:             op = isFloatExpr ? "ADF" : "ADI"; break;
        case MINUS_OP:            op = isFloatExpr ? "SBF" : "SBI"; break;
        case MULTIPLY_OP:         op = isFloatExpr ? "MLF" : "MLI"; break;
        case DIVIDE_OP:           op = isFloatExpr ? "DVF" : "DVI"; break;
        case MODULUS_OP:          {
            walkNode(node->as.expression->leftExpr);
            if (node->as.expression->leftExpr->isFloaty) {
                printf("FTI\n");
            }
            walkNode(node->as.expression->rightExpr);
            if (node->as.expression->rightExpr->isFloaty) {
                printf("FTI\n");
            }
            op = "DVI\nMLI\nSBI";
            node->isFloaty = 0;
            break;
        }
        case GRT_THAN_OP:         op = isFloatExpr ? "GTF" : "GTI"; break;
        case GRT_THAN_EQUAL_OP:   op = isFloatExpr ? "GEF" : "GTI"; break;
        case LESS_THAN_OP:        op = isFloatExpr ? "LTF" : "LTI"; break;
        case LESS_THAN_EQUAL_OP:  op = isFloatExpr ? "LEF" : "LEI"; break;
        case EQUAL_OP:            op = isFloatExpr ? "EQF" : "EQI"; break;
        case NOT_EQUAL_OP:        op = isFloatExpr ? "NEF" : "NEI"; break;
        default:                  yyerrorInfo("Error: Unknown binary operator!", tokenTable.table[node->tokenInfoIndex]); exit(-1);
    }
    printf("%s\n", op);
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
    printf("ISP %d\n", offset);

    AstNode* currentNode = astRootNode;
    while (currentNode != NULL) {
        walkNode(currentNode);
        currentNode = currentNode->next;
    }
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
    }
}