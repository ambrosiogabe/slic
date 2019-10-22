%{
    /*======================================================================
    * Author: Gabe Ambrosio
    * 
    * Description: This is a scanner for the Slic language.
    * The syntax of the language is as specified in the documentation
    * on Canvas.
    * ======================================================================*/
    #define DEBUG 0

    // Generated
    #include "y.tab.h"

    #include <stdio.h>
    #include <string.h>
%}

%%
[\t ]+                                              

[mM][aA][iI][nN]                                    {
                                                        if (DEBUG) printf("Token: MAIN_RW %s\n", yytext);
                                                        return(MAIN_RW);
                                                    }
                              
[eE][nN][dD]                                        {
                                                        if (DEBUG) printf("Token: END_RW %s\n", yytext);
                                                        return(END_RW);
                                                    }
                              
[dD][aA][tT][aA]                                    {
                                                        if (DEBUG) printf("Token: DATA_RW %s\n", yytext);
                                                        return(DATA_RW);
                                                    }
         
[aA][lL][gG][oO][rR][iI][tT][hH][mM]                {
                                                        if (DEBUG) printf("Token: ALGORITHM_RW %s\n", yytext);
                                                        return(ALGORITHM_RW);
                                                    }

[eE][xX][iI][tT]                                    {
                                                        if (DEBUG) printf("Token: EXIT_RW %s\n", yytext);
                                                        return(EXIT_RW);
                                                    }

[rR][eE][aA][dD]                                    {
                                                        if (DEBUG) printf("Token: READ_RW %s\n", yytext);
                                                        return(READ_RW);
                                                    }

[pP][rR][iI][nN][tT]                                {
                                                        if (DEBUG) printf("Token: PRINT_RW %s\n", yytext);
                                                        return(PRINT_RW);
                                                    }

[rR][eE][aA][lL]                                    {
                                                        if (DEBUG) printf("Token: REAL_RW %s\n", yytext);
                                                        return(REAL_RW);
                                                    }

[iI][nN][tT][eE][gG][eE][rR]                        {
                                                        if (DEBUG) printf("Token: INTEGER_RW %s\n", yytext);
                                                        return(INTEGER_RW);
                                                    }

[wW][hH][iI][lL][eE]                                {
                                                        if (DEBUG) printf("Token: WHILE_RW %s\n", yytext);
                                                        return(WHILE_RW);
                                                    }

[iI][fF]                                            {
                                                        if (DEBUG) printf("Token: IF_RW %s\n", yytext);
                                                        return(IF_RW);
                                                    }

[eE][lL][sS][eE]                                    {
                                                        if (DEBUG) printf("Token: ELSE_RW %s\n", yytext);
                                                        return(ELSE_RW);
                                                    }

[cC][oO][uU][nN][tT][iI][nN][gG]                    {
                                                        if (DEBUG) printf("Token: COUNTING_RW %s\n", yytext);
                                                        return(COUNTING_RW);
                                                    }

[uU][pP][wW][aA][rR][dD]                            {
                                                        if (DEBUG) printf("Token: UPWARD_RW %s\n", yytext);
                                                        return(UPWARD_RW);
                                                    }

[dD][oO][wW][nN][wW][aA][rR][dD]                    {
                                                        if (DEBUG) printf("Token: DOWNWARD_RW %s\n", yytext);
                                                        return(DOWNWARD_RW);
                                                    }

[tT][oO]                                            {
                                                        if (DEBUG) printf("Token: TO_RW %s\n", yytext);
                                                        return(TO_RW);
                                                    }

"!"                                                 {
                                                        if (DEBUG) printf("Token: BANG %s\n", yytext);
                                                        return(BANG);
                                                    }

";"                                                 {
                                                        if (DEBUG) printf("Token: SEMICOLON %s\n", yytext);
                                                        return(SEMICOLON);
                                                    }
         
":"                                                 {
                                                        if (DEBUG) printf("Token: COLON %s\n", yytext);
                                                        return(COLON);
                                                    }
         
","                                                 {
                                                        if (DEBUG) printf("Token: COMMA %s\n", yytext);
                                                        return(COMMA);
                                                    }

"["                                                 {
                                                        if (DEBUG) printf("Token: LEFT_BRACKET %s\n", yytext);
                                                        return(LEFT_BRACKET);
                                                    }

"]"                                                 {
                                                        if (DEBUG) printf("Token: RIGHT_BRACKET %s\n", yytext);
                                                        return(RIGHT_BRACKET);
                                                    }

"("                                                 {
                                                        if (DEBUG) printf("Token: LEFT_PAREN %s\n", yytext);
                                                        return(LEFT_PAREN);
                                                    }

")"                                                 {
                                                        if (DEBUG) printf("Token: RIGHT_PAREN %s\n", yytext);
                                                        return(RIGHT_PAREN);
                                                    }

"{"                                                 {
                                                        if (DEBUG) printf("Token: LEFT_BRACE %s\n", yytext);
                                                        return(LEFT_BRACE);
                                                    }

"}"                                                 {
                                                        if (DEBUG) printf("Token: RIGHT_BRACE %s\n", yytext);
                                                        return(RIGHT_BRACE);
                                                    }

"*"                                                 {
                                                        if (DEBUG) printf("Token: MULTIPLY_OP %s\n", yytext);
                                                        return(MULTIPLY_OP);
                                                    }

"/"                                                 {
                                                        if (DEBUG) printf("Token: DIVIDE_OP %s\n", yytext);
                                                        return(DIVIDE_OP);
                                                    }

"-"                                                 {
                                                        if (DEBUG) printf("Token: MINUS_OP %s\n", yytext);
                                                        return(MINUS_OP);
                                                    }

"+"                                                 {
                                                        if (DEBUG) printf("Token: ADD_OP %s\n", yytext);
                                                        return(PLUS_OP);
                                                    }

"%"                                                 {
                                                        if (DEBUG) printf("Token: MODULUS_OP %s\n", yytext);
                                                        return(MODULUS_OP);
                                                    }

"<"                                                 {
                                                        if (DEBUG) printf("Token: LESS_THAN_OP %s\n", yytext);
                                                        return(LESS_THAN_OP);
                                                    }

"<="                                                {
                                                        if (DEBUG) printf("Token: LESS_THAN_EQUAL_OP %s\n", yytext);
                                                        return(LESS_THAN_EQUAL_OP);
                                                    }

">"                                                 {
                                                        if (DEBUG) printf("Token: GRT_THAN_OP %s\n", yytext);
                                                        return(GRT_THAN_OP);
                                                    }

">="                                                {
                                                        if (DEBUG) printf("Token: GRT_THAN_EQUAL_OP %s\n", yytext);
                                                        return(GRT_THAN_EQUAL_OP);
                                                    }

"="                                                 {
                                                        if (DEBUG) printf("Token: EQUAL_OP %s\n", yytext);
                                                        return(EQUAL_OP);
                                                    }

"<>"                                                {
                                                        if (DEBUG) printf("Token: NOT_EQUAL_OP %s\n", yytext);
                                                        return(NOT_EQUAL_OP);
                                                    }

"&"                                                 {
                                                        if (DEBUG) printf("Token: AND_OP %s\n", yytext);
                                                        return(AND_OP);
                                                    }

"|"                                                 {
                                                        if (DEBUG) printf("Token: OR_OP %s\n", yytext);
                                                        return(OR_OP);
                                                    }

"~"                                                 {
                                                        if (DEBUG) printf("Token: NOT_OP %s\n", yytext);
                                                        return(NOT_OP);
                                                    }

":="                                                {
                                                        if (DEBUG) printf("Token: ASSIGN_OP %s\n", yytext);
                                                        return(ASSIGN_OP);
                                                    }
         
#(.*)                                               {
                                                        if (DEBUG) printf("Token: COMMENT  %s\n", yytext);
                                                    }

(\+|-)?(([0-9]+)\.([0-9]+))((e|E)(\+|-)?[0-9]+)?    {
                                                        if (DEBUG) printf("Token: REAL_NUMBER  %s\n", yytext);
                                                        yylval.sval = strdup(yytext);
                                                        return(REAL_NUMBER);
                                                    }

[0-9]+                                              {
                                                        if (DEBUG) printf("Token: INTEGER  %s\n", yytext);
                                                        yylval.sval = strdup(yytext);
                                                        return(INTEGER);
                                                    }

([a-zA-Z])([a-zA-Z0-9]*)                            {
                                                        if (DEBUG) printf("Token: VARIABLE  %s\n", yytext);
                                                        yylval.sval = strdup(yytext);
                                                        return(VARIABLE);
                                                    }

\"(([^\"]*)(\"\")?)*\"                              {
                                                        if (DEBUG) printf("Token: STRING  %s\n", yytext);
                                                        yylval.sval = strdup(yytext);
                                                        return(STRING);
                                                    }

(\n)|(\r\n)                                         {
                                                        if (DEBUG) printf("Newline\n");
                                                    }
%%