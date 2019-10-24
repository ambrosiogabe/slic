/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_GENERATED_Y_TAB_H_INCLUDED
# define YY_YY_SRC_GENERATED_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN_RW = 258,
    END_RW = 259,
    DATA_RW = 260,
    ALGORITHM_RW = 261,
    EXIT_RW = 262,
    READ_RW = 263,
    PRINT_RW = 264,
    REAL_RW = 265,
    INTEGER_RW = 266,
    WHILE_RW = 267,
    IF_RW = 268,
    ELSE_RW = 269,
    COUNTING_RW = 270,
    UPWARD_RW = 271,
    DOWNWARD_RW = 272,
    TO_RW = 273,
    BANG = 274,
    SEMICOLON = 275,
    COLON = 276,
    COMMA = 277,
    LEFT_BRACKET = 278,
    RIGHT_BRACKET = 279,
    LEFT_PAREN = 280,
    RIGHT_PAREN = 281,
    LEFT_BRACE = 282,
    RIGHT_BRACE = 283,
    MULTIPLY_OP = 284,
    DIVIDE_OP = 285,
    MINUS_OP = 286,
    PLUS_OP = 287,
    MODULUS_OP = 288,
    LESS_THAN_OP = 289,
    LESS_THAN_EQUAL_OP = 290,
    GRT_THAN_OP = 291,
    GRT_THAN_EQUAL_OP = 292,
    EQUAL_OP = 293,
    NOT_EQUAL_OP = 294,
    AND_OP = 295,
    OR_OP = 296,
    NOT_OP = 297,
    ASSIGN_OP = 298,
    REAL_NUMBER = 299,
    INTEGER = 300,
    VARIABLE = 301,
    STRING = 302,
    NEWLINE = 303
  };
#endif
/* Tokens.  */
#define MAIN_RW 258
#define END_RW 259
#define DATA_RW 260
#define ALGORITHM_RW 261
#define EXIT_RW 262
#define READ_RW 263
#define PRINT_RW 264
#define REAL_RW 265
#define INTEGER_RW 266
#define WHILE_RW 267
#define IF_RW 268
#define ELSE_RW 269
#define COUNTING_RW 270
#define UPWARD_RW 271
#define DOWNWARD_RW 272
#define TO_RW 273
#define BANG 274
#define SEMICOLON 275
#define COLON 276
#define COMMA 277
#define LEFT_BRACKET 278
#define RIGHT_BRACKET 279
#define LEFT_PAREN 280
#define RIGHT_PAREN 281
#define LEFT_BRACE 282
#define RIGHT_BRACE 283
#define MULTIPLY_OP 284
#define DIVIDE_OP 285
#define MINUS_OP 286
#define PLUS_OP 287
#define MODULUS_OP 288
#define LESS_THAN_OP 289
#define LESS_THAN_EQUAL_OP 290
#define GRT_THAN_OP 291
#define GRT_THAN_EQUAL_OP 292
#define EQUAL_OP 293
#define NOT_EQUAL_OP 294
#define AND_OP 295
#define OR_OP 296
#define NOT_OP 297
#define ASSIGN_OP 298
#define REAL_NUMBER 299
#define INTEGER 300
#define VARIABLE 301
#define STRING 302
#define NEWLINE 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "src/parser.y" /* yacc.c:1909  */

   char *sval;
   int ival;
   float rval;

#line 156 "src/generated/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_GENERATED_Y_TAB_H_INCLUDED  */
