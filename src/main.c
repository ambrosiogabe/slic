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

#include "symbolTable.h"
#include "abstractSyntaxTree.h"
#include "compiler.h"

#ifdef PRETTY
	// Generated
	#include "generated/y.tab.h"
#else 
	#include "y.tab.h"
#endif

#include <stdio.h>
#include <stdlib.h>

// Helper functions to output GSTAL code
// to print contents of symbol table after
// execution of program.
void gstalPrintSymbol(SymbolTableEntry entry) {
	int curAddress = entry.address;

	for (char* c = entry.name; *c != '\0'; c++) {
		printf("LLI %d\n", *c);
		printf("PTC\n");
	}
	printf("LLI %d\n", ':');
	printf("PTC\n");
	printf("LLI %d\nPTC\n", ' ');

	for (int i=0; i < entry.size; i++) {
		printf("LAA %d\n", curAddress);
		if (entry.type == REAL)
			printf("LOD\nPTF\n");
		else 
			printf("LOD\nPTI\n");

		if (i != entry.size - 1)
			printf("LLI %d\nPTC\nLLI %d\nPTC\n", ',', ' ');
		curAddress++;
	}
	printf("PTL\n");
}

void gstalPrintAllSymbols() {
	for (int i=0; i < symbolTable.size; i++) {
		gstalPrintSymbol(symbolTable.symbols[i]);
	}
}

int main()
{
	initSymbolTable();
	initSyntaxTree();

   	int n;
   	n = yyparse();

   	if (n != 0) {
		printf("There was an error parsing::main.c\n");
		return -1;
	}

	//printSymbolTable();
	walkSyntaxTree();
	gstalPrintAllSymbols();

	// Clean up memory and exit
	freeAst();
	freeSymbolTable();
   	return 0;
}
