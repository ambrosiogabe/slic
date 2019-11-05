%{
/*
 * ========================================================================
 * 
 * parser.y   --- The grammar for the SLIC language
 *                Turning DEBUG_PARSER to 1 will not print the most
 *                useful debugging information yet.
 * 
 * Programmer --- Gabe Ambrosio
 * Class      --- Compiler Construction
 * 
 * ========================================================================
 */

#include <stdio.h>

#ifdef PRETTY
	#include "../symbolTable.h"
	#include "../abstractSyntaxTree.h"
	#include "../compiler.h"
#else 
	#include "symbolTable.h"
	#include "abstractSyntaxTree.h"
	#include "compiler.h"
#endif

#define DEBUG_PARSER 0

int yyerror();
int yylex();

DataType currentType;
int address = 0;

%}

%define parse.error verbose

%union {
   char* sval;
   int ival;
   float rval;
   AstNode* node;
}

%token        MAIN_RW
%token        END_RW
%token        DATA_RW
%token        ALGORITHM_RW
%token        EXIT_RW
%token        READ_RW
%token        PRINT_RW
%token        REAL_RW
%token        INTEGER_RW
%token        WHILE_RW
%token        IF_RW
%token        ELSE_RW
%token        COUNTING_RW
%token        UPWARD_RW
%token        DOWNWARD_RW
%token        TO_RW

%token        BANG
%token        SEMICOLON
%token        COLON
%token        COMMA
%token        LEFT_BRACKET
%token        RIGHT_BRACKET
%token        LEFT_PAREN
%token        RIGHT_PAREN
%token        LEFT_BRACE 
%token        RIGHT_BRACE 

%token        MULTIPLY_TOKEN
%token        DIVIDE_TOKEN
%token        MINUS_TOKEN
%token        PLUS_TOKEN
%token        MODULUS_TOKEN
%token        LESS_THAN_TOKEN
%token        LESS_THAN_EQUAL_TOKEN
%token        GRT_THAN_TOKEN
%token        GRT_THAN_EQUAL_TOKEN
%token        EQUAL_TOKEN 
%token        NOT_EQUAL_TOKEN 
%token        AND_TOKEN 
%token        OR_TOKEN 
%token        NOT_TOKEN 
%token        ASSIGN_TOKEN 

%token <rval> REAL_NUMBER
%token <ival> INTEGER
%token <sval> VARIABLE
%token <sval> STRING 
%token        NEWLINE

%type <node> stmt;
%type <node> expr;
%type <node> assignStmt;
%type <node> boolTerm;
%type <node> binExpr;
%type <node> term;
%type <node> unary;
%type <node> factor;
%type <node> stmtList;

%%

program:   
    mainBlock
;

mainBlock:
	MAIN_RW SEMICOLON dataBlock algorithmBlock END_RW MAIN_RW SEMICOLON
;

dataBlock:
	  DATA_RW COLON declarationStmtList {if(DEBUG_PARSER) printf("DATA BLOCK\n");}
;

algorithmBlock:
	  ALGORITHM_RW COLON stmtList
;

declarationStmtList:
	  declarationStmtList dataType COLON declarationList SEMICOLON     {if(DEBUG_PARSER) printf("||Declaration List\n");}
	| dataType COLON declarationList SEMICOLON                         {if(DEBUG_PARSER) printf("||Declaration List\n");}
;

dataType:
	  REAL_RW     {currentType = REAL;}
	| INTEGER_RW  {currentType = INT;}
;

declarationList:
	  declarationList COMMA declarationItem
	| declarationItem
;

declarationItem:
	  VARIABLE                                  {
		  											if(DEBUG_PARSER) printf("%s ", $1);
													insertSymbolTable(currentType, $1, address, SCALAR, 1);
													address++;
												}
	| VARIABLE LEFT_BRACKET INTEGER RIGHT_BRACKET    
												{
													if(DEBUG_PARSER) printf("%s[] ", $1);
													insertSymbolTable(currentType, $1, address, ARRAY, $3);
													address += $3;
												}
;

stmtList:
	  stmtList stmt 
	  			{
					  AstNode* lastNode = astRootNode;
					  if (lastNode == NULL) {
						astRootNode = $1;
						lastNode = $1;
					  } else {
						  while (lastNode->next != NULL) {
							  lastNode = lastNode->next;
						  }
					  }

					lastNode->next = $2;
					$$ = $2;
					$2->next = NULL;
				}
	| stmt      
				{ 
					AstNode* lastNode = astRootNode;
					if (lastNode == NULL) {
						astRootNode = $1;
						lastNode = $1;
					} else {
						while (lastNode->next != NULL) {
							lastNode = lastNode->next;
						}
					}
					lastNode->next = $1;
					$$ = $1;
					$1->next = NULL;
				}
;

stmt: 
	assignStmt {$$ = $1;}
;

assignStmt:
	VARIABLE ASSIGN_TOKEN expr SEMICOLON { $$ = makeAssignmentNode($1, $3); } 
	| VARIABLE LEFT_BRACKET expr RIGHT_BRACKET ASSIGN_TOKEN expr SEMICOLON { $$ = makeArrayAssignmentNode($1, $3, $6);}
;

expr:
	  expr AND_TOKEN boolTerm  {$$ = makeExprNode(AND_OP, $1, $3);}
	| expr OR_TOKEN boolTerm   {$$ = makeExprNode(OR_OP, $1, $3);}
	| NOT_TOKEN boolTerm       {$$ = makeUnaryExprNode(NOT_OP, $2);}
	| boolTerm				   {$$ = $1;}
;

boolTerm:
	  boolTerm GRT_THAN_TOKEN binExpr        {$$ = makeExprNode(GRT_THAN_OP, $1, $3);}
	| boolTerm LESS_THAN_TOKEN binExpr       {$$ = makeExprNode(LESS_THAN_OP, $1, $3);}
	| boolTerm GRT_THAN_EQUAL_TOKEN binExpr  {$$ = makeExprNode(GRT_THAN_EQUAL_OP, $1, $3);}
	| boolTerm LESS_THAN_EQUAL_TOKEN binExpr {$$ = makeExprNode(LESS_THAN_EQUAL_OP, $1, $3);}
	| boolTerm EQUAL_TOKEN binExpr           {$$ = makeExprNode(EQUAL_OP, $1, $3);}
	| boolTerm NOT_EQUAL_TOKEN binExpr       {$$ = makeExprNode(NOT_EQUAL_OP, $1, $3);}
	| binExpr                                {$$ = $1;}
;

binExpr:
	  binExpr PLUS_TOKEN term   {$$ = makeExprNode(PLUS_OP, $1, $3);}
	| binExpr MINUS_TOKEN term  {$$ = makeExprNode(MINUS_OP, $1, $3);}
	| term                      {$$ = $1;}
;

term:
	  term MULTIPLY_TOKEN unary {$$ = makeExprNode(MULTIPLY_OP, $1, $3);}
	| term DIVIDE_TOKEN unary   {$$ = makeExprNode(DIVIDE_OP, $1, $3);}
	| term MODULUS_TOKEN unary  {$$ = makeExprNode(MODULUS_OP, $1, $3);}
	| unary                     {$$ = $1;}
;

unary:
	  MINUS_TOKEN factor {$$ = makeUnaryExprNode(MINUS_OP, $2);}
	| factor             {$$ = $1;}
;

factor: 
	  VARIABLE                                   {$$ = makeVariableNode($1);}
	| VARIABLE LEFT_BRACKET expr RIGHT_BRACKET   {$$ = makeArrayLoadNode($1, $3);}
	| REAL_NUMBER                                {$$ = makeFloatValueNode($1);}
	| INTEGER                                    {$$ = makeIntValueNode($1);}
	| LEFT_PAREN expr RIGHT_PAREN                {$$ = $2;}
;


%%

int yyerror(char const* s) {
	fprintf (stderr, "Error: %s\n", s);
 	return  0;
}
