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
    PARAM_RW = 274,
    RETURN_RW = 275,
    BANG = 276,
    SEMICOLON = 277,
    COLON = 278,
    COMMA = 279,
    LEFT_BRACKET = 280,
    RIGHT_BRACKET = 281,
    LEFT_PAREN = 282,
    RIGHT_PAREN = 283,
    LEFT_BRACE = 284,
    RIGHT_BRACE = 285,
    MULTIPLY_TOKEN = 286,
    DIVIDE_TOKEN = 287,
    MINUS_TOKEN = 288,
    PLUS_TOKEN = 289,
    MODULUS_TOKEN = 290,
    LESS_THAN_TOKEN = 291,
    LESS_THAN_EQUAL_TOKEN = 292,
    GRT_THAN_TOKEN = 293,
    GRT_THAN_EQUAL_TOKEN = 294,
    EQUAL_TOKEN = 295,
    NOT_EQUAL_TOKEN = 296,
    AND_TOKEN = 297,
    OR_TOKEN = 298,
    NOT_TOKEN = 299,
    ASSIGN_TOKEN = 300,
    REAL_NUMBER = 301,
    INTEGER = 302,
    VARIABLE = 303,
    STRING = 304,
    NEWLINE = 305
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
#define PARAM_RW 274
#define RETURN_RW 275
#define BANG 276
#define SEMICOLON 277
#define COLON 278
#define COMMA 279
#define LEFT_BRACKET 280
#define RIGHT_BRACKET 281
#define LEFT_PAREN 282
#define RIGHT_PAREN 283
#define LEFT_BRACE 284
#define RIGHT_BRACE 285
#define MULTIPLY_TOKEN 286
#define DIVIDE_TOKEN 287
#define MINUS_TOKEN 288
#define PLUS_TOKEN 289
#define MODULUS_TOKEN 290
#define LESS_THAN_TOKEN 291
#define LESS_THAN_EQUAL_TOKEN 292
#define GRT_THAN_TOKEN 293
#define GRT_THAN_EQUAL_TOKEN 294
#define EQUAL_TOKEN 295
#define NOT_EQUAL_TOKEN 296
#define AND_TOKEN 297
#define OR_TOKEN 298
#define NOT_TOKEN 299
#define ASSIGN_TOKEN 300
#define REAL_NUMBER 301
#define INTEGER 302
#define VARIABLE 303
#define STRING 304
#define NEWLINE 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "src/parser.y" /* yacc.c:1909  */

   AstNode* node;
   TokenHelper helper;

#line 159 "src/generated/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_GENERATED_Y_TAB_H_INCLUDED  */
