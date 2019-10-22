/*
 * ========================================================================
 * 
 * main.c ------- All the source code for the parser is in src/parser.y
 *                To run this, type in make to make the binary, then type
 *                  
 *                        bin/slic.exe < filename.in
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

int main()
{
   	int n;

   	n = yyparse();
   	if (n == 0)
		printf("Parsing was successful.\n");
	else 
		printf("There was an error parsing\n");

		
   	exit(0);
}
