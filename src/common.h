#ifndef SLIC_COMMON_H
#define SLIC_COMMON_H

/*=================================================================
/* This file contains all the code necessary for error tracking.
/* It also contains a table with tokens, that point to the 
/* original line in source coude the token was found.
/*
/* Programmer: Gabe Ambrosio
/*================================================================= */

char* sourceCode;
char* beginningOfCurrentLine;
int   lengthOfCurrentLine;
int   currentLineNumber;
int   currentColumn;

/*=================================================================
/* The struct to hold information about the source code line
/* this token was found on.
/*================================================================= */
typedef struct {
    char* lineBeginning;
    int lineSize;
    int lineNumber;
    int column;
    int lexemeSize;
} TokenInformation;

/*=================================================================
/* The table to hold all the tokens
/*================================================================= */
typedef struct {
    TokenInformation* table;
    int size;
    int capacity;
} TokenTable;

/*=================================================================
/* A new struct to use for all the tokens in flex, so that they
/* can each keep track of their index as well as what value
/* the lexeme may hold.
/*================================================================= */
typedef struct {
    int tokenIndex;
    union {
        char* sval;
        float rval;
        int ival;
    };
} TokenHelper;
TokenTable tokenTable;

/*=================================================================
/* These are some functions to help initialize the token table,
/* increment the line in the source code, provide an error
/* function, and provide a method to insert a token into the table.
/*================================================================= */
void initTokenInformationTable();
void insertToken(char* lineBeginning, int lineSize, int lineNumber, int column, int lexemeSize);
void incrementLinePointer();
int yyerrorInfo(const char* s, TokenInformation token);


/*=================================================================
/* This redefinition of YY_USER_ACTION allows me to keep track of
/* which column the current token starts on. It also allows
/* me to insert a token every time a new token is encountered.
/*================================================================= */
#define YY_USER_ACTION if (yytext[0] != '\t' && yytext[0] != '\n' && strcmp(yytext, "\r\n") != 0) {\
    if (yytext[0] != ' ') {\
        yylval.helper.tokenIndex = tokenTable.size; \
        insertToken(beginningOfCurrentLine, lengthOfCurrentLine, currentLineNumber, currentColumn, yyleng);\
    }\
    if (!(yytext[0] == ' ' && currentColumn == 0)) {\
        currentColumn += yyleng;\
    }\
}

#define AS_ASSIGN_STMT(node) (node->as.assignStmt)
#define AS_VARIABLE(node)    (node->as.variable)

#endif