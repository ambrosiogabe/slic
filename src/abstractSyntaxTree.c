/* ==============================================================
/* This file contains the implementation for abstractSyntaxTree.h
/* See that file for more information about the functions and 
/* structs.
/* 
/* Author: Gabe Ambrosio
/* ============================================================== */

#include "compiler.h"
#include "abstractSyntaxTree.h"


/* ==============================================================
/* All the functions to create AstNodes
/* ============================================================== */
AstNode* makeAssignmentNode(int tokenInfoIndex, char* name, AstNode* expr) {
    if (!IS_TYPE_OF_EXPR(*expr)) {
        printf("Error: You can only assign an expression to a variable!");
        exit(-1);
    }

    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = ASSIGN_STMT_NODE;
    AstNode* varNode = makeVariableNode(tokenInfoIndex, name);
    newNode->as.assignStmt = malloc(sizeof(AssignStmt));
    newNode->as.assignStmt->variableNode = varNode;
    newNode->as.assignStmt->exprNode = expr;

    return newNode;
}

AstNode* makeArrayAssignmentNode(int tokenInfoIndex, char* name, AstNode* indexExpr, AstNode* valExpr) {
    if (!IS_TYPE_OF_EXPR(*indexExpr) || !IS_TYPE_OF_EXPR(*valExpr)) {
        printf("Error: You can only use expressions as indices in arrays, or as values to assign to arrays!");
        exit(-1);
    }

    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = ARRAY_ASSIGN_STMT_NODE;
    AstNode* varNode = makeVariableNode(tokenInfoIndex, name);
    newNode->as.arrayAssignStmt = malloc(sizeof(ArrayAssignStmt));
    newNode->as.arrayAssignStmt->variableNode = varNode;
    newNode->as.arrayAssignStmt->indexExpr = indexExpr;
    newNode->as.arrayAssignStmt->valExpr = valExpr;

    return newNode;
}

AstNode* makeExprNode(int tokenInfoIndex, ExprOp op, AstNode* leftExpr, AstNode* rightExpr) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = EXPR_NODE;
    newNode->as.expression = malloc(sizeof(Expr));
    newNode->as.expression->op = op;

    if (!IS_TYPE_OF_EXPR(*leftExpr) || !IS_TYPE_OF_EXPR(*rightExpr)) {
        printf("Error: You can only have a variable, value, or expression inside an expression!");
        exit(-1);
    }
    newNode->as.expression->leftExpr = leftExpr;
    newNode->as.expression->rightExpr = rightExpr;

    return newNode;
}

AstNode* makeUnaryExprNode(int tokenInfoIndex, ExprOp op, AstNode* expr) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = UNARY_EXPR_NODE;
    newNode->as.unaryExpr = malloc(sizeof(UnaryExpr));
    newNode->as.unaryExpr->op = op;
    newNode->as.unaryExpr->expr = expr;

    return newNode;
}

AstNode* makeFloatValueNode(int tokenInfoIndex, float value) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = VALUE_NODE;
    newNode->as.value = malloc(sizeof(Value));

    newNode->as.value->type = REAL;
    newNode->as.value->as.rVal = value;

    return newNode;
}

AstNode* makeIntValueNode(int tokenInfoIndex, int value) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = VALUE_NODE;
    newNode->as.value = malloc(sizeof(Value));

    newNode->as.value->type = INT;
    newNode->as.value->as.iVal = value;

    return newNode;
}

AstNode* makeVariableNode(int tokenInfoIndex, char* name) {
    SymbolTableEntry symEntry = getSymbol(name);
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = VARIABLE_NODE;
    newNode->as.variable = symEntry;

    return newNode;
}

AstNode* makeArrayLoadNode(int tokenInfoIndex, char* name, AstNode* indexExpr) {
    SymbolTableEntry symEntry = getSymbol(name);
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = ARRAY_LOAD_NODE;
    newNode->as.arrayLoad = malloc(sizeof(ArrayLoad));

    newNode->as.arrayLoad->symEntry = symEntry;
    newNode->as.arrayLoad->indexExpr = indexExpr;

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
        freeNode(currentNode);
        currentNode = currentNode->next;
    }
}

static void freeVariableNode(AstNode* node) {
    free(node);
}

static void freeArrayLoadNode(AstNode* node) {
    free(node->as.arrayLoad);

    free(node);
}

static void freeAssignmentStatement(AstNode* node) {
    freeNode(node->as.assignStmt->variableNode);
    freeNode(node->as.assignStmt->exprNode);

    free(node->as.assignStmt);
    free(node);
}

static void freeArrayAssignmentStatement(AstNode* node) {
    freeNode(node->as.arrayAssignStmt->variableNode);
    freeNode(node->as.arrayAssignStmt->indexExpr);
    freeNode(node->as.arrayAssignStmt->valExpr);

    free(node->as.arrayAssignStmt);
    free(node);
}

static void freeExprNode(AstNode* node) {
    Expr* expr = node->as.expression;
    freeNode(expr->leftExpr);
    freeNode(expr->rightExpr);

    free(expr);
}

static void freeUnaryExprNode(AstNode* node) {
    UnaryExpr* expr = node->as.unaryExpr;
    freeNode(expr->expr);

    free(node);
}

static void freeValueNode(AstNode* node) {
    Value* value = node->as.value;

    free(value);
    free(node);
}