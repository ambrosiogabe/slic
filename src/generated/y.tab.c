/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y" /* yacc.c:339  */

/*
 * ========================================================================
 * 
 * parser.y   --- The grammar for the SLIC language
 *                Turning DEBUG_PARSER to 1 will not print the most
 *                useful debugging information yet.
 * 
 * Programmer --- Gabe Ambrosio
 * Class      --- Compiler Construction
 * 
 * ========================================================================
 */

#include <stdio.h>
#include <string.h>

#ifdef PRETTY
	#include "../symbolTable.h"
	#include "../abstractSyntaxTree.h"
	#include "../compiler.h"
	#include "../common.h"
#else 
	#include "symbolTable.h"
	#include "abstractSyntaxTree.h"
	#include "compiler.h"
	#include "common.h"
#endif

#define DEBUG_PARSER 0

int yyerror(const char* msg);
int yyerrorInfo(const char* s, TokenInformation token);
int yylex();

DataType currentType;
static int previousTokenIndex = 0;
int isParameter = 0;


#line 107 "src/generated/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 44 "src/parser.y" /* yacc.c:355  */

   AstNode* node;
   TokenHelper helper;

#line 252 "src/generated/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_GENERATED_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 269 "src/generated/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   132,   133,   138,   137,   172,   171,   189,
     189,   190,   194,   195,   199,   203,   204,   208,   209,   213,
     214,   218,   228,   246,   262,   280,   284,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   303,   307,   308,   312,
     313,   317,   318,   322,   326,   327,   331,   332,   333,   337,
     341,   342,   346,   350,   355,   363,   364,   368,   372,   375,
     382,   383,   384,   385,   389,   390,   391,   392,   393,   394,
     395,   399,   400,   401,   405,   406,   407,   408,   412,   413,
     417,   418,   419,   420,   421,   422
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN_RW", "END_RW", "DATA_RW",
  "ALGORITHM_RW", "EXIT_RW", "READ_RW", "PRINT_RW", "REAL_RW",
  "INTEGER_RW", "WHILE_RW", "IF_RW", "ELSE_RW", "COUNTING_RW", "UPWARD_RW",
  "DOWNWARD_RW", "TO_RW", "PARAM_RW", "RETURN_RW", "BANG", "SEMICOLON",
  "COLON", "COMMA", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PAREN",
  "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE", "MULTIPLY_TOKEN",
  "DIVIDE_TOKEN", "MINUS_TOKEN", "PLUS_TOKEN", "MODULUS_TOKEN",
  "LESS_THAN_TOKEN", "LESS_THAN_EQUAL_TOKEN", "GRT_THAN_TOKEN",
  "GRT_THAN_EQUAL_TOKEN", "EQUAL_TOKEN", "NOT_EQUAL_TOKEN", "AND_TOKEN",
  "OR_TOKEN", "NOT_TOKEN", "ASSIGN_TOKEN", "REAL_NUMBER", "INTEGER",
  "VARIABLE", "STRING", "NEWLINE", "$accept", "program", "functionList",
  "function", "$@1", "$@2", "parameterBlock", "$@3", "dataBlock",
  "algorithmBlock", "declarationStmtList", "dataType", "declarationList",
  "declarationItem", "stmtList", "blockStmtList", "stmt", "returnStmt",
  "functionCallStmt", "functionCall", "variableList", "exitStmt",
  "printList", "printItem", "printExpr", "readStmt", "whileLoop",
  "countingLoop", "ifStmt", "elseBlock", "assignStmt", "expr", "boolTerm",
  "binExpr", "term", "unary", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -12

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,  -109,  -109,    25,  -109,     3,    10,    24,  -109,  -109,
      65,    87,    57,   124,    70,    65,   142,   119,   115,   140,
     124,  -109,  -109,   142,   147,     0,   168,   142,   169,   149,
     126,   153,   128,    -5,    44,    44,   129,    44,   109,     0,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,   156,
     142,   132,   126,   154,    80,  -109,  -109,    -4,  -109,    44,
      62,    67,  -109,  -109,    36,  -109,  -109,   159,   158,  -109,
      69,   110,   131,    -8,  -109,  -109,    74,    79,   150,    81,
      44,    39,    44,  -109,  -109,   161,   113,   137,  -109,   126,
    -109,    44,   101,  -109,   110,    44,    51,  -109,    -5,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,     0,     0,    44,    44,  -109,    -9,   163,   160,
      26,    83,  -109,  -109,   164,  -109,    14,  -109,    33,  -109,
     165,  -109,   110,   110,   131,   131,   131,   131,   131,   131,
      -8,    -8,  -109,  -109,  -109,   182,     0,    15,    -7,    12,
     144,  -109,   170,    44,  -109,  -109,   172,  -109,  -109,   175,
    -109,   178,   173,   192,    44,    44,    44,  -109,  -109,  -109,
     176,   177,     0,   184,    85,    96,    98,  -109,  -109,  -109,
     179,     0,     0,  -109,  -109,   196,   198,   188,   189,   183,
     185,  -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     5,     0,     2,     4,     0,     0,     1,     3,
       0,     0,     0,     0,     0,     0,    13,     0,     0,     9,
       0,    17,    18,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      24,    35,    34,    33,    32,    30,    31,    28,    27,     0,
      10,     0,     0,    21,     0,    20,    43,     0,    48,     0,
       0,     0,    83,    84,    80,    47,    81,     0,    45,    46,
      49,    63,    70,    73,    77,    79,     0,     0,     0,     0,
       0,     0,     0,    23,     8,     0,     0,     0,    16,     0,
      50,     0,     0,    78,    62,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
      42,     0,     6,    15,     0,    19,     0,    85,     0,    40,
       0,    44,    60,    61,    65,    67,    64,    66,    68,    69,
      72,    71,    74,    75,    76,     0,    26,     0,     0,     0,
       0,    38,     0,     0,    58,    22,     0,    82,    39,     0,
      25,     0,     0,     0,     0,     0,     0,    37,    41,    51,
       0,     0,     0,     0,     0,     0,     0,    52,    56,    57,
       0,     0,     0,    59,    55,     0,     0,     0,     0,     0,
       0,    53,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,   201,  -109,  -109,  -109,  -109,  -109,   193,   190,
     186,   -13,   157,   122,  -109,  -108,     6,  -109,  -109,  -109,
     -93,  -109,   114,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,   -33,   -47,    54,    61,    52,   155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     7,     6,    15,    27,    13,    18,
      23,    24,    54,    55,    39,   145,   146,    41,    42,    66,
     119,    43,    67,    68,    69,    44,    45,    46,    47,   163,
      48,   120,    71,    72,    73,    74,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    76,    77,   130,    79,   147,     1,    31,    32,    33,
      29,   164,    34,    35,    94,    36,    58,   150,    90,   161,
      37,    91,    59,   109,   110,     8,    92,   111,    60,   162,
     165,    40,    10,    99,   100,    99,   100,    29,   160,    61,
     156,    62,    63,    64,    65,    83,    11,   117,    38,   121,
     153,     2,   132,   133,    99,   100,    99,   100,   126,   157,
     168,    95,   128,    96,   179,    70,    59,   118,    99,   100,
      12,    59,    60,   185,   186,    99,   100,    60,    59,   129,
      16,   148,   149,    61,    60,    62,    63,    64,    61,    59,
      62,    63,    64,    19,    59,    61,   112,    62,    63,    64,
      60,   113,    88,   116,    89,   154,    14,   181,    62,    63,
      64,    99,   100,    62,    63,    64,    99,   100,   182,    26,
     183,    99,   100,    99,   100,    99,   100,    99,   100,   127,
      17,   174,   175,   176,    80,   123,    81,    89,    99,   100,
      99,   100,    25,    99,   100,   -11,   101,   102,   103,   104,
     105,   106,    21,    22,    82,   134,   135,   136,   137,   138,
     139,   142,   143,   144,   107,   108,   114,   115,   140,   141,
      30,    49,    52,    51,    53,    56,    57,    78,    84,    87,
      85,    97,    98,   122,   124,   151,   159,   170,   152,   166,
     155,   171,   167,   158,   169,   172,   173,   180,   177,   178,
     187,   184,   188,   189,   190,   191,     9,   192,    20,    86,
      28,   125,   131,    50,     0,    93
};

static const yytype_int16 yycheck[] =
{
      33,    34,    35,    96,    37,   113,     3,     7,     8,     9,
      23,    18,    12,    13,    61,    15,    21,    26,    22,     4,
      20,    25,    27,    31,    32,     0,    59,    35,    33,    14,
      18,    25,    22,    42,    43,    42,    43,    50,   146,    44,
      26,    46,    47,    48,    49,    39,    22,    80,    48,    82,
      24,    48,    99,   100,    42,    43,    42,    43,    91,    26,
     153,    25,    95,    27,   172,    98,    27,    28,    42,    43,
       5,    27,    33,   181,   182,    42,    43,    33,    27,    28,
      23,   114,   115,    44,    33,    46,    47,    48,    44,    27,
      46,    47,    48,    23,    27,    44,    22,    46,    47,    48,
      33,    22,    22,    22,    24,    22,    19,    22,    46,    47,
      48,    42,    43,    46,    47,    48,    42,    43,    22,     4,
      22,    42,    43,    42,    43,    42,    43,    42,    43,    28,
       6,   164,   165,   166,    25,    22,    27,    24,    42,    43,
      42,    43,    23,    42,    43,     5,    36,    37,    38,    39,
      40,    41,    10,    11,    45,   101,   102,   103,   104,   105,
     106,   109,   110,   111,    33,    34,    16,    17,   107,   108,
      23,     3,    23,     4,    48,    22,    48,    48,    22,    25,
      48,    22,    24,    22,    47,    22,     4,    12,    28,    45,
      26,    13,    22,    28,    22,    22,     4,    13,    22,    22,
       4,    22,     4,    15,    15,    22,     5,    22,    15,    52,
      20,    89,    98,    27,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    48,    52,    53,    54,    56,    55,     0,    53,
      22,    22,     5,    59,    19,    57,    23,     6,    60,    23,
      59,    10,    11,    61,    62,    23,     4,    58,    60,    62,
      23,     7,     8,     9,    12,    13,    15,    20,    48,    65,
      67,    68,    69,    72,    76,    77,    78,    79,    81,     3,
      61,     4,    23,    48,    63,    64,    22,    48,    21,    27,
      33,    44,    46,    47,    48,    49,    70,    73,    74,    75,
      82,    83,    84,    85,    86,    87,    82,    82,    48,    82,
      25,    27,    45,    67,    22,    48,    63,    25,    22,    24,
      22,    25,    82,    87,    83,    25,    27,    22,    24,    42,
      43,    36,    37,    38,    39,    40,    41,    33,    34,    31,
      32,    35,    22,    22,    16,    17,    22,    82,    28,    71,
      82,    82,    22,    22,    47,    64,    82,    28,    82,    28,
      71,    73,    83,    83,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    86,    86,    66,    67,    66,    82,    82,
      26,    22,    28,    24,    22,    26,    26,    26,    28,     4,
      66,     4,    14,    80,    18,    18,    45,    22,    71,    22,
      12,    13,    22,     4,    82,    82,    82,    22,    22,    66,
      13,    22,    22,    22,    22,    66,    66,     4,     4,    15,
      15,    22,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    55,    54,    56,    54,    58,
      57,    57,    59,    59,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    69,    69,    70,
      70,    71,    71,    72,    73,    73,    74,    74,    74,    75,
      76,    76,    77,    78,    78,    79,    79,    80,    81,    81,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    85,    85,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     9,     0,     8,     0,
       4,     2,     3,     2,     3,     5,     4,     1,     1,     3,
       1,     1,     4,     2,     1,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     5,     4,     4,
       3,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     6,     7,    11,    11,     8,     7,     3,     4,     7,
       3,     3,     2,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     1,
       1,     1,     4,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 138 "src/parser.y" /* yacc.c:1646  */
    {
			if (getFunctionSymbol("main") == NULL) {
				yyerrorInfo("main function must be first function in file!", tokenTable.table[(yyvsp[0].helper).tokenIndex]);
				exit(-1);
			}

			insertFunctionSymbol((yyvsp[0].helper).sval);
			functionSymbolTable = getFunctionSymbol((yyvsp[0].helper).sval);
			AstNode* lastNode = astRootNode;
			while (lastNode->next != NULL) {
				lastNode = lastNode->next;
			}
			AstNode* functionNode = makeFunctionNode((yyvsp[0].helper).tokenIndex);
			functionNode->next = NULL;
			lastNode->next = functionNode;
		}
#line 1504 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 155 "src/parser.y" /* yacc.c:1646  */
    {
			AstNode* lastNode = astRootNode;
			while (lastNode->next != NULL) {
				lastNode = lastNode->next;
			}
			AstNode* exitNode = makeExitNode((yyvsp[-2].helper).tokenIndex);
			AstNode* endOfFunction = makeEndOfFunctionNode((yyvsp[-8].helper).tokenIndex, (yyvsp[-8].helper).sval);
			lastNode->next = endOfFunction;
			endOfFunction->next = exitNode;
			exitNode->next = NULL;

			if (strcmp((yyvsp[-8].helper).sval, (yyvsp[-1].helper).sval) != 0) {
				yyerrorInfo("end 'functionName' must match 'functionName'", tokenTable.table[(yyvsp[-1].helper).tokenIndex]);
			}
	  	}
#line 1524 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 172 "src/parser.y" /* yacc.c:1646  */
    {
			insertFunctionSymbol("main");
			functionSymbolTable = getFunctionSymbol("main");
		}
#line 1533 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 177 "src/parser.y" /* yacc.c:1646  */
    {
			AstNode* lastNode = astRootNode;
			while (lastNode->next != NULL) {
				lastNode = lastNode->next;
			}
			AstNode* exitNode = makeExitNode((yyvsp[-2].helper).tokenIndex);
			exitNode->next = NULL;
			lastNode->next = exitNode;
	  	}
#line 1547 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { isParameter = 1; }
#line 1553 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { isParameter = 0; }
#line 1559 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 208 "src/parser.y" /* yacc.c:1646  */
    {currentType = REAL;}
#line 1565 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 209 "src/parser.y" /* yacc.c:1646  */
    {currentType = INT;}
#line 1571 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 218 "src/parser.y" /* yacc.c:1646  */
    {
													if (getSymbol((yyvsp[0].helper).sval).address != 65535) {														
														yyerrorInfo("Duplicate variable declaration.", tokenTable.table[(yyvsp[0].helper).tokenIndex]);
														YYERROR;
													}
													if (!isParameter)
														insertSymbolTable(currentType, (yyvsp[0].helper).sval, SCALAR, 1);
													else 
														insertParameterSymbolTable(currentType, (yyvsp[0].helper).sval, SCALAR, 1);
												}
#line 1586 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {
													if (isParameter) {
														yyerrorInfo("Cannot use array as paramter for a function!", tokenTable.table[(yyvsp[-3].helper).tokenIndex]);
														YYERROR;
													}
													if (getSymbol((yyvsp[-3].helper).sval).address != 65535) {
														yyerrorInfo("Duplicate variable declaration.", tokenTable.table[(yyvsp[-3].helper).tokenIndex]);
														YYERROR;
													}
													if (!isParameter)
														insertSymbolTable(currentType, (yyvsp[-3].helper).sval, ARRAY, (yyvsp[-1].helper).ival);
													else 
														insertParameterSymbolTable(currentType, (yyvsp[-3].helper).sval, ARRAY, (yyvsp[-1].helper).ival);
												}
#line 1605 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 247 "src/parser.y" /* yacc.c:1646  */
    {
					  AstNode* lastNode = astRootNode;
					  if (lastNode == NULL) {
						astRootNode = (yyvsp[-1].node);
						lastNode = (yyvsp[-1].node);
					  } else {
						  while (lastNode->next != NULL) {
							  lastNode = lastNode->next;
						  }
					  }

					lastNode->next = (yyvsp[0].node);
					(yyval.node) = (yyvsp[0].node);
					(yyvsp[0].node)->next = NULL;
				}
#line 1625 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { 
					AstNode* lastNode = astRootNode;
					if (lastNode == NULL) {
						astRootNode = (yyvsp[0].node);
						lastNode = (yyvsp[0].node);
					} else {
						while (lastNode->next != NULL) {
							lastNode = lastNode->next;
						}
					}
					lastNode->next = (yyvsp[0].node);
					(yyval.node) = (yyvsp[0].node);
					(yyvsp[0].node)->next = NULL;
				}
#line 1644 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 280 "src/parser.y" /* yacc.c:1646  */
    { 
		  						(yyval.node) = (yyvsp[-1].node); 
								(yyval.node)->next = (yyvsp[0].node);
							}
#line 1653 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { 
								(yyval.node) = (yyvsp[0].node); 
								(yyval.node)->next = NULL;
							}
#line 1662 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 291 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1668 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 292 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1674 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 293 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makePrintListNode((yyvsp[-1].node)->tokenInfoIndex, (yyvsp[-1].node)); }
#line 1680 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1686 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1692 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 296 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1698 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1704 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1710 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1716 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeReturnNode((yyvsp[-2].helper).tokenIndex, (yyvsp[-1].node), functionSymbolTable->functionName); }
#line 1722 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeFunctionCallNode((yyvsp[-4].helper).tokenIndex, (yyvsp[-4].helper).sval, (yyvsp[-2].node)); }
#line 1728 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 308 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeFunctionCallNode((yyvsp[-3].helper).tokenIndex, (yyvsp[-3].helper).sval, NULL); }
#line 1734 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeFunctionCallNode((yyvsp[-3].helper).tokenIndex, (yyvsp[-3].helper).sval, (yyvsp[-1].node)); }
#line 1740 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 313 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeFunctionCallNode((yyvsp[-2].helper).tokenIndex, (yyvsp[-2].helper).sval, NULL); }
#line 1746 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); (yyval.node)->next = (yyvsp[0].node); }
#line 1752 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->next = NULL; }
#line 1758 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 322 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeExitNode((yyvsp[-1].helper).tokenIndex); }
#line 1764 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 326 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); (yyval.node)->next = (yyvsp[0].node); }
#line 1770 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->next = NULL; }
#line 1776 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1782 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeStringNode((yyvsp[0].helper).tokenIndex, (yyvsp[0].helper).sval); }
#line 1788 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 333 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeNewlineNode((yyvsp[0].helper).tokenIndex); }
#line 1794 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makePrintExpr((yyvsp[0].node)->tokenInfoIndex, (yyvsp[0].node)); }
#line 1800 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 341 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeReadNode((yyvsp[-2].helper).tokenIndex, (yyvsp[-1].helper).sval); }
#line 1806 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 342 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeReadArrayNode((yyvsp[-5].helper).tokenIndex, (yyvsp[-4].helper).sval, (yyvsp[-2].node)); }
#line 1812 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 346 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeWhileLoopNode((yyvsp[-6].helper).tokenIndex, (yyvsp[-5].node), (yyvsp[-3].node)); }
#line 1818 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 351 "src/parser.y" /* yacc.c:1646  */
    {
					AstNode* variable = makeVariableNode((yyvsp[-9].helper).tokenIndex, (yyvsp[-9].helper).sval);
					(yyval.node) = makeCountingLoopNode((yyvsp[-10].helper).tokenIndex, variable, 1, (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node));
				}
#line 1827 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 356 "src/parser.y" /* yacc.c:1646  */
    {
					AstNode* variable = makeVariableNode((yyvsp[-9].helper).tokenIndex, (yyvsp[-9].helper).sval);
					(yyval.node) = makeCountingLoopNode((yyvsp[-10].helper).tokenIndex, variable, 0, (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node));
				}
#line 1836 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 363 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeIfStatement((yyvsp[-4].node), (yyvsp[-6].node), (yyvsp[-3].node)); }
#line 1842 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeIfStatement((yyvsp[-3].node), (yyvsp[-5].node), NULL); }
#line 1848 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1854 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 372 "src/parser.y" /* yacc.c:1646  */
    { 
												(yyval.node) = makeAssignmentNode((yyvsp[-3].helper).tokenIndex, (yyvsp[-3].helper).sval, (yyvsp[-1].node)); 
											}
#line 1862 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 376 "src/parser.y" /* yacc.c:1646  */
    { 
												(yyval.node) = makeArrayAssignmentNode((yyvsp[-6].helper).tokenIndex, (yyvsp[-6].helper).sval, (yyvsp[-4].node), (yyvsp[-1].node));
											}
#line 1870 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 382 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, AND_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1876 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 383 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, OR_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1882 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 384 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeUnaryExprNode((yyvsp[-1].helper).tokenIndex, NOT_OP, (yyvsp[0].node));}
#line 1888 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 385 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1894 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 389 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, GRT_THAN_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1900 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 390 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, LESS_THAN_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1906 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 391 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, GRT_THAN_EQUAL_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1912 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 392 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, LESS_THAN_EQUAL_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1918 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 393 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, EQUAL_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1924 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 394 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, NOT_EQUAL_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1930 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 395 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1936 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 399 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, PLUS_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1942 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 400 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, MINUS_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1948 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 401 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1954 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 405 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, MULTIPLY_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1960 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 406 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, DIVIDE_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1966 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 407 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, MODULUS_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1972 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 408 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1978 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 412 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeUnaryExprNode((yyvsp[-1].helper).tokenIndex, MINUS_OP, (yyvsp[0].node));}
#line 1984 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 413 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1990 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 417 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeVariableNode((yyvsp[0].helper).tokenIndex, (yyvsp[0].helper).sval); }
#line 1996 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 418 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2002 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 419 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeArrayLoadNode((yyvsp[-3].helper).tokenIndex, (yyvsp[-3].helper).sval, (yyvsp[-1].node)); }
#line 2008 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 420 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeFloatValueNode((yyvsp[0].helper).tokenIndex, (yyvsp[0].helper).rval);}
#line 2014 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 421 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeIntValueNode((yyvsp[0].helper).tokenIndex, (yyvsp[0].helper).ival);}
#line 2020 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 422 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);}
#line 2026 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;


#line 2030 "src/generated/y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 426 "src/parser.y" /* yacc.c:1906  */


int yyerror(const char* msg) {
	printf("Error: %s\nOn line:\n", msg);
	TokenInformation token = tokenTable.table[tokenTable.size - 1];
	printf("\t%d.| %.*s\n", token.lineNumber, token.lineSize - 1, token.lineBeginning);

	int numSize = 1;
	if (token.lineNumber > 9 && token.lineNumber < 100) numSize = 2;
	else if (token.lineNumber > 99 && token.lineNumber < 1000) numSize = 3;
	else if (token.lineNumber > 999 && token.lineNumber < 10000) numSize = 4;
	else if (token.lineNumber > 9999 && token.lineNumber < 100000) numSize = 5;

	printf("\t   %*c", token.column + numSize, ' ');
	printf("^-- Here.\n");
	errorOccurred = 1;
 	return 0;
}

int yyerrorInfo(const char* s, TokenInformation token) {
	printf("Error: %s\nOn line:\n", s);
	printf("\t%d.| %.*s\n", token.lineNumber, token.lineSize - 1, token.lineBeginning);

	int numSize = 1;
	if (token.lineNumber > 9 && token.lineNumber < 100) numSize = 2;
	else if (token.lineNumber > 99 && token.lineNumber < 1000) numSize = 3;
	else if (token.lineNumber > 999 && token.lineNumber < 10000) numSize = 4;
	else if (token.lineNumber > 9999 && token.lineNumber < 100000) numSize = 5;

	printf("\t   %*c", token.column + numSize, ' ');
	printf("^-- Here.\n");
	errorOccurred = 1;
 	return 0;
}
