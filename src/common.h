#ifndef SLIC_COMMON_H
#define SLIC_COMMON_H

char* sourceCode;
char* beginningOfCurrentLine;
int   lengthOfCurrentLine;
int   currentLineNumber;
int   currentColumn;

typedef struct {
    char* lineBeginning;
    int lineSize;
    int lineNumber;
    int column;
    int lexemeSize;
} TokenInformation;

typedef struct {
    TokenInformation* table;
    int size;
    int capacity;
} TokenTable;

typedef struct {
    int tokenIndex;
    union {
        char* sval;
        float rval;
        int ival;
    };
} TokenHelper;

TokenTable tokenTable;

void initTokenInformationTable();
void insertToken(char* lineBeginning, int lineSize, int lineNumber, int column, int lexemeSize);
void incrementLinePointer();

#define YY_USER_ACTION if (yytext[0] != '\t' && yytext[0] != '\n' && strcmp(yytext, "\r\n") != 0) {\
    if (yytext[0] != ' ') {\
        yylval.helper.tokenIndex = tokenTable.size; \
        insertToken(beginningOfCurrentLine, lengthOfCurrentLine, currentLineNumber, currentColumn, yyleng);\
    }\
    if (!(yytext[0] == ' ' && currentColumn == 0)) {\
        currentColumn += yyleng;\
    }\
}

#endif