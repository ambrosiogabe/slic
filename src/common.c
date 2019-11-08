#include <stdlib.h>

#include "common.h"

void initTokenInformationTable() {
    tokenTable.size = 0;
    tokenTable.capacity = 8;
    tokenTable.table = malloc(sizeof(TokenInformation) * tokenTable.capacity);
}

void insertToken(char* lineBeginning, int lineSize, int lineNumber, int column, int lexemeSize) {
    if (tokenTable.size + 1 >= tokenTable.capacity) {
        tokenTable.capacity *= 2;
        tokenTable.table = realloc(tokenTable.table, tokenTable.capacity * sizeof(TokenInformation));
    }

    TokenInformation newToken;
    newToken.lineBeginning = lineBeginning;
    newToken.lineSize = lineSize;
    newToken.lineNumber = lineNumber;
    newToken.column = column;
    newToken.lexemeSize = lexemeSize;
    tokenTable.table[tokenTable.size] = newToken;
    tokenTable.size++;
}

void incrementLinePointer() {
    beginningOfCurrentLine += lengthOfCurrentLine + 1; 
    lengthOfCurrentLine = 0; 
        for (char* p = beginningOfCurrentLine; *p != '\0' && (*p == '\t' || *p == ' '); p++) { 
            beginningOfCurrentLine++; 
        } 
        for (char* p = beginningOfCurrentLine; *p != '\0' && *p != '\n'; p++) { 
            lengthOfCurrentLine++; 
        } 
}