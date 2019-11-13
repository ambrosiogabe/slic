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
	#include "../common.h"
#else 
	#include "symbolTable.h"
	#include "abstractSyntaxTree.h"
	#include "compiler.h"
	#include "common.h"
#endif

#define DEBUG_PARSER 0

int yyerror();
int yyerrorInfo(const char* s, TokenInformation token);
int yylex();

DataType currentType;
int address = 0;
static int previousTokenIndex = 0;

%}

%define parse.error verbose

%union {
   AstNode* node;
   TokenHelper helper;
}

%token <helper> MAIN_RW
%token <helper> END_RW
%token <helper> DATA_RW
%token <helper> ALGORITHM_RW
%token <helper> EXIT_RW
%token <helper> READ_RW
%token <helper> PRINT_RW
%token <helper> REAL_RW
%token <helper> INTEGER_RW
%token <helper> WHILE_RW
%token <helper> IF_RW
%token <helper> ELSE_RW
%token <helper> COUNTING_RW
%token <helper> UPWARD_RW
%token <helper> DOWNWARD_RW
%token <helper> TO_RW

%token <helper> BANG
%token <helper> SEMICOLON
%token <helper> COLON
%token <helper> COMMA
%token <helper> LEFT_BRACKET
%token <helper> RIGHT_BRACKET
%token <helper> LEFT_PAREN
%token <helper> RIGHT_PAREN
%token <helper> LEFT_BRACE 
%token <helper> RIGHT_BRACE 

%token <helper> MULTIPLY_TOKEN
%token <helper> DIVIDE_TOKEN
%token <helper> MINUS_TOKEN
%token <helper> PLUS_TOKEN
%token <helper> MODULUS_TOKEN
%token <helper> LESS_THAN_TOKEN
%token <helper> LESS_THAN_EQUAL_TOKEN
%token <helper> GRT_THAN_TOKEN
%token <helper> GRT_THAN_EQUAL_TOKEN
%token <helper> EQUAL_TOKEN 
%token <helper> NOT_EQUAL_TOKEN 
%token <helper> AND_TOKEN 
%token <helper> OR_TOKEN 
%token <helper> NOT_TOKEN 
%token <helper> ASSIGN_TOKEN 

%token <helper> REAL_NUMBER
%token <helper> INTEGER
%token <helper> VARIABLE
%token <helper> STRING 
%token          NEWLINE

%type <node> stmt;
%type <node> stmtList;
%type <node> blockStmtList;
%type <node> expr;
%type <node> assignStmt;
%type <node> boolTerm;
%type <node> binExpr;
%type <node> term;
%type <node> unary;
%type <node> factor;
%type <node> printItem;
%type <node> printList;
%type <node> printExpr;
%type <node> ifStmt;
%type <node> elseBlock;
%type <node> whileLoop;

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
													if (getSymbol($1.sval).address != 65535) {														
														yyerrorInfo("Duplicate variable declaration.", tokenTable.table[$1.tokenIndex]);
														YYERROR;
													}
													insertSymbolTable(currentType, $1.sval, address, SCALAR, 1);
													address++;
												}
	| VARIABLE LEFT_BRACKET INTEGER RIGHT_BRACKET    
												{
													if(DEBUG_PARSER) printf("%s[] ", $1);
													if (getSymbol($1.sval).address != 65535) {
														yyerrorInfo("Duplicate variable declaration.", tokenTable.table[$1.tokenIndex]);
														YYERROR;
													}
													insertSymbolTable(currentType, $1.sval, address, ARRAY, $3.ival);
													address += $3.ival;
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

blockStmtList: 
	  stmt blockStmtList 	{ 
		  						$$ = $1; 
								$$->next = $2;
							}
	| stmt               	{ 
								$$ = $1; 
								$$->next = NULL;
							}
;

stmt: 
	  assignStmt                   { $$ = $1; }
	| ifStmt                       { $$ = $1; }
	| PRINT_RW printList SEMICOLON { $$ = makePrintListNode($2->tokenInfoIndex, $2); }
	| whileLoop                    { $$ = $1; }
;

printList:
	  printItem COMMA printList { $$ = $1; $$->next = $3; }
	| printItem                 { $$ = $1; $$->next = NULL; }
;

printItem:
	  printExpr { $$ = $1; }
	| STRING    { $$ = makeStringNode($1.tokenIndex, $1.sval); }
	| BANG      { $$ = makeNewlineNode($1.tokenIndex); }
;

printExpr:
	expr { $$ = makePrintExpr($1->tokenInfoIndex, $1); }
;

whileLoop:
	WHILE_RW expr SEMICOLON blockStmtList END_RW WHILE_RW SEMICOLON { $$ = makeWhileLoopNode($1.tokenIndex, $2, $4); }
;

ifStmt:
	  IF_RW expr SEMICOLON blockStmtList elseBlock END_RW IF_RW SEMICOLON { $$ = makeIfStatement($4, $2, $5); }
	| IF_RW expr SEMICOLON blockStmtList END_RW IF_RW SEMICOLON           { $$ = makeIfStatement($4, $2, NULL); }
;

elseBlock:
	ELSE_RW SEMICOLON blockStmtList { $$ = $3; }
;

assignStmt:
	VARIABLE ASSIGN_TOKEN expr SEMICOLON 	{ 
												if (getSymbol($1.sval).address == 65535) {
													yyerrorInfo("Unknown variable.", tokenTable.table[$1.tokenIndex]);
													YYERROR;
												}
												$$ = makeAssignmentNode($1.tokenIndex, $1.sval, $3); 
											} 
	| VARIABLE LEFT_BRACKET expr RIGHT_BRACKET ASSIGN_TOKEN expr SEMICOLON 
											{ 
												if (getSymbol($1.sval).address == 65535) {
													yyerrorInfo("Unknown variable.", tokenTable.table[$1.tokenIndex]);
													YYERROR;
												}
												$$ = makeArrayAssignmentNode($1.tokenIndex, $1.sval, $3, $6);
											}
;

expr:
	  expr AND_TOKEN boolTerm  {$$ = makeExprNode($2.tokenIndex, AND_OP, $1, $3);}
	| expr OR_TOKEN boolTerm   {$$ = makeExprNode($2.tokenIndex, OR_OP, $1, $3);}
	| NOT_TOKEN boolTerm       {$$ = makeUnaryExprNode($1.tokenIndex, NOT_OP, $2);}
	| boolTerm				   {$$ = $1;}
;

boolTerm:
	  boolTerm GRT_THAN_TOKEN binExpr        {$$ = makeExprNode($2.tokenIndex, GRT_THAN_OP, $1, $3);}
	| boolTerm LESS_THAN_TOKEN binExpr       {$$ = makeExprNode($2.tokenIndex, LESS_THAN_OP, $1, $3);}
	| boolTerm GRT_THAN_EQUAL_TOKEN binExpr  {$$ = makeExprNode($2.tokenIndex, GRT_THAN_EQUAL_OP, $1, $3);}
	| boolTerm LESS_THAN_EQUAL_TOKEN binExpr {$$ = makeExprNode($2.tokenIndex, LESS_THAN_EQUAL_OP, $1, $3);}
	| boolTerm EQUAL_TOKEN binExpr           {$$ = makeExprNode($2.tokenIndex, EQUAL_OP, $1, $3);}
	| boolTerm NOT_EQUAL_TOKEN binExpr       {$$ = makeExprNode($2.tokenIndex, NOT_EQUAL_OP, $1, $3);}
	| binExpr                                {$$ = $1;}
;

binExpr:
	  binExpr PLUS_TOKEN term   {$$ = makeExprNode($2.tokenIndex, PLUS_OP, $1, $3);}
	| binExpr MINUS_TOKEN term  {$$ = makeExprNode($2.tokenIndex, MINUS_OP, $1, $3);}
	| term                      {$$ = $1;}
;

term:
	  term MULTIPLY_TOKEN unary {$$ = makeExprNode($2.tokenIndex, MULTIPLY_OP, $1, $3);}
	| term DIVIDE_TOKEN unary   {$$ = makeExprNode($2.tokenIndex, DIVIDE_OP, $1, $3);}
	| term MODULUS_TOKEN unary  {$$ = makeExprNode($2.tokenIndex, MODULUS_OP, $1, $3);}
	| unary                     {$$ = $1;}
;

unary:
	  MINUS_TOKEN factor {$$ = makeUnaryExprNode($1.tokenIndex, MINUS_OP, $2);}
	| factor             {$$ = $1;}
;

factor: 
	  VARIABLE  {
		  			if (getSymbol($1.sval).address == 65535) {
						  yyerror("Undeclared variable.");
						  YYERROR;
					}
					$$ = makeVariableNode($1.tokenIndex, $1.sval);
				}
	| VARIABLE LEFT_BRACKET expr RIGHT_BRACKET   
				{
					if (getSymbol($1.sval).address == 65535) {
						yyerrorInfo("Undeclared variable.", tokenTable.table[tokenTable.size - 4]);
						YYERROR;
					}
					$$ = makeArrayLoadNode($1.tokenIndex, $1.sval, $3);
				}
	| REAL_NUMBER                                {$$ = makeFloatValueNode($1.tokenIndex, $1.rval);}
	| INTEGER                                    {$$ = makeIntValueNode($1.tokenIndex, $1.ival);}
	| LEFT_PAREN expr RIGHT_PAREN                {$$ = $2;}
;


%%

int yyerror(const char* s) {
	printf("Error: %s\nOn line:\n", s);
	TokenInformation token = tokenTable.table[tokenTable.size - 1];
	printf("\t%d.| %.*s\n", token.lineNumber, token.lineSize - 1, token.lineBeginning);

	int numSize = 1;
	if (token.lineNumber > 9 && token.lineNumber < 100) numSize = 2;
	else if (token.lineNumber > 99 && token.lineNumber < 1000) numSize = 3;
	else if (token.lineNumber > 999 && token.lineNumber < 10000) numSize = 4;
	else if (token.lineNumber > 9999 && token.lineNumber < 100000) numSize = 5;

	printf("\t   %*c", token.column + numSize, ' ');
	printf("^-- Here.\n");
 	return 0;
}

int yyerrorInfo(const char* s, TokenInformation token) {
	printf("Error: %s\nOn line:\n", s);
	printf("\t%d.| %.*s\n", token.lineNumber, token.lineSize - 1, token.lineBeginning);

	int numSize = 1;
	if (token.lineNumber > 9 && token.lineNumber < 100) numSize = 2;
	else if (token.lineNumber > 99 && token.lineNumber < 1000) numSize = 3;
	else if (token.lineNumber > 999 && token.lineNumber < 10000) numSize = 4;
	else if (token.lineNumber > 9999 && token.lineNumber < 100000) numSize = 5;

	printf("\t   %*c", token.column + numSize, ' ');
	printf("^-- Here.\n");
 	return 0;
}
