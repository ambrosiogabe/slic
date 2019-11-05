#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "symbolTable.h"

void initSymbolTable() {
    symbolTable.size = 0;
    symbolTable.capacity = 8;
    symbolTable.symbols = (SymbolTableEntry*)malloc(symbolTable.capacity * sizeof(SymbolTableEntry));
}

void freeSymbolTable() {
    for (int i=0; i < symbolTable.size; i++) {
        free(symbolTable.symbols[i].name);
    }
    free(symbolTable.symbols);
}

static SymbolTableEntry makeSymbol(DataType type, char* name, uint16_t address, DataStructure structure, uint16_t size) {
    SymbolTableEntry entry;
    entry.type = type;
    entry.name = name;
    entry.address = address;
    entry.structure = structure;
    entry.size = size;
    entry.hashValue = hashVariableName(name);

    return entry;
}

void insertSymbolTable(DataType type, char* name, uint16_t address, DataStructure structure, uint16_t size) {
    SymbolTableEntry entry = makeSymbol(type, name, address, structure, size);
    if (symbolTable.size + 1 >= symbolTable.capacity) {
        symbolTable.capacity *= 2;
        symbolTable.symbols = realloc(symbolTable.symbols, symbolTable.capacity * sizeof(SymbolTableEntry));
    }

    symbolTable.symbols[symbolTable.size] = entry;
    symbolTable.size++;
}

SymbolTableEntry getSymbol(char* name) {
    int hash = hashVariableName(name);
    for (int i=0; i < symbolTable.size; i++) {
        if (symbolTable.symbols[i].hashValue == hash && strcmp(name, symbolTable.symbols[i].name) == 0) {
            return symbolTable.symbols[i];
        }
    }
    
    printf("Error: Symbol '%s' not declared.", name);
    exit(-1);
}

unsigned int hashVariableName(char* name) {
    unsigned int hash = 7;
    for (char* c = name; *c != '\0'; c++) {
            hash = (hash * 31) + (int)*c;
    }
    return hash;
}

void printSymbolTable() {
    // Print the contents of the symbol table
	printf("|%11s|%11s|%11s|%11s|%11s|\n", "Type", "Name", "Address", "Size", "Structure");
	for (int i=0; i < 61; i++) printf("=");
	printf("\n");

	for (int i=0; i < symbolTable.size; i++) {
		SymbolTableEntry entry = symbolTable.symbols[i];
		char* type = entry.type == INT ? "integer" : "real";
		char* structure = entry.structure == SCALAR ? "scalar" : "array"; 

		printf("|%11s|%11s|%11d|%11d|%11s|\n", type, entry.name, entry.address, entry.size, structure);
		for (int i=0; i < 61; i++) printf("-");
		printf("\n");
	}
}