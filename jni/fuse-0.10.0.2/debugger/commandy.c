/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LOGICAL_OR = 258,
     LOGICAL_AND = 259,
     COMPARISON = 260,
     EQUALITY = 261,
     NEGATE = 262,
     TIMES_DIVIDE = 263,
     BASE = 264,
     BREAK = 265,
     TBREAK = 266,
     CLEAR = 267,
     COMMANDS = 268,
     CONDITION = 269,
     CONTINUE = 270,
     DEBUGGER_DELETE = 271,
     DISASSEMBLE = 272,
     DEBUGGER_END = 273,
     EVENT = 274,
     EXIT = 275,
     FINISH = 276,
     IF = 277,
     DEBUGGER_IGNORE = 278,
     NEXT = 279,
     DEBUGGER_OUT = 280,
     PORT = 281,
     DEBUGGER_PRINT = 282,
     READ = 283,
     SET = 284,
     STEP = 285,
     TIME = 286,
     WRITE = 287,
     PAGE = 288,
     DEBUGGER_REGISTER = 289,
     NUMBER = 290,
     STRING = 291,
     VARIABLE = 292,
     DEBUGGER_ERROR = 293
   };
#endif
/* Tokens.  */
#define LOGICAL_OR 258
#define LOGICAL_AND 259
#define COMPARISON 260
#define EQUALITY 261
#define NEGATE 262
#define TIMES_DIVIDE 263
#define BASE 264
#define BREAK 265
#define TBREAK 266
#define CLEAR 267
#define COMMANDS 268
#define CONDITION 269
#define CONTINUE 270
#define DEBUGGER_DELETE 271
#define DISASSEMBLE 272
#define DEBUGGER_END 273
#define EVENT 274
#define EXIT 275
#define FINISH 276
#define IF 277
#define DEBUGGER_IGNORE 278
#define NEXT 279
#define DEBUGGER_OUT 280
#define PORT 281
#define DEBUGGER_PRINT 282
#define READ 283
#define SET 284
#define STEP 285
#define TIME 286
#define WRITE 287
#define PAGE 288
#define DEBUGGER_REGISTER 289
#define NUMBER 290
#define STRING 291
#define VARIABLE 292
#define DEBUGGER_ERROR 293




/* Copy the first part of user declarations.  */
#line 26 "commandy.y"


#include <config.h>

#include <stdio.h>		/* Needed by NetBSD yacc */
#include <stdlib.h>
#include <string.h>

#include "debugger.h"
#include "debugger_internals.h"
#include "mempool.h"
#include "ui/ui.h"
#include "z80/z80.h"
#include "z80/z80_macros.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 46 "commandy.y"
{

  int token;
  int reg;

  libspectrum_dword integer;
  char *string;

  debugger_breakpoint_type bptype;
  debugger_breakpoint_life bplife;
  struct { int value1; libspectrum_word value2; } pair;

  debugger_expression* exp;

}
/* Line 187 of yacc.c.  */
#line 208 "commandy.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 221 "commandy.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  112

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      46,    47,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    39,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    12,    15,    20,    26,
      31,    38,    41,    47,    51,    53,    55,    58,    61,    63,
      65,    69,    71,    75,    78,    82,    86,    90,    92,    94,
      96,    97,    99,   101,   103,   107,   109,   111,   113,   115,
     116,   119,   120,   122,   123,   125,   127,   129,   131,   133,
     137,   140,   143,   146,   150,   154,   158,   162,   166,   170,
     174,   178,   182,   186,   188,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    50,    -1,     1,    -1,    49,    44,
      50,    -1,     9,    59,    -1,    51,    52,    53,    56,    -1,
      51,    26,    55,    53,    56,    -1,    51,    31,    59,    56,
      -1,    51,    19,    36,    45,    36,    56,    -1,    12,    57,
      -1,    13,    59,    44,    61,    18,    -1,    14,    35,    58,
      -1,    15,    -1,    16,    -1,    16,    59,    -1,    17,    59,
      -1,    20,    -1,    21,    -1,    23,    35,    59,    -1,    24,
      -1,    25,    59,    35,    -1,    27,    59,    -1,    29,    35,
      59,    -1,    29,    34,    59,    -1,    29,    37,    59,    -1,
      30,    -1,    10,    -1,    11,    -1,    -1,    28,    -1,    32,
      -1,    57,    -1,    54,    45,    59,    -1,    33,    -1,    59,
      -1,    28,    -1,    32,    -1,    -1,    22,    60,    -1,    -1,
      59,    -1,    -1,    60,    -1,    60,    -1,    35,    -1,    34,
      -1,    37,    -1,    46,    60,    47,    -1,    42,    60,    -1,
      43,    60,    -1,     7,    60,    -1,    60,    42,    60,    -1,
      60,    43,    60,    -1,    60,     8,    60,    -1,    60,     6,
      60,    -1,    60,     5,    60,    -1,    60,    41,    60,    -1,
      60,    40,    60,    -1,    60,    39,    60,    -1,    60,     4,
      60,    -1,    60,     3,    60,    -1,    62,    -1,    61,    62,
      -1,    36,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   148,   149,   150,   153,   154,   158,   164,
     168,   172,   173,   174,   177,   178,   179,   180,   181,   182,
     183,   186,   187,   188,   189,   190,   191,   192,   195,   196,
     199,   200,   201,   204,   205,   208,   209,   211,   212,   215,
     216,   219,   220,   223,   224,   227,   230,   233,   236,   239,
     240,   241,   245,   249,   253,   257,   261,   265,   269,   273,
     277,   281,   287,   295,   296,   301
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOGICAL_OR", "LOGICAL_AND",
  "COMPARISON", "EQUALITY", "NEGATE", "TIMES_DIVIDE", "BASE", "BREAK",
  "TBREAK", "CLEAR", "COMMANDS", "CONDITION", "CONTINUE",
  "DEBUGGER_DELETE", "DISASSEMBLE", "DEBUGGER_END", "EVENT", "EXIT",
  "FINISH", "IF", "DEBUGGER_IGNORE", "NEXT", "DEBUGGER_OUT", "PORT",
  "DEBUGGER_PRINT", "READ", "SET", "STEP", "TIME", "WRITE", "PAGE",
  "DEBUGGER_REGISTER", "NUMBER", "STRING", "VARIABLE", "DEBUGGER_ERROR",
  "'|'", "'^'", "'&'", "'+'", "'-'", "'\\n'", "':'", "'('", "')'",
  "$accept", "input", "command", "breakpointlife", "breakpointtype",
  "breakpointpair", "pageornumber", "portbreakpointtype",
  "optionalcondition", "numberorpc", "expressionornull", "number",
  "expression", "debuggercommands", "debuggercommand", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   124,
      94,    38,    43,    45,    10,    58,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     3,     2,     4,     5,     4,
       6,     2,     5,     3,     1,     1,     2,     2,     1,     1,
       3,     1,     3,     2,     3,     3,     3,     1,     1,     1,
       0,     1,     1,     1,     3,     1,     1,     1,     1,     0,
       2,     0,     1,     0,     1,     1,     1,     1,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    28,    29,    41,     0,     0,    14,    15,
       0,    18,    19,     0,    21,     0,     0,     0,    27,     0,
       3,    30,     0,    47,    46,    48,     0,     0,     0,     6,
      45,    11,    42,     0,    43,    16,    17,     0,     0,    23,
       0,     0,     0,     1,     0,     0,     0,    31,     0,    32,
      41,    52,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    44,    20,    22,
      25,    24,    26,     5,     0,    37,    38,    41,    39,    35,
      39,     0,    33,    42,    49,    62,    61,    57,    56,    55,
      60,    59,    58,    53,    54,     0,     0,    63,     0,    39,
       0,     9,     7,     0,    65,    12,    64,    39,     8,    40,
      34,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    20,    21,    50,    80,    81,    77,   101,    82,
      66,    83,    30,    96,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
      58,   -76,   111,   -76,   -76,   111,   111,   -29,   -76,   111,
     111,   -76,   -76,   -26,   -76,   111,   111,   -12,   -76,     1,
     -76,   186,   111,   -76,   -76,   -76,   111,   111,   111,   -76,
      86,   -76,   -76,   -33,   111,   -76,   -76,   111,   -18,   -76,
     111,   111,   111,   -76,   179,   -10,   -16,   -76,   111,   -76,
      77,   -76,   -76,   -76,    57,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,    -5,   -76,    86,   -76,   -76,
     -76,   -76,   -76,   -76,   -27,   -76,   -76,    77,     7,   -76,
       7,   -15,   -76,   -11,   -76,   101,   125,    -6,   131,   -76,
     129,   144,   116,    25,    25,    -3,    -8,   -76,     6,     7,
     111,   -76,   -76,   111,   -76,   -76,   -76,     7,   -76,    86,
     -76,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,    -1,   -76,   -76,   -30,   -76,   -76,   -75,    39,
     -76,    -2,    -7,   -76,   -32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int8 yytable[] =
{
      29,    43,    59,    32,    33,   102,    34,    35,    36,    37,
     105,    65,    75,    38,    39,    51,    76,    69,    98,    52,
      53,    54,    40,    41,   108,    42,    74,    67,    95,   100,
     103,    95,   111,    59,   -36,    68,    63,    64,    70,    71,
      72,   104,   107,    73,    31,    44,    78,    99,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -2,     1,
      55,    56,    57,    58,   106,    59,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,     0,    11,    12,
       0,    13,    14,    15,    22,    16,     0,    17,    18,    55,
      56,    57,    58,   109,    59,     0,    60,    61,    62,    63,
      64,   110,    -2,     0,    84,    56,    57,    58,     0,    59,
      79,    23,    24,     0,    25,     0,     0,     0,    22,    26,
      27,    57,    58,    28,    59,    60,    61,    62,    63,    64,
      57,    58,     0,    59,    57,    58,    57,    59,     0,    59,
      60,    61,    62,    63,    64,    23,    24,     0,    25,    57,
      58,     0,    59,    26,    27,     0,     0,    28,    63,    64,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    61,
      62,    63,    64,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,     0,    11,
      12,     0,    13,    14,    15,    45,    16,     0,    17,    18,
       0,     0,    46,     0,    47,     0,     0,    48,    49
};

static const yytype_int8 yycheck[] =
{
       2,     0,     8,     5,     6,    80,    35,     9,    10,    35,
      18,    44,    28,    15,    16,    22,    32,    35,    45,    26,
      27,    28,    34,    35,    99,    37,    36,    34,    36,    22,
      45,    36,   107,     8,    45,    37,    42,    43,    40,    41,
      42,    44,    36,    44,     5,    44,    48,    77,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     1,
       3,     4,     5,     6,    96,     8,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    21,
      -1,    23,    24,    25,     7,    27,    -1,    29,    30,     3,
       4,     5,     6,   100,     8,    -1,    39,    40,    41,    42,
      43,   103,    44,    -1,    47,     4,     5,     6,    -1,     8,
      33,    34,    35,    -1,    37,    -1,    -1,    -1,     7,    42,
      43,     5,     6,    46,     8,    39,    40,    41,    42,    43,
       5,     6,    -1,     8,     5,     6,     5,     8,    -1,     8,
      39,    40,    41,    42,    43,    34,    35,    -1,    37,     5,
       6,    -1,     8,    42,    43,    -1,    -1,    46,    42,    43,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    40,
      41,    42,    43,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    -1,    23,    24,    25,    19,    27,    -1,    29,    30,
      -1,    -1,    26,    -1,    28,    -1,    -1,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    20,    21,    23,    24,    25,    27,    29,    30,    49,
      50,    51,     7,    34,    35,    37,    42,    43,    46,    59,
      60,    57,    59,    59,    35,    59,    59,    35,    59,    59,
      34,    35,    37,     0,    44,    19,    26,    28,    31,    32,
      52,    60,    60,    60,    60,     3,     4,     5,     6,     8,
      39,    40,    41,    42,    43,    44,    58,    60,    59,    35,
      59,    59,    59,    50,    36,    28,    32,    55,    59,    33,
      53,    54,    57,    59,    47,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    36,    61,    62,    45,    53,
      22,    56,    56,    45,    44,    18,    62,    36,    56,    60,
      59,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 153 "commandy.y"
    { debugger_output_base = (yyvsp[(2) - (2)].integer); }
    break;

  case 7:
#line 154 "commandy.y"
    {
             debugger_breakpoint_add_address( (yyvsp[(2) - (4)].bptype), (yyvsp[(3) - (4)].pair).value1, (yyvsp[(3) - (4)].pair).value2, 0, (yyvsp[(1) - (4)].bplife),
					      (yyvsp[(4) - (4)].exp) );
	   }
    break;

  case 8:
#line 158 "commandy.y"
    {
	     int mask; libspectrum_word port;
	     mask = (yyvsp[(4) - (5)].pair).value1; port = (yyvsp[(4) - (5)].pair).value2;
	     if( mask == -1 ) mask = ( port < 0x100 ? 0x00ff : 0xffff );
	     debugger_breakpoint_add_port( (yyvsp[(3) - (5)].bptype), port, mask, 0, (yyvsp[(1) - (5)].bplife), (yyvsp[(5) - (5)].exp) );
           }
    break;

  case 9:
#line 164 "commandy.y"
    {
	     debugger_breakpoint_add_time( DEBUGGER_BREAKPOINT_TYPE_TIME,
					   (yyvsp[(3) - (4)].integer), 0, (yyvsp[(1) - (4)].bplife), (yyvsp[(4) - (4)].exp) );
	   }
    break;

  case 10:
#line 168 "commandy.y"
    {
	     debugger_breakpoint_add_event( DEBUGGER_BREAKPOINT_TYPE_EVENT,
					    (yyvsp[(3) - (6)].string), (yyvsp[(5) - (6)].string), 0, (yyvsp[(1) - (6)].bplife), (yyvsp[(6) - (6)].exp) );
	   }
    break;

  case 11:
#line 172 "commandy.y"
    { debugger_breakpoint_clear( (yyvsp[(2) - (2)].integer) ); }
    break;

  case 12:
#line 173 "commandy.y"
    { debugger_breakpoint_set_commands( (yyvsp[(2) - (5)].integer), (yyvsp[(4) - (5)].string) ); }
    break;

  case 13:
#line 174 "commandy.y"
    {
	     debugger_breakpoint_set_condition( (yyvsp[(2) - (3)].integer), (yyvsp[(3) - (3)].exp) );
           }
    break;

  case 14:
#line 177 "commandy.y"
    { debugger_run(); }
    break;

  case 15:
#line 178 "commandy.y"
    { debugger_breakpoint_remove_all(); }
    break;

  case 16:
#line 179 "commandy.y"
    { debugger_breakpoint_remove( (yyvsp[(2) - (2)].integer) ); }
    break;

  case 17:
#line 180 "commandy.y"
    { ui_debugger_disassemble( (yyvsp[(2) - (2)].integer) ); }
    break;

  case 18:
#line 181 "commandy.y"
    { debugger_exit_emulator(); }
    break;

  case 19:
#line 182 "commandy.y"
    { debugger_breakpoint_exit(); }
    break;

  case 20:
#line 183 "commandy.y"
    {
	     debugger_breakpoint_ignore( (yyvsp[(2) - (3)].integer), (yyvsp[(3) - (3)].integer) );
	   }
    break;

  case 21:
#line 186 "commandy.y"
    { debugger_next(); }
    break;

  case 22:
#line 187 "commandy.y"
    { debugger_port_write( (yyvsp[(2) - (3)].integer), (yyvsp[(3) - (3)].integer) ); }
    break;

  case 23:
#line 188 "commandy.y"
    { printf( "0x%x\n", (yyvsp[(2) - (2)].integer) ); }
    break;

  case 24:
#line 189 "commandy.y"
    { debugger_poke( (yyvsp[(2) - (3)].integer), (yyvsp[(3) - (3)].integer) ); }
    break;

  case 25:
#line 190 "commandy.y"
    { debugger_register_set( (yyvsp[(2) - (3)].reg), (yyvsp[(3) - (3)].integer) ); }
    break;

  case 26:
#line 191 "commandy.y"
    { debugger_variable_set( (yyvsp[(2) - (3)].string), (yyvsp[(3) - (3)].integer) ); }
    break;

  case 27:
#line 192 "commandy.y"
    { debugger_step(); }
    break;

  case 28:
#line 195 "commandy.y"
    { (yyval.bplife) = DEBUGGER_BREAKPOINT_LIFE_PERMANENT; }
    break;

  case 29:
#line 196 "commandy.y"
    { (yyval.bplife) = DEBUGGER_BREAKPOINT_LIFE_ONESHOT; }
    break;

  case 30:
#line 199 "commandy.y"
    { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_EXECUTE; }
    break;

  case 31:
#line 200 "commandy.y"
    { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_READ; }
    break;

  case 32:
#line 201 "commandy.y"
    { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_WRITE; }
    break;

  case 33:
#line 204 "commandy.y"
    { (yyval.pair).value1 = -1; (yyval.pair).value2 = (yyvsp[(1) - (1)].integer); }
    break;

  case 34:
#line 205 "commandy.y"
    { (yyval.pair).value1 = (yyvsp[(1) - (3)].integer); (yyval.pair).value2 = (yyvsp[(3) - (3)].integer); }
    break;

  case 35:
#line 208 "commandy.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 36:
#line 209 "commandy.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 37:
#line 211 "commandy.y"
    { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_PORT_READ; }
    break;

  case 38:
#line 212 "commandy.y"
    { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_PORT_WRITE; }
    break;

  case 39:
#line 215 "commandy.y"
    { (yyval.exp) = NULL; }
    break;

  case 40:
#line 216 "commandy.y"
    { (yyval.exp) = (yyvsp[(2) - (2)].exp); }
    break;

  case 41:
#line 219 "commandy.y"
    { (yyval.integer) = PC; }
    break;

  case 42:
#line 220 "commandy.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 43:
#line 223 "commandy.y"
    { (yyval.exp) = NULL; }
    break;

  case 44:
#line 224 "commandy.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 45:
#line 227 "commandy.y"
    { (yyval.integer) = debugger_expression_evaluate( (yyvsp[(1) - (1)].exp) ); }
    break;

  case 46:
#line 230 "commandy.y"
    { (yyval.exp) = debugger_expression_new_number( (yyvsp[(1) - (1)].integer), debugger_memory_pool );
		       if( !(yyval.exp) ) YYABORT;
		     }
    break;

  case 47:
#line 233 "commandy.y"
    { (yyval.exp) = debugger_expression_new_register( (yyvsp[(1) - (1)].reg), debugger_memory_pool );
			 if( !(yyval.exp) ) YYABORT;
		       }
    break;

  case 48:
#line 236 "commandy.y"
    { (yyval.exp) = debugger_expression_new_variable( (yyvsp[(1) - (1)].string), debugger_memory_pool );
			 if( !(yyval.exp) ) YYABORT;
		       }
    break;

  case 49:
#line 239 "commandy.y"
    { (yyval.exp) = (yyvsp[(2) - (3)].exp); }
    break;

  case 50:
#line 240 "commandy.y"
    { (yyval.exp) = (yyvsp[(2) - (2)].exp); }
    break;

  case 51:
#line 241 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_unaryop( '-', (yyvsp[(2) - (2)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 52:
#line 245 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_unaryop( (yyvsp[(1) - (2)].token), (yyvsp[(2) - (2)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 53:
#line 249 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop( '+', (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 54:
#line 253 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop( '-', (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 55:
#line 257 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop( (yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 56:
#line 261 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop( (yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 57:
#line 265 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop( (yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 58:
#line 269 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop( '&', (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 59:
#line 273 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop( '^', (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 60:
#line 277 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop( '|', (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 61:
#line 281 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop(
		  DEBUGGER_TOKEN_LOGICAL_AND, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool
                );
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 62:
#line 287 "commandy.y"
    {
	        (yyval.exp) = debugger_expression_new_binaryop(
		  DEBUGGER_TOKEN_LOGICAL_OR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), debugger_memory_pool
		);
		if( !(yyval.exp) ) YYABORT;
	      }
    break;

  case 63:
#line 295 "commandy.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 64:
#line 296 "commandy.y"
    {
                      (yyval.string) = mempool_alloc( debugger_memory_pool, strlen( (yyvsp[(1) - (2)].string) ) + strlen( (yyvsp[(2) - (2)].string) ) + 2 );
                      sprintf( (yyval.string), "%s\n%s", (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string) );
                    }
    break;


/* Line 1267 of yacc.c.  */
#line 1900 "commandy.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 303 "commandy.y"


