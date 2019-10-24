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
#else 
	#include "symbolTable.h"
#endif

#define DEBUG_PARSER 0

int yyerror();
int yylex();

DataType currentType;
int address = 0;

%}

%define parse.error verbose

%union {
   char *sval;
   int ival;
   float rval;
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

%token        MULTIPLY_OP
%token        DIVIDE_OP
%token        MINUS_OP
%token        PLUS_OP
%token        MODULUS_OP
%token        LESS_THAN_OP
%token        LESS_THAN_EQUAL_OP
%token        GRT_THAN_OP
%token        GRT_THAN_EQUAL_OP
%token        EQUAL_OP 
%token        NOT_EQUAL_OP 
%token        AND_OP 
%token        OR_OP 
%token        NOT_OP 
%token        ASSIGN_OP 

%token <rval> REAL_NUMBER
%token <ival> INTEGER
%token <sval> VARIABLE
%token <sval> STRING 
%token        NEWLINE

%%

program:   
    mainBlock
;

mainBlock:
      MAIN_RW SEMICOLON dataBlock
	| MAIN_RW SEMICOLON dataBlock END_RW MAIN_RW SEMICOLON
;

dataBlock:
	  DATA_RW COLON declarationStmtList {if(DEBUG_PARSER) printf("DATA BLOCK\n");}
;

declarationStmtList:
	  declarationStmtList dataType COLON declarationList SEMICOLON     {if(DEBUG_PARSER) printf("||Declaration List\n");}
	| dataType COLON declarationList SEMICOLON                         {if(DEBUG_PARSER) printf("||Declaration List\n");}
;

dataType:
	  REAL_RW {currentType = REAL;}
	| INTEGER_RW {currentType = INT;}
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
%%

int yyerror(char const* s) {
	fprintf (stderr, "Error: %s\n", s);
 	return  0;
}
