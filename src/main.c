/*
 * ========================================================================
 * 
 * main.c ------- All the source code for the parser is in src/parser.y
 *                To run this, type in make to make the binary, then type
 *                  
 *                        bin/slic.exe < filename.txt
 * 
 * 				  This will generate the parsers output for the given input
 *                file.
 * 
 * Programmer --- Gabe Ambrosio
 * 
 * ========================================================================
 */

// Generated
#include "generated/y.tab.h"

#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.h"

int main()
{
	initSymbolTable();

   	int n;
   	n = yyparse();

   	if (n != 0) {
		printf("There was an error parsing\n");
		return -1;
	}


	// Print the contents of the symbol table
	printf("|%11s|%11s|%11s|%11s|%11s|%11s|\n", "Type", "Name", "Address", "Size", "Structure", "Hash Value");
	for (int i=0; i < 73; i++) printf("=");
	printf("\n");

	for (int i=0; i < symbolTable.size; i++) {
		SymbolTableEntry entry = symbolTable.symbols[i];
		char* type = entry.type == INT ? "integer" : "real";
		char* structure = entry.structure == SCALAR ? "scalar" : "array"; 

		printf("|%11s|%11s|%11d|%11d|%11s|%11u|\n", type, entry.name, entry.address, entry.size, structure, entry.hashValue);
		for (int i=0; i < 73; i++) printf("-");
		printf("\n");
	}
	
	// Clean up memory and exit
	freeSymbolTable();
   	return 0;
}
