#ifndef SLIC_AST_H
#define SLIC_AST_H
/* ===========================================================
/* This file contains all the logic for creating an abstract
/* syntax tree, and inserting elements into the tree.
/* 
/* Implementation: abstractSyntaxTree.c
/* Author: Gabe Ambrosio
/* =========================================================== */


#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"

typedef struct AstNode AstNode;

/* ===========================================================================
/* The NodeType is an enum that is used to determine what subclass a AstNode
/* is. E.g is it an ARRAY_NODE, ASSIGNMENT_STMT_NODE, etc.
/* ===========================================================================*/
typedef enum {
    ASSIGN_STMT_NODE,
    ARRAY_ASSIGN_STMT_NODE,
    EXPR_NODE,
    UNARY_EXPR_NODE,
    VALUE_NODE,
    VARIABLE_NODE,
    ARRAY_LOAD_NODE
} NodeType;

/* ===========================================================================
/* The ExprOp is a helper enum that is used to determine which operator is
/* being used in a binary or unary expression.
/* ===========================================================================*/
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

/* ===========================================================================
/* The AssignStmt node handles all the assignment statements that are
/* not arrays.
/*
/* @AstNode* variableNode: The variable being assigned to
/* @AstNode* exprNode: The expression that is being assigned
/* ===========================================================================*/
typedef struct {
    AstNode* variableNode;
    AstNode* exprNode;
} AssignStmt;

/* ===========================================================================
/* The ArrayAssignmentStmt handles assignment statements for an array
/* variable. This includes the variable node, index expression, and
/* value expression.
/*          a[i + 2] := 23 * b;
/*      var-^  ^   valExpr-^
/*   indexExpr-|
/*
/* @AstNode* variableNode: The variable
/* @AstNode* indexExpr: The expression inside the brackets
/* @AstNode* valExpr: The expression being evaluated on the righthand
/*                    side of the assignment operator.
/* ===========================================================================*/
typedef struct {
    AstNode* variableNode;
    AstNode* indexExpr;
    AstNode* valExpr;
} ArrayAssignStmt;

/* ===========================================================================
/* The Expr node is a node that contains logic for a binary expression,
/* and an operator that is acting on the expression.
/*
/* @ExprOp op: The operator (e.g MINUS_OP, PLUS_OP, MULTIPLY_OP, etc)
/* @AstNode* leftExpr: The lefthand side of the operator
/* @AstNode* rightExpr: The righthand side of the operator
/* ===========================================================================*/
typedef struct {
    ExprOp op;
    AstNode* leftExpr;
    AstNode* rightExpr;
} Expr;

/* ===========================================================================
/* The UnaryExpr is a node that contains the operator and the expression
/* that the unary operator is acting on.
/*
/* @ExprOp op: The operator (e.g MINUS_OP, NOT_OP)
/* @AstNode* expr: The expression branch
/* ===========================================================================*/
typedef struct {
    ExprOp op;
    AstNode* expr;
} UnaryExpr;

/* ===========================================================================
/* The Value is a node that contains the value of a literal constant.
/*
/* @DataType type: The type (Real or Integer)
/* @union as: The value of the constant
/* ===========================================================================*/
typedef struct {
    DataType type;
    union {
        float rVal;
        int iVal;
    } as;
} Value;

/* ===========================================================================
/* The ArrayLoad node contains the branches for loading array variables
/* in the middle of an expression.
/*
/* @SymbolTableEntry symEntry: The variables entry in the symbol table
/* @AstNode* indexExpr: The pointer to the expression for the index
/*       e.g a[i + 2] where 'i + 2' is the index expression
/* ===========================================================================*/
typedef struct {
    SymbolTableEntry symEntry;
    AstNode* indexExpr;
} ArrayLoad;

/* ===========================================================================
/* The AstNode is the "parent" class of all other node subclasses. The node
/* subclasses are denoted by the union and the type.
/*
/* @NodeType type: The type of node this node is (ArrayLoad, Value, etc)
/* @union as: The pointer to the node
/* @AstNode* next: the pointer to the next statement 
/* ===========================================================================*/
struct AstNode {
    NodeType type;
    int tokenInfoIndex;
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

/* ===========================================================================
/* Helper macros to determine whether a variable is an expression or value
/* etc.
/* ===========================================================================*/
#define IS_VAL_NODE(value)         ((value).type ==  VALUE_NODE)
#define IS_VARIABLE_NODE(value)    ((value).type == VARIABLE_NODE)
#define IS_UNARY_EXPR_NODE(value)  ((value).type == UNARY_EXPR_NODE)
#define IS_EXPR_NODE(value)        ((value).type == EXPR_NODE || IS_UNARY_EXPR_NODE(value))
#define IS_ARRAY_LOAD_NODE(value)  ((value).type == ARRAY_LOAD_NODE)
#define IS_TYPE_OF_EXPR(value)     ((value).type == EXPR_NODE || IS_VAL_NODE(value) || IS_VARIABLE_NODE(value) || IS_UNARY_EXPR_NODE(value) || IS_ARRAY_LOAD_NODE(value))

/* ===========================================================================
/* Helper functions to make specific nodes for the abstract syntax tree.
/* The functions are split for each different type of node.
/* ===========================================================================*/
AstNode* makeAssignmentNode(int tokenInfoIndex, char* name, AstNode* expr);
AstNode* makeArrayAssignmentNode(int tokenInfoIndex, char* name, AstNode* indexExpr, AstNode* valExpr);
AstNode* makeExprNode(int tokenInfoIndex, ExprOp op, AstNode* leftExpr, AstNode* rightExpr);
AstNode* makeUnaryExprNode(int tokenInfoIndex, ExprOp op, AstNode* expr);
AstNode* makeFloatValueNode(int tokenInfoIndex, float value);
AstNode* makeIntValueNode(int tokenInfoIndex, int value);
AstNode* makeVariableNode(int tokenInfoIndex, char* name);
AstNode* makeArrayLoadNode(int tokenInfoIndex, char* name, AstNode* indexExpr);

/* ===========================================================================
/* A function to free all the memory used for the AST.
/* ===========================================================================*/
void freeAst();

#endif