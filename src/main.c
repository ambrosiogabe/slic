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
#include "common.h"

#ifdef PRETTY
	// Generated
	#include "generated/y.tab.h"
#else 
	#include "y.tab.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* ===============================================================================
/*	Function to create a buffer from user input through cat (<) or from file
/*  input by the user.
/* =============================================================================== */
static char* readFile(const char* path) {
	FILE* file = NULL;
	if (path != NULL)
		file = fopen(path, "rb");
	else 
		file = stdin;

	if (file == NULL) {
		fprintf(stderr, "Could not open file \"%s\".\n", path);
		exit(74);
	}

	fseek(file, 0L, SEEK_END);
	size_t fileSize = ftell(file);
	rewind(file);

	char* buffer = (char*)malloc(fileSize + 1);
	if (buffer == NULL) {
		fprintf(stderr, "Not enough memory to read\"%s\".\n", path);
		exit(74);
	}

	size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
	if (bytesRead < fileSize) {
		fprintf(stderr, "Could not read file \"%s\".\n", path);
		exit(74);
	}

	buffer[bytesRead] = '\0';
	if (file != stdin) {
		fclose(file);
	} else {
		rewind(file);
	}
	return buffer;
}

/* ===============================================================================
/*	Initialize my own buffer to keep track of lines for error reporting
/* =============================================================================== */
static void init(int argc, char** argv) {
	if (argc > 2) {
		sourceCode = readFile(argv[2]);
	} else {
		sourceCode = readFile(NULL);
	}

	lengthOfCurrentLine = -1;
	currentLineNumber = 1;
	beginningOfCurrentLine = sourceCode;
	currentColumn = 0;
	incrementLinePointer();
}

int main(int argc, char** argv)
{
	init(argc, argv);
	initTokenInformationTable();
	initSymbolTable();
	initSyntaxTree();

   	int n;
   	n = yyparse();

   	if (n != 0) {
		return -1;
	}

	//printSymbolTable();
	walkSyntaxTree();
	gstalPrintAllSymbols();

	// Clean up memory and exit
	freeAst();
	freeSymbolTable();
	free(sourceCode);
   	return 0;
}
