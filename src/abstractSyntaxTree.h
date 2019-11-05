#ifndef SLIC_AST_H
#define SLIC_AST_H

#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"

typedef struct AstNode AstNode;

typedef enum {
    ASSIGN_STMT_NODE,
    ARRAY_ASSIGN_STMT_NODE,
    EXPR_NODE,
    UNARY_EXPR_NODE,
    VALUE_NODE,
    VARIABLE_NODE,
    ARRAY_LOAD_NODE
} NodeType;

typedef enum {
    PLUS_OP,
    MINUS_OP,
    MULTIPLY_OP,
    DIVIDE_OP,
    MODULUS_OP,
    AND_OP,
    OR_OP,
    NOT_OP,
    GRT_THAN_OP,
    LESS_THAN_OP,
    GRT_THAN_EQUAL_OP,
    LESS_THAN_EQUAL_OP,
    EQUAL_OP,
    NOT_EQUAL_OP
} ExprOp;

typedef struct {
    AstNode* variableNode;
    AstNode* exprNode;
} AssignStmt;

typedef struct {
    AstNode* variableNode;
    AstNode* indexExpr;
    AstNode* valExpr;
} ArrayAssignStmt;

typedef struct {
    ExprOp op;
    AstNode* leftExpr;
    AstNode* rightExpr;
} Expr;

typedef struct {
    ExprOp op;
    AstNode* expr;
} UnaryExpr;

typedef struct {
    DataType type;
    union {
        float rVal;
        int iVal;
    } as;
} Value;

typedef struct {
    SymbolTableEntry symEntry;
    AstNode* indexExpr;
} ArrayLoad;

struct AstNode {
    NodeType type;
    union {
        AssignStmt* assignStmt;
        ArrayAssignStmt* arrayAssignStmt;
        Expr* expression;
        UnaryExpr* unaryExpr;
        Value* value;
        ArrayLoad* arrayLoad;
        SymbolTableEntry variable;
    } as; 
    AstNode* next;
};

#define IS_VAL_NODE(value)         ((value).type ==  VALUE_NODE)
#define IS_VARIABLE_NODE(value)    ((value).type == VARIABLE_NODE)
#define IS_UNARY_EXPR_NODE(value)  ((value).type == UNARY_EXPR_NODE)
#define IS_EXPR_NODE(value)        ((value).type == EXPR_NODE || IS_UNARY_EXPR_NODE(value))
#define IS_ARRAY_LOAD_NODE(value)  ((value).type == ARRAY_LOAD_NODE)
#define IS_TYPE_OF_EXPR(value)     ((value).type == EXPR_NODE || IS_VAL_NODE(value) || IS_VARIABLE_NODE(value) || IS_UNARY_EXPR_NODE(value) || IS_ARRAY_LOAD_NODE(value))

AstNode* makeAssignmentNode(char* name, AstNode* expr);
AstNode* makeArrayAssignmentNode(char* name, AstNode* indexExpr, AstNode* valExpr);
AstNode* makeExprNode(ExprOp op, AstNode* leftExpr, AstNode* rightExpr);
AstNode* makeUnaryExprNode(ExprOp op, AstNode* expr);
AstNode* makeFloatValueNode(float value);
AstNode* makeIntValueNode(int value);
AstNode* makeVariableNode(char* name);
AstNode* makeArrayLoadNode(char* name, AstNode* indexExpr);
void freeAst();

#endif