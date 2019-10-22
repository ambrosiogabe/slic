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

#define DEBUG_PARSER 0

int yyerror();
int yylex();

%}

%define parse.error verbose

%union {
   char *sval;
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

%token <sval> REAL_NUMBER
%token <sval> INTEGER
%token <sval> VARIABLE
%token <sval> STRING 
%token        NEWLINE

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
	  ALGORITHM_RW COLON stmtList {if(DEBUG_PARSER) printf("ALGORITHM BLOCK\n");}
;

declarationStmtList:
	  declarationStmtList dataType COLON declarationList SEMICOLON     {if(DEBUG_PARSER) printf("||Declaration List\n");}
	| dataType COLON declarationList SEMICOLON                         {if(DEBUG_PARSER) printf("||Declaration List\n");}
;

dataType:
	  REAL_RW 
	| INTEGER_RW
;

declarationList:
	  declarationList COMMA declarationItem
	| declarationItem
;

declarationItem:
	  VARIABLE                                    {if(DEBUG_PARSER) printf("%s ", $1);}
	| VARIABLE LEFT_BRACKET INTEGER RIGHT_BRACKET    {if(DEBUG_PARSER) printf("%s[] ", $1);}
;

stmtList:
	  stmtList stmt 
	| stmt
;

stmt: 
	  printStmt 
	| readStmt 
	| assignStmt 
	| exitStmt 
	| whileLoop 
	| forLoop 
	| ifStmt
;

ifStmt:
	  beginIfStmt stmtList elseBlock
	| beginIfStmt stmtList endIfStmt
;

beginIfStmt:
	IF_RW expr SEMICOLON {if(DEBUG_PARSER) printf("||Begin if statement\n");}
;

beginElseBlock:
	ELSE_RW SEMICOLON {if(DEBUG_PARSER) printf("||Begin else block\n");}
;

elseBlock:
	beginElseBlock stmtList endIfStmt
;

endIfStmt:
	END_RW IF_RW SEMICOLON {if(DEBUG_PARSER) printf("||End if statement\n");}
;

forLoop:
	beginForLoop stmtList endForLoop
;

beginForLoop:
	  COUNTING_RW VARIABLE UPWARD_RW expr TO_RW expr SEMICOLON   {if(DEBUG_PARSER) printf("||for loop upward\n");}
	| COUNTING_RW VARIABLE DOWNWARD_RW expr TO_RW expr SEMICOLON {if(DEBUG_PARSER) printf("||for loop downward\n");}
;

endForLoop:
	END_RW COUNTING_RW SEMICOLON  {if(DEBUG_PARSER) printf("||End for loop\n");}
;

whileLoop:
	whileBeginStmt stmtList whileEndStmt
;

whileBeginStmt:
	WHILE_RW expr SEMICOLON {if(DEBUG_PARSER) printf("||Begin while loop\n");}
;

whileEndStmt:
	END_RW WHILE_RW SEMICOLON {if(DEBUG_PARSER) printf("||End while loop\n");}
;

exitStmt:
	EXIT_RW SEMICOLON
;

readStmt:
	  READ_RW VARIABLE SEMICOLON {if(DEBUG_PARSER) printf("%s read\n", $2);}
	| READ_RW VARIABLE LEFT_BRACKET expr {if(DEBUG_PARSER) printf("%s[", $2);} RIGHT_BRACKET SEMICOLON {if(DEBUG_PARSER) printf("] read\n");}
;

printStmt:
	PRINT_RW printList SEMICOLON {if(DEBUG_PARSER) printf("||Print statement\n");}
;

printList:
	  printList COMMA printItem  
	| printItem 
;

printItem:
	  BANG   {if(DEBUG_PARSER) printf("! ");}
	| expr 		
	| STRING {if(DEBUG_PARSER) printf("%s ", $1);}
;

assignStmt:
	VARIABLE ASSIGN_OP expr SEMICOLON {if(DEBUG_PARSER) printf("%s :=\n", $1);} 
	| VARIABLE LEFT_BRACKET {if(DEBUG_PARSER) printf("%s[", $1);} expr RIGHT_BRACKET ASSIGN_OP expr SEMICOLON {if(DEBUG_PARSER) printf("] :=\n");}
;

expr:
	  expr AND_OP boolTerm  {if(DEBUG_PARSER) printf("& ");}
	| expr OR_OP boolTerm   {if(DEBUG_PARSER) printf("| ");}
	| expr NOT_OP boolTerm  {if(DEBUG_PARSER) printf("! ");}
	| boolTerm
;

boolTerm:
	  boolTerm GRT_THAN_OP binExpr        {if(DEBUG_PARSER) printf("> ");}
	| boolTerm LESS_THAN_OP binExpr       {if(DEBUG_PARSER) printf("< ");}
	| boolTerm GRT_THAN_EQUAL_OP binExpr  {if(DEBUG_PARSER) printf(">= ");}
	| boolTerm LESS_THAN_EQUAL_OP binExpr {if(DEBUG_PARSER) printf("<= ");}
	| boolTerm EQUAL_OP binExpr           {if(DEBUG_PARSER) printf("= ");}
	| boolTerm NOT_EQUAL_OP binExpr       {if(DEBUG_PARSER) printf("<> ");}
	| binExpr
;

binExpr:
	  binExpr PLUS_OP term   {if(DEBUG_PARSER) printf("+ ");}
	| binExpr MINUS_OP term  {if(DEBUG_PARSER) printf("- ");}
	| term 
;

term:
	  term MULTIPLY_OP unary {if(DEBUG_PARSER) printf("* ");}
	| term DIVIDE_OP unary   {if(DEBUG_PARSER) printf("/ ");}
	| term MODULUS_OP unary  {if(DEBUG_PARSER) printf("%% ");}
	| unary 
;

unary:
	  MINUS_OP factor {if(DEBUG_PARSER) printf("(-) ");}
	| factor
;

factor: 
	  VARIABLE     {if(DEBUG_PARSER) printf("%s ", $1);}
	| REAL_NUMBER  {if(DEBUG_PARSER) printf("%s ", $1);}
	| INTEGER      {if(DEBUG_PARSER) printf("%s ", $1);}
	| LEFT_PAREN expr RIGHT_PAREN 
;

%%

int yyerror(char const* s) {
	fprintf (stderr, "Error: %s\n", s);
 	return  0;
}
