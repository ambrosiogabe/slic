/*
 * ========================================================================
 * 
 * main.c ------- The main program to run the compiler. All the methods
 *                are in the appropriate files.
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

/* ===============================================================================
/*	Helper function to open a file with error checking.
/* =============================================================================== */
static FILE* openFile(const char* path) {
	FILE* file = NULL;
	if (path != NULL)
		file = fopen(path, "r");
	else 
		file = stdin;

	if (file == NULL) {
		fprintf(stderr, "Could not open file \"%s\".\n", path);
		exit(74);
	}

	return file;
}

/* ===============================================================================
/*	Function to create a buffer from user input through cat (<) or from file
/*  input by the user.
/* =============================================================================== */
static char* readFile(const char* path) {
	FILE* file = NULL;
	int isStandardInput = 0;
	if (path != NULL) {
		file = fopen(path, "rb");
	}
	else {
		file = stdin;
		isStandardInput = 1;
	}

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
	if (isStandardInput != 1) {
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
	if (argc == 2) {
		sourceCode = readFile(argv[1]);
	} else if (argc == 1) {
		sourceCode = readFile(NULL);
	} else {
		printf("Correct usage: \n\t  slic input.slic\n\t| slic < input.slic\n");
		exit(-1);
	}

	lengthOfCurrentLine = -1;
	currentLineNumber = 1;
	beginningOfCurrentLine = sourceCode;
	currentColumn = 0;
	incrementLinePointer();
}

int main(int argc, char** argv)
{
	// Initialize everything if correct number of arguments
	extern FILE *yyin;
	init(argc, argv);
	initInstructionContainer();
	initTokenInformationTable();
	initSymbolTable();
	initSyntaxTree();

	// Initialize filename if the user gave an argument
   	int n;
	filename = NULL;
	if (argc == 2) {
		filename = strdup(argv[1]);
		yyin = openFile(filename);
		n = yyparse();
	} else {
		yyin = stdin;
		n = yyparse();
	} 

   	if (n != 0) {
		return -1;
	}

	printSymbolTable();
	// Walk syntax tree and generate code
	walkSyntaxTree();

	// Clean up memory and exit
	freeInstructionContainer();
	freeAst();
	freeSymbolTable();
	free(sourceCode);
	if (filename != NULL) free(filename);
	if (yyin != stdin && yyin != NULL) {
		fclose(yyin);
		free(yyin);
	}

   	return 0;
}
