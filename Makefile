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
CLASS_FLEXOPTS = -I

YACC = bison
YACCOPTS = -d -y -b src/generated/y 
CLASS_YACCOPTS = -d -y 

slic: classLex.yy.c
	${CC} -o slic.exe symbolTable.c abstractSyntaxTree.c compiler.c lex.yy.c y.tab.c main.c ${LEXLIB}

pretty: mkdirs mvFiles lex.yy.c 
	${CC} -DPRETTY -o bin/slic.exe src/symbolTable.c src/abstractSyntaxTree.c src/compiler.c src/generated/lex.yy.c src/generated/y.tab.c src/main.c ${LEXLIB}

classLex.yy.c: classBison.y
	${LEX} ${CLASS_FLEXOPTS} scanner.l

classBison.y:
	bison ${CLASS_YACCOPTS} parser.y

lex.yy.c: bison.y
	${LEX} ${FLEXOPTS} src/scanner.l

bison.y:
	bison ${YACCOPTS} src/parser.y

mkdirs:
	mkdir -p src
	mkdir -p bin
	mkdir -p src/generated

mvFiles:
	-mv -t src *.c *.h *.y *.l

clean:
	-rm *.yy.c *.tab.c *.tab.h *.exe

cleanPretty:
	rm -rf bin
	rm -rf src/generated
	-mv src/* ./ 
	rm -rf src