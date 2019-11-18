/* ==============================================================================
/* Implementation of symbolTable.h. See symbolTable.h for more details on 
/* specifics.
/* 
/* Programmer: Gabe Ambrosio
/* 
/* ============================================================================== */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "symbolTable.h"

void initSymbolTable() {
    symbolTable.size = 0;
    symbolTable.capacity = 8;
    symbolTable.functionSymbols = malloc(symbolTable.capacity * sizeof(FunctionSymbolTable));
}

void freeFunctionSymbolTable(FunctionSymbolTable* table) {
    for (int i=0; i < table->size; i++) {
        free(table->symbols[i].name);
    }
    free(table->symbols);
    free(table);
}

void freeSymbolTable() {
    for (int i=0; i < symbolTable.size; i++) {
        freeFunctionSymbolTable(symbolTable.functionSymbols[i]);
    }
    free(symbolTable.functionSymbols);
}

static SymbolTableEntry makeSymbol(DataType type, char* name, DataStructure structure, uint16_t size) {
    SymbolTableEntry entry;
    entry.type = type;
    entry.name = name;
    entry.address = functionSymbolTable->nextAddress;
    entry.structure = structure;
    entry.size = size;
    entry.isParameter = 0;
    entry.hashValue = hashVariableName(name);
    functionSymbolTable->nextAddress += size;

    return entry;
}

void insertSymbolTable(DataType type, char* name, DataStructure structure, uint16_t size) {
    SymbolTableEntry entry = makeSymbol(type, name, structure, size);
    if (functionSymbolTable->size + 1 >= functionSymbolTable->capacity) {
        functionSymbolTable->capacity *= 2;
        functionSymbolTable->symbols = realloc(functionSymbolTable->symbols, functionSymbolTable->capacity * sizeof(SymbolTableEntry));
    }

    functionSymbolTable->symbols[functionSymbolTable->size] = entry;
    functionSymbolTable->size++;
}

void insertParameterSymbolTable(DataType type, char* name, DataStructure structure, uint16_t size) {
    SymbolTableEntry entry = makeSymbol(type, name, structure, size);
    entry.isParameter = 1;
    if (functionSymbolTable->size + 1 >= functionSymbolTable->capacity) {
        functionSymbolTable->capacity *= 2;
        functionSymbolTable->symbols = realloc(functionSymbolTable->symbols, functionSymbolTable->capacity * sizeof(SymbolTableEntry));
    }

    functionSymbolTable->symbols[functionSymbolTable->size] = entry;
    functionSymbolTable->size++;
}

int getParameterLength(char* name) {
    FunctionSymbolTable* symbolTable = getFunctionSymbol(name);
    int length = 0;
    for (int i=0; i < symbolTable->size; i++) {
        if (symbolTable->symbols[i].isParameter == 1) length++;
    }
    return length;
}

int getVariableLength(char* name) {
    FunctionSymbolTable* symbolTable = getFunctionSymbol(name);
    int length = 0;
    for (int i=0; i < symbolTable->size; i++) {
        if (symbolTable->symbols[i].isParameter == 0) length++;
    }
    return length;
}

void setFunctionSymbolLine(char* funcName, int line) {
    FunctionSymbolTable* symbolTable = getFunctionSymbol(funcName);
    symbolTable->functionLine = line;
}

int getFunctionSymbolLine(char* funcName) {
   int ret = getFunctionSymbol(funcName)->functionLine;
   return ret;
}

void functionReturnsSymbol(char* funcName) {
    getFunctionSymbol(funcName)->returnsAValue = 1;
}

static FunctionSymbolTable* makeFunctionSymbol(char* name) {
    FunctionSymbolTable* table = malloc(sizeof(FunctionSymbolTable));
    table->capacity = 8;
    table->size = 0;
    table->nextAddress = 0;
    table->symbols = malloc(table->capacity * sizeof(SymbolTableEntry));
    table->functionName = name;
    table->returnsAValue = 0;
    table->hashValue = hashVariableName(name);
    return table;
}

void insertFunctionSymbol(char* name) {
    FunctionSymbolTable* table = makeFunctionSymbol(name);
    if (symbolTable.size + 1 >= symbolTable.capacity) {
        symbolTable.capacity *= 2;
        symbolTable.functionSymbols = realloc(symbolTable.functionSymbols, symbolTable.capacity * sizeof(FunctionSymbolTable));
    }
    symbolTable.functionSymbols[symbolTable.size] = table;
    symbolTable.size++;
}

SymbolTableEntry getSymbol(char* name) {
    int hash = hashVariableName(name);
    if (functionSymbolTable != NULL) {
        for (int i=0; i < functionSymbolTable->size; i++) {
            if (functionSymbolTable->symbols[i].hashValue == hash && strcmp(name, functionSymbolTable->symbols[i].name) == 0) {
                return functionSymbolTable->symbols[i];
            }
        }
    } else {
        printf("Null function symbol table!\n");
        exit(-1);
    }
    
    SymbolTableEntry badEntry;
    badEntry.address = 65535;
    return badEntry;
}

FunctionSymbolTable* getFunctionSymbol(char* name) {
    int hash = hashVariableName(name);
    for (int i=0; i < symbolTable.size; i++) {
        if (symbolTable.functionSymbols[i]->hashValue == hash && strcmp(name, symbolTable.functionSymbols[i]->functionName) == 0) {
            return symbolTable.functionSymbols[i];
        }
    }

    return NULL;
}

unsigned int hashVariableName(char* name) {
    unsigned int hash = 7;
    for (char* c = name; *c != '\0'; c++) {
            hash = (hash * 31) + (int)*c;
    }
    return hash;
}

void printSymbolTable() {
    FunctionSymbolTable* currentTable = NULL;
    for (int i=0; i < symbolTable.size; i++) {
        currentTable = symbolTable.functionSymbols[i];
        printf("%s\n", currentTable->functionName);
        printf("|%11s|%11s|%11s|%11s|%11s|%11s|\n", "Type", "Name", "Address", "Size", "Structure", "Param");
        for (int i=0; i < 73; i++) printf("=");
            printf("\n");

        for (int i=0; i < currentTable->size; i++) {
            SymbolTableEntry entry = currentTable->symbols[i];
            char* type = entry.type == INT ? "integer" : "real";
            char* structure = entry.structure == SCALAR ? "scalar" : "array"; 

            printf("|%11s|%11s|%11d|%11d|%11s|%11d|\n", type, entry.name, entry.address, entry.size, structure, entry.isParameter);
            for (int i=0; i < 73; i++) printf("-");
                printf("\n");
        }
        
        printf("\n\n");
    }
}