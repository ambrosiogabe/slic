#=========================================================================
# Makefile for making slic compiler
#=========================================================================

#=========================================================================
# To allow make to choose the right system, include this in your .login
# file:
# 
#     setenv BCSYSTEM [system name]
# 
# This is necessary so that selectSystem (see below) will work correctly.
#=========================================================================

CC = gcc

LEX = flex
LEXLIB = -lfl   #Cygwin
FLEXOPTS = -o src/generated/lex.yy.c -I

YACC = bison
YACCOPTS = -d -y -b src/generated/y 

slic: mkdirs lex.yy.c
	${CC} -o bin/slic.exe src/symbolTable.c src/generated/lex.yy.c src/generated/y.tab.c src/main.c ${LEXLIB}

lex.yy.c: bison.y
	${LEX} ${FLEXOPTS} src/scanner.l

bison.y:
	bison ${YACCOPTS} src/parser.y

mkdirs:
	mkdir -p debug
	mkdir -p bin
	mkdir -p src/generated

clean:
	rm -rf bin
	rm -rf src/generated