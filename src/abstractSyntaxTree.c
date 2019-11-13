/* ==============================================================
/* This file contains the implementation for abstractSyntaxTree.h
/* See that file for more information about the functions and 
/* structs.
/* 
/* Author: Gabe Ambrosio
/* ============================================================== */

#include "compiler.h"
#include "common.h"
#include "abstractSyntaxTree.h"


/* ==============================================================
/* All the functions to create AstNodes
/* ============================================================== */
AstNode* makeWhileLoopNode(int tokenInfoIndex, AstNode* conditionExpr, AstNode* whileBlock) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->type = WHILE_LOOP_NODE;
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->as.whileLoop = malloc(sizeof(WhileLoop));
    newNode->as.whileLoop->conditionExpression = conditionExpr;
    newNode->as.whileLoop->whileBlock = whileBlock;

    return newNode;
}

AstNode* makeIfStatement(AstNode* ifBlock, AstNode* ifCondition, AstNode* elseBlock) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->type = IF_STMT_NODE;
    newNode->as.ifStmt = malloc(sizeof(IfStmt));
    newNode->as.ifStmt->ifBlock = ifBlock;
    newNode->as.ifStmt->conditionStatement = ifCondition;
    newNode->as.ifStmt->elseBlock = elseBlock;

    return newNode;
}

AstNode* makeAssignmentNode(int tokenInfoIndex, char* name, AstNode* expr) {
    if (!IS_TYPE_OF_EXPR(*expr)) {
        yyerrorInfo("You can only assign an expression to a variable!", tokenTable.table[expr->tokenInfoIndex]);
        exit(-1);
    }

    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = ASSIGN_STMT_NODE;
    AstNode* varNode = makeVariableNode(tokenInfoIndex, name);
    newNode->as.assignStmt = malloc(sizeof(AssignStmt));
    newNode->as.assignStmt->variableNode = varNode;
    newNode->as.assignStmt->exprNode = expr;
    newNode->isFloaty = newNode->as.assignStmt->variableNode->as.variable.type == REAL;

    return newNode;
}

AstNode* makeArrayAssignmentNode(int tokenInfoIndex, char* name, AstNode* indexExpr, AstNode* valExpr) {
    if (!IS_TYPE_OF_EXPR(*indexExpr)) {
        yyerrorInfo("You can only use expressions as indices in arrays!", tokenTable.table[indexExpr->tokenInfoIndex]);
        exit(-1);
    }
    if (!IS_TYPE_OF_EXPR(*valExpr)) {
        yyerrorInfo("You can only assign expressions to variables!", tokenTable.table[valExpr->tokenInfoIndex]);
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
    newNode->isFloaty = newNode->as.arrayAssignStmt->variableNode->as.variable.type == REAL;

    return newNode;
}

AstNode* makeExprNode(int tokenInfoIndex, ExprOp op, AstNode* leftExpr, AstNode* rightExpr) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = EXPR_NODE;
    newNode->as.expression = malloc(sizeof(Expr));
    newNode->as.expression->op = op;
    newNode->isFloaty = leftExpr->isFloaty | rightExpr->isFloaty;

    if (!IS_TYPE_OF_EXPR(*leftExpr) || !IS_TYPE_OF_EXPR(*rightExpr)) {
        yyerrorInfo("You can only have a variable, literal, or expression inside an expression!", tokenTable.table[leftExpr->tokenInfoIndex]);
        exit(-1);
    }
    newNode->as.expression->leftExpr = leftExpr;
    newNode->as.expression->rightExpr = rightExpr;

    return newNode;
}

AstNode* makePrintExpr(int tokenIndex, AstNode* expr) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->type = PRINT_EXPRESSION_NODE;
    newNode->as.printExpr = malloc(sizeof(PrintExpr));
    newNode->as.printExpr->printExpr = expr;

    return newNode;
}

AstNode* makePrintListNode(int tokenInfoIndex, AstNode* firstItem) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->type = PRINT_LIST_NODE;
    newNode->as.printList = malloc(sizeof(PrintListNode));
    newNode->as.printList->firstItem = firstItem;

    return newNode;
}

AstNode* makeUnaryExprNode(int tokenInfoIndex, ExprOp op, AstNode* expr) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = UNARY_EXPR_NODE;
    newNode->as.unaryExpr = malloc(sizeof(UnaryExpr));
    newNode->as.unaryExpr->op = op;
    newNode->as.unaryExpr->expr = expr;
    newNode->isFloaty = expr->isFloaty;

    return newNode;
}

AstNode* makeFloatValueNode(int tokenInfoIndex, float value) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = VALUE_NODE;
    newNode->as.value = malloc(sizeof(Value));

    newNode->as.value->type = REAL;
    newNode->as.value->as.rVal = value;
    newNode->isFloaty = 1;

    return newNode;
}

AstNode* makeIntValueNode(int tokenInfoIndex, int value) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = VALUE_NODE;
    newNode->as.value = malloc(sizeof(Value));

    newNode->as.value->type = INT;
    newNode->as.value->as.iVal = value;
    newNode->isFloaty = 0;

    return newNode;
}

AstNode* makeStringNode(int tokenInfoIndex, char* string) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = STRING_VALUE_NODE;
    newNode->as.string = string;

    return newNode;
}

AstNode* makeNewlineNode(int tokenInfoIndex) {
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = NEWLINE_NODE;
    
    return newNode;
}

AstNode* makeVariableNode(int tokenInfoIndex, char* name) {
    SymbolTableEntry symEntry = getSymbol(name);
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = VARIABLE_NODE;
    newNode->as.variable = symEntry;
    newNode->isFloaty = symEntry.type == REAL;

    return newNode;
}

AstNode* makeArrayLoadNode(int tokenInfoIndex, char* name, AstNode* indexExpr) {
    SymbolTableEntry symEntry = getSymbol(name);
    AstNode* newNode = malloc(sizeof(AstNode));
    newNode->tokenInfoIndex = tokenInfoIndex;
    newNode->type = ARRAY_LOAD_NODE;
    newNode->as.arrayLoad = malloc(sizeof(ArrayLoad));
    newNode->isFloaty = symEntry.type == REAL;

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
static void freeIfStmtNode(AstNode* node);
static void freeStringNode(AstNode* node);
static void freeNewlineNode(AstNode* node);
static void freePrintExprNode(AstNode* node);
static void freePrintListNode(AstNode* node);
static void freeWhileLoop(AstNode* node);

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
    freeNode(node->as.whileLoop->whileBlock);

    free(node->as.whileLoop);
    free(node);
    node = NULL;
}

static void freeIfStmtNode(AstNode* node) {
    freeNode(node->as.ifStmt->conditionStatement);
    freeNode(node->as.ifStmt->ifBlock);
    freeNode(node->as.ifStmt->elseBlock);
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
}

static void freePrintExprNode(AstNode* node) {
    freeNode(node->as.printExpr->printExpr);
    free(node);
    node = NULL;
}

static void freeUnaryExprNode(AstNode* node) {
    UnaryExpr* expr = node->as.unaryExpr;
    freeNode(expr->expr);

    free(node);
    node = NULL;
}

static void freeValueNode(AstNode* node) {
    Value* value = node->as.value;

    free(value);
    free(node);
    node = NULL;
}