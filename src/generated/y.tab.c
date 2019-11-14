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

int yyerror();
int yyerrorInfo(const char* s, TokenInformation token);
int yylex();

DataType currentType;
static int previousTokenIndex = 0;


#line 105 "src/generated/y.tab.c" /* yacc.c:339  */

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
    MULTIPLY_TOKEN = 284,
    DIVIDE_TOKEN = 285,
    MINUS_TOKEN = 286,
    PLUS_TOKEN = 287,
    MODULUS_TOKEN = 288,
    LESS_THAN_TOKEN = 289,
    LESS_THAN_EQUAL_TOKEN = 290,
    GRT_THAN_TOKEN = 291,
    GRT_THAN_EQUAL_TOKEN = 292,
    EQUAL_TOKEN = 293,
    NOT_EQUAL_TOKEN = 294,
    AND_TOKEN = 295,
    OR_TOKEN = 296,
    NOT_TOKEN = 297,
    ASSIGN_TOKEN = 298,
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
#define MULTIPLY_TOKEN 284
#define DIVIDE_TOKEN 285
#define MINUS_TOKEN 286
#define PLUS_TOKEN 287
#define MODULUS_TOKEN 288
#define LESS_THAN_TOKEN 289
#define LESS_THAN_EQUAL_TOKEN 290
#define GRT_THAN_TOKEN 291
#define GRT_THAN_EQUAL_TOKEN 292
#define EQUAL_TOKEN 293
#define NOT_EQUAL_TOKEN 294
#define AND_TOKEN 295
#define OR_TOKEN 296
#define NOT_TOKEN 297
#define ASSIGN_TOKEN 298
#define REAL_NUMBER 299
#define INTEGER 300
#define VARIABLE 301
#define STRING 302
#define NEWLINE 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "src/parser.y" /* yacc.c:355  */

   AstNode* node;
   TokenHelper helper;

#line 246 "src/generated/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_GENERATED_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "src/generated/y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   124,   128,   132,   136,   137,   141,   142,
     146,   147,   151,   158,   169,   185,   203,   207,   214,   215,
     216,   217,   218,   219,   220,   224,   228,   229,   233,   234,
     235,   239,   243,   244,   248,   252,   257,   265,   266,   270,
     274,   281,   292,   293,   294,   295,   299,   300,   301,   302,
     303,   304,   305,   309,   310,   311,   315,   316,   317,   318,
     322,   323,   327,   334,   342,   343,   344
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
  "DOWNWARD_RW", "TO_RW", "BANG", "SEMICOLON", "COLON", "COMMA",
  "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PAREN", "RIGHT_PAREN",
  "LEFT_BRACE", "RIGHT_BRACE", "MULTIPLY_TOKEN", "DIVIDE_TOKEN",
  "MINUS_TOKEN", "PLUS_TOKEN", "MODULUS_TOKEN", "LESS_THAN_TOKEN",
  "LESS_THAN_EQUAL_TOKEN", "GRT_THAN_TOKEN", "GRT_THAN_EQUAL_TOKEN",
  "EQUAL_TOKEN", "NOT_EQUAL_TOKEN", "AND_TOKEN", "OR_TOKEN", "NOT_TOKEN",
  "ASSIGN_TOKEN", "REAL_NUMBER", "INTEGER", "VARIABLE", "STRING",
  "NEWLINE", "$accept", "program", "mainBlock", "dataBlock",
  "algorithmBlock", "declarationStmtList", "dataType", "declarationList",
  "declarationItem", "stmtList", "blockStmtList", "stmt", "exitStmt",
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,     1,    32,   -89,    25,   -89,   112,    50,    95,   114,
      64,   -89,   -89,    95,   115,    -3,   122,   116,    88,   118,
      93,     0,    30,    30,    94,   -16,    -3,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   121,    88,   119,    42,   -89,   -89,
      18,   -89,    30,    38,    35,   -89,   -89,   120,   -89,   124,
     123,   -89,    76,    65,    96,   -15,   -89,   -89,    37,    45,
     113,    30,    30,   -89,   -89,   104,   101,   -89,    88,   -89,
      30,   -18,   -89,    65,    30,   -89,     0,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      -3,    -3,    30,    30,    13,    47,   -89,   125,   -89,    67,
     -89,    74,   -89,    65,    65,    96,    96,    96,    96,    96,
      96,   -15,   -15,   -89,   -89,   -89,   143,    -3,    12,    -7,
      10,   105,   -89,   -89,   130,   -89,   139,   -89,   140,   132,
     150,    30,    30,    30,   -89,   135,   136,    -3,   144,    49,
      53,    72,   -89,   -89,   -89,   138,    -3,    -3,   -89,   -89,
     155,   156,   146,   147,   145,   148,   -89,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     8,     9,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,    15,    24,    23,
      21,    22,    19,    18,     0,     0,    12,     0,    11,    25,
       0,    30,     0,     0,     0,    64,    65,    62,    29,     0,
      27,    28,    31,    45,    52,    55,    59,    61,     0,     0,
       0,     0,     0,    14,     3,     0,     0,     7,     0,    32,
       0,     0,    60,    44,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,    10,     0,
      66,     0,    26,    42,    43,    47,    49,    46,    48,    50,
      51,    54,    53,    56,    57,    58,     0,    17,     0,     0,
       0,     0,    40,    13,     0,    63,     0,    16,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,    34,    38,    39,     0,     0,     0,    41,    37,
       0,     0,     0,     0,     0,     0,    35,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,   -89,   151,   128,    98,   -89,
     -88,    -2,   -89,    91,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -22,   -42,    39,    46,     8,   126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    10,    13,    14,    37,    38,    26,
     116,   117,    28,    49,    50,    51,    29,    30,    31,    32,
     130,    33,    52,    53,    54,    55,    56,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    59,    73,   118,    19,    20,    21,    61,   100,    22,
      23,   131,    24,    27,    87,    88,   128,     1,    89,    41,
      71,     4,    77,    78,    63,    42,   129,    62,   132,   127,
       6,    43,     5,    77,    78,   103,   104,   121,    69,    94,
      95,    70,    44,    25,    45,    46,    47,    48,    99,   144,
      77,    78,   101,    77,    78,    42,     9,    90,   150,   151,
      42,    43,    67,    42,    68,    91,    43,   122,    16,   146,
     119,   120,    44,   147,    45,    46,    47,    77,    78,    45,
      46,    47,    45,    46,    47,    77,    78,    77,    78,    77,
      78,   124,   148,    77,    78,   113,   114,   115,   125,    79,
      80,    81,    82,    83,    84,    11,    12,    77,    78,   139,
     140,   141,    77,    78,    77,    78,    77,    78,   105,   106,
     107,   108,   109,   110,    96,    34,    68,    85,    86,    92,
      93,   111,   112,     8,    36,    15,    18,    35,    39,    40,
      60,    64,    66,    74,    75,    76,    97,   126,   133,   123,
     134,   135,   137,   136,   138,   142,   143,   145,   149,   152,
     153,   154,   155,    65,    17,   156,    98,   102,   157,    72
};

static const yytype_uint8 yycheck[] =
{
      22,    23,    44,    91,     7,     8,     9,    23,    26,    12,
      13,    18,    15,    15,    29,    30,     4,     3,    33,    19,
      42,    20,    40,    41,    26,    25,    14,    43,    18,   117,
       5,    31,     0,    40,    41,    77,    78,    24,    20,    61,
      62,    23,    42,    46,    44,    45,    46,    47,    70,   137,
      40,    41,    74,    40,    41,    25,     6,    20,   146,   147,
      25,    31,    20,    25,    22,    20,    31,    20,     4,    20,
      92,    93,    42,    20,    44,    45,    46,    40,    41,    44,
      45,    46,    44,    45,    46,    40,    41,    40,    41,    40,
      41,    24,    20,    40,    41,    87,    88,    89,    24,    34,
      35,    36,    37,    38,    39,    10,    11,    40,    41,   131,
     132,   133,    40,    41,    40,    41,    40,    41,    79,    80,
      81,    82,    83,    84,    20,     3,    22,    31,    32,    16,
      17,    85,    86,    21,    46,    21,    21,    21,    20,    46,
      46,    20,    23,    23,    20,    22,    45,     4,    43,    24,
      20,    12,    20,    13,     4,    20,    20,    13,    20,     4,
       4,    15,    15,    35,    13,    20,    68,    76,    20,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    51,    20,     0,     5,    52,    21,     6,
      53,    10,    11,    54,    55,    21,     4,    55,    21,     7,
       8,     9,    12,    13,    15,    46,    58,    60,    61,    65,
      66,    67,    68,    70,     3,    21,    46,    56,    57,    20,
      46,    19,    25,    31,    42,    44,    45,    46,    47,    62,
      63,    64,    71,    72,    73,    74,    75,    76,    71,    71,
      46,    23,    43,    60,    20,    56,    23,    20,    22,    20,
      23,    71,    76,    72,    23,    20,    22,    40,    41,    34,
      35,    36,    37,    38,    39,    31,    32,    29,    30,    33,
      20,    20,    16,    17,    71,    71,    20,    45,    57,    71,
      26,    71,    62,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    59,    60,    59,    71,
      71,    24,    20,    24,    24,    24,     4,    59,     4,    14,
      69,    18,    18,    43,    20,    12,    13,    20,     4,    71,
      71,    71,    20,    20,    59,    13,    20,    20,    20,    20,
      59,    59,     4,     4,    15,    15,    20,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    61,    62,    62,    63,    63,
      63,    64,    65,    65,    66,    67,    67,    68,    68,    69,
      70,    70,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    74,    74,    74,    74,
      75,    75,    76,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     7,     3,     3,     5,     4,     1,     1,
       3,     1,     1,     4,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     6,     7,    11,    11,     8,     7,     3,
       4,     7,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     1,     1,     4,     1,     1,     3
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
        case 8:
#line 141 "src/parser.y" /* yacc.c:1646  */
    {currentType = REAL;}
#line 1450 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 142 "src/parser.y" /* yacc.c:1646  */
    {currentType = INT;}
#line 1456 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 151 "src/parser.y" /* yacc.c:1646  */
    {
													if (getSymbol((yyvsp[0].helper).sval).address != 65535) {														
														yyerrorInfo("Duplicate variable declaration.", tokenTable.table[(yyvsp[0].helper).tokenIndex]);
														YYERROR;
													}
													insertSymbolTable(currentType, (yyvsp[0].helper).sval, SCALAR, 1);
												}
#line 1468 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 159 "src/parser.y" /* yacc.c:1646  */
    {
													if (getSymbol((yyvsp[-3].helper).sval).address != 65535) {
														yyerrorInfo("Duplicate variable declaration.", tokenTable.table[(yyvsp[-3].helper).tokenIndex]);
														YYERROR;
													}
													insertSymbolTable(currentType, (yyvsp[-3].helper).sval, ARRAY, (yyvsp[-1].helper).ival);
												}
#line 1480 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 170 "src/parser.y" /* yacc.c:1646  */
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
#line 1500 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 186 "src/parser.y" /* yacc.c:1646  */
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
#line 1519 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 203 "src/parser.y" /* yacc.c:1646  */
    { 
		  						(yyval.node) = (yyvsp[-1].node); 
								(yyval.node)->next = (yyvsp[0].node);
							}
#line 1528 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { 
								(yyval.node) = (yyvsp[0].node); 
								(yyval.node)->next = NULL;
							}
#line 1537 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1543 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1549 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makePrintListNode((yyvsp[-1].node)->tokenInfoIndex, (yyvsp[-1].node)); }
#line 1555 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1561 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1567 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1573 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 220 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1579 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 224 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeExitNode((yyvsp[-1].helper).tokenIndex); }
#line 1585 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); (yyval.node)->next = (yyvsp[0].node); }
#line 1591 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 229 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->next = NULL; }
#line 1597 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 233 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1603 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 234 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeStringNode((yyvsp[0].helper).tokenIndex, (yyvsp[0].helper).sval); }
#line 1609 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 235 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeNewlineNode((yyvsp[0].helper).tokenIndex); }
#line 1615 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 239 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makePrintExpr((yyvsp[0].node)->tokenInfoIndex, (yyvsp[0].node)); }
#line 1621 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 243 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeReadNode((yyvsp[-2].helper).tokenIndex, (yyvsp[-1].helper).sval); }
#line 1627 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 244 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeReadArrayNode((yyvsp[-5].helper).tokenIndex, (yyvsp[-4].helper).sval, (yyvsp[-2].node)); }
#line 1633 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeWhileLoopNode((yyvsp[-6].helper).tokenIndex, (yyvsp[-5].node), (yyvsp[-3].node)); }
#line 1639 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 253 "src/parser.y" /* yacc.c:1646  */
    {
					AstNode* variable = makeVariableNode((yyvsp[-9].helper).tokenIndex, (yyvsp[-9].helper).sval);
					(yyval.node) = makeCountingLoopNode((yyvsp[-10].helper).tokenIndex, variable, 1, (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node));
				}
#line 1648 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 258 "src/parser.y" /* yacc.c:1646  */
    {
					AstNode* variable = makeVariableNode((yyvsp[-9].helper).tokenIndex, (yyvsp[-9].helper).sval);
					(yyval.node) = makeCountingLoopNode((yyvsp[-10].helper).tokenIndex, variable, 0, (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node));
				}
#line 1657 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeIfStatement((yyvsp[-4].node), (yyvsp[-6].node), (yyvsp[-3].node)); }
#line 1663 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 266 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = makeIfStatement((yyvsp[-3].node), (yyvsp[-5].node), NULL); }
#line 1669 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 270 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1675 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { 
												if (getSymbol((yyvsp[-3].helper).sval).address == 65535) {
													yyerrorInfo("Unknown variable.", tokenTable.table[(yyvsp[-3].helper).tokenIndex]);
													YYERROR;
												}
												(yyval.node) = makeAssignmentNode((yyvsp[-3].helper).tokenIndex, (yyvsp[-3].helper).sval, (yyvsp[-1].node)); 
											}
#line 1687 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 282 "src/parser.y" /* yacc.c:1646  */
    { 
												if (getSymbol((yyvsp[-6].helper).sval).address == 65535) {
													yyerrorInfo("Unknown variable.", tokenTable.table[(yyvsp[-6].helper).tokenIndex]);
													YYERROR;
												}
												(yyval.node) = makeArrayAssignmentNode((yyvsp[-6].helper).tokenIndex, (yyvsp[-6].helper).sval, (yyvsp[-4].node), (yyvsp[-1].node));
											}
#line 1699 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 292 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, AND_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1705 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 293 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, OR_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1711 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 294 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeUnaryExprNode((yyvsp[-1].helper).tokenIndex, NOT_OP, (yyvsp[0].node));}
#line 1717 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 295 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1723 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 299 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, GRT_THAN_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1729 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 300 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, LESS_THAN_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1735 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 301 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, GRT_THAN_EQUAL_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1741 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 302 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, LESS_THAN_EQUAL_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1747 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 303 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, EQUAL_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1753 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 304 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, NOT_EQUAL_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1759 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 305 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1765 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 309 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, PLUS_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1771 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 310 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, MINUS_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1777 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 311 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1783 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 315 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, MULTIPLY_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1789 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 316 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, DIVIDE_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1795 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 317 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeExprNode((yyvsp[-1].helper).tokenIndex, MODULUS_OP, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1801 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 318 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1807 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 322 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeUnaryExprNode((yyvsp[-1].helper).tokenIndex, MINUS_OP, (yyvsp[0].node));}
#line 1813 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 323 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1819 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 327 "src/parser.y" /* yacc.c:1646  */
    {
		  			if (getSymbol((yyvsp[0].helper).sval).address == 65535) {
						  yyerror("Undeclared variable.");
						  YYERROR;
					}
					(yyval.node) = makeVariableNode((yyvsp[0].helper).tokenIndex, (yyvsp[0].helper).sval);
				}
#line 1831 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 335 "src/parser.y" /* yacc.c:1646  */
    {
					if (getSymbol((yyvsp[-3].helper).sval).address == 65535) {
						yyerrorInfo("Undeclared variable.", tokenTable.table[tokenTable.size - 4]);
						YYERROR;
					}
					(yyval.node) = makeArrayLoadNode((yyvsp[-3].helper).tokenIndex, (yyvsp[-3].helper).sval, (yyvsp[-1].node));
				}
#line 1843 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 342 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeFloatValueNode((yyvsp[0].helper).tokenIndex, (yyvsp[0].helper).rval);}
#line 1849 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 343 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = makeIntValueNode((yyvsp[0].helper).tokenIndex, (yyvsp[0].helper).ival);}
#line 1855 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 344 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1861 "src/generated/y.tab.c" /* yacc.c:1646  */
    break;


#line 1865 "src/generated/y.tab.c" /* yacc.c:1646  */
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
#line 348 "src/parser.y" /* yacc.c:1906  */


int yyerror(const char* s) {
	printf("Error: %s\nOn line:\n", s);
	TokenInformation token = tokenTable.table[tokenTable.size - 1];
	printf("\t%d.| %.*s\n", token.lineNumber, token.lineSize - 1, token.lineBeginning);

	int numSize = 1;
	if (token.lineNumber > 9 && token.lineNumber < 100) numSize = 2;
	else if (token.lineNumber > 99 && token.lineNumber < 1000) numSize = 3;
	else if (token.lineNumber > 999 && token.lineNumber < 10000) numSize = 4;
	else if (token.lineNumber > 9999 && token.lineNumber < 100000) numSize = 5;

	printf("\t   %*c", token.column + numSize, ' ');
	printf("^-- Here.\n");
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
 	return 0;
}
