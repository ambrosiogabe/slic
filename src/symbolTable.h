#pragma once

#include <stdint.h>

typedef enum {
    INT,
    REAL,
} DataType;

typedef enum {
    ARRAY,
    SCALAR,
} DataStructure;

typedef struct {
    DataType type;
    char* name;
    uint16_t address;
    DataStructure structure;
    uint16_t size;
    unsigned int hashValue; // Used instead of string comparison
} SymbolTableEntry;

typedef struct {
    SymbolTableEntry* symbols;
    unsigned int size;
    unsigned int capacity;
} SymbolTable;

SymbolTable symbolTable;

void initSymbolTable();
void freeSymbolTable();
void insertSymbolTable(DataType type, char* name, uint16_t address, DataStructure structure, uint16_t size);
SymbolTableEntry getSymbol(char* name);

unsigned int hashVariableName(char* name);