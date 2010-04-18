/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1489 of yacc.c.  */
#line 141 "commandy.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

