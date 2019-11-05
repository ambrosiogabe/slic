#ifndef SLIC_SYMBOL_TABLE_H
#define SLIC_SYMBOL_TABLE_H

/*
 * ==============================================================================
 * 
 * symbolTable.h ------- This is the code that defines the symbolTable. It includes
 *                       functions to insert a variable into the symbol table,
 *                       get a symbol from the symbol table by name, and to 
 *                       initialize and free a symbol table for the SLIC language.
 * 
 *                       All implementations are included in the symbolTable.c file.
 * 
 * Programmer ---------- Gabe Ambrosio
 * 
 * ==============================================================================
 */

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

// A function to generate a hash for a variable, thus reducing
// the need to do a string comparison when doing lookups.
unsigned int hashVariableName(char* name); 
void printSymbolTable();

#endif