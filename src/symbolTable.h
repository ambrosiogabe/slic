#ifndef SLIC_SYMBOL_TABLE_H
#define SLIC_SYMBOL_TABLE_H

/* ==============================================================================
/* This is the code that defines the symbolTable. It includes
/* functions to insert a variable into the symbol table,
/* get a symbol from the symbol table by name, and to 
/* initialize and free a symbol table for the SLIC language.
/* 
/* All implementations are included in the symbolTable.c file.
/* 
/* Programmer: Gabe Ambrosio
/* 
/* ============================================================================== */

#include <stdint.h>

/* =================================================================
/* Helper enum to determine whether a symbol table entry
/* is a real or int.
/* ================================================================= */
typedef enum {
    INT,
    REAL,
} DataType;


/* =================================================================
/* Helper enum to determine whether a symbol table entry
/* is an array or a scalar value.
/* ================================================================= */
typedef enum {
    ARRAY,
    SCALAR,
} DataStructure;

/* =================================================================
/* SymbolTableEntry is the definition for one symbol 
/* table entry inside the array of symbols.
/*
/* @DataType type: Type (real or int)
/* @char* name: Variable name (e.g 'myVar', 'fido', 'fluffy')
/* @uint16_t address: The address of the first variable
/* @DataStructure structure: SCALAR or ARRAY
/* @uint16_t size: The size of the variable (1 if it is SCALAR)
/* @unsigned int hashValue: A hash of the variable name, used to 
/*                          increase lookup speed.
/* ================================================================= */
typedef struct {
    DataType type;
    char* name;
    uint16_t address;
    DataStructure structure;
    uint16_t size;
    unsigned int hashValue; // Used instead of string comparison
} SymbolTableEntry;

/* =================================================================
/* A SymbolTable is the container for all the symbol table entries.
/* It contains the size and capacity for the symbol table at its
/* current state.
/* ================================================================= */
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
void printSymbolTable();

#endif