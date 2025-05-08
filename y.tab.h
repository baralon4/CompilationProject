/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_BOOL = 258,                  /* T_BOOL  */
    T_CHAR = 259,                  /* T_CHAR  */
    T_INT = 260,                   /* T_INT  */
    T_REAL = 261,                  /* T_REAL  */
    T_STRING = 262,                /* T_STRING  */
    T_INTPTR = 263,                /* T_INTPTR  */
    T_CHARPTR = 264,               /* T_CHARPTR  */
    T_REALPTR = 265,               /* T_REALPTR  */
    T_IF = 266,                    /* T_IF  */
    T_ELIF = 267,                  /* T_ELIF  */
    T_ELSE = 268,                  /* T_ELSE  */
    T_WHILE = 269,                 /* T_WHILE  */
    T_FOR = 270,                   /* T_FOR  */
    T_DO = 271,                    /* T_DO  */
    T_VAR = 272,                   /* T_VAR  */
    T_RETURNS = 273,               /* T_RETURNS  */
    T_RETURN = 274,                /* T_RETURN  */
    T_NULL = 275,                  /* T_NULL  */
    T_CALL = 276,                  /* T_CALL  */
    T_TYPE = 277,                  /* T_TYPE  */
    T_BEGIN = 278,                 /* T_BEGIN  */
    T_END = 279,                   /* T_END  */
    T_DEF = 280,                   /* T_DEF  */
    T_AND = 281,                   /* T_AND  */
    T_NOT = 282,                   /* T_NOT  */
    T_OR = 283,                    /* T_OR  */
    T_DIVISION = 284,              /* T_DIVISION  */
    T_ASSIGNMENT = 285,            /* T_ASSIGNMENT  */
    T_EQL = 286,                   /* T_EQL  */
    T_GREATER = 287,               /* T_GREATER  */
    T_GREATEREQL = 288,            /* T_GREATEREQL  */
    T_LESS = 289,                  /* T_LESS  */
    T_LESSEQL = 290,               /* T_LESSEQL  */
    T_MINUS = 291,                 /* T_MINUS  */
    T_NOTEQL = 292,                /* T_NOTEQL  */
    T_PLUS = 293,                  /* T_PLUS  */
    T_STAR = 294,                  /* T_STAR  */
    T_ADDRESS = 295,               /* T_ADDRESS  */
    T_TRUE = 296,                  /* T_TRUE  */
    T_FALSE = 297,                 /* T_FALSE  */
    T_LBRACKET = 298,              /* T_LBRACKET  */
    T_RBRACKET = 299,              /* T_RBRACKET  */
    T_CHAR_LTL = 300,              /* T_CHAR_LTL  */
    T_HEX_LTL = 301,               /* T_HEX_LTL  */
    T_REAL_LTL = 302,              /* T_REAL_LTL  */
    T_STRING_LITERAL = 303,        /* T_STRING_LITERAL  */
    T_PAR_NUM = 304,               /* T_PAR_NUM  */
    T_DEC_LTL = 305,               /* T_DEC_LTL  */
    T_IDENTIFIER_LITERAL = 306,    /* T_IDENTIFIER_LITERAL  */
    T_COMMENT = 307,               /* T_COMMENT  */
    T_NUMBER = 308,                /* T_NUMBER  */
    T_LPAREN = 309,                /* T_LPAREN  */
    T_RPAREN = 310,                /* T_RPAREN  */
    T_COLON = 311,                 /* T_COLON  */
    T_SEMICOLON = 312,             /* T_SEMICOLON  */
    T_COMMA = 313,                 /* T_COMMA  */
    T_MAIN = 314,                  /* T_MAIN  */
    T_LENGTH = 315                 /* T_LENGTH  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_BOOL 258
#define T_CHAR 259
#define T_INT 260
#define T_REAL 261
#define T_STRING 262
#define T_INTPTR 263
#define T_CHARPTR 264
#define T_REALPTR 265
#define T_IF 266
#define T_ELIF 267
#define T_ELSE 268
#define T_WHILE 269
#define T_FOR 270
#define T_DO 271
#define T_VAR 272
#define T_RETURNS 273
#define T_RETURN 274
#define T_NULL 275
#define T_CALL 276
#define T_TYPE 277
#define T_BEGIN 278
#define T_END 279
#define T_DEF 280
#define T_AND 281
#define T_NOT 282
#define T_OR 283
#define T_DIVISION 284
#define T_ASSIGNMENT 285
#define T_EQL 286
#define T_GREATER 287
#define T_GREATEREQL 288
#define T_LESS 289
#define T_LESSEQL 290
#define T_MINUS 291
#define T_NOTEQL 292
#define T_PLUS 293
#define T_STAR 294
#define T_ADDRESS 295
#define T_TRUE 296
#define T_FALSE 297
#define T_LBRACKET 298
#define T_RBRACKET 299
#define T_CHAR_LTL 300
#define T_HEX_LTL 301
#define T_REAL_LTL 302
#define T_STRING_LITERAL 303
#define T_PAR_NUM 304
#define T_DEC_LTL 305
#define T_IDENTIFIER_LITERAL 306
#define T_COMMENT 307
#define T_NUMBER 308
#define T_LPAREN 309
#define T_RPAREN 310
#define T_COLON 311
#define T_SEMICOLON 312
#define T_COMMA 313
#define T_MAIN 314
#define T_LENGTH 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "parser.y"

	struct node *node;
	char* string;
	int intval;
	


#line 195 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
