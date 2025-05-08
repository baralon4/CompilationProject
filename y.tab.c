/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TTSTYPE struct node*

int yylex();

int yyerror(char *e);

typedef struct node
{
	char *token;
    struct node *left;
	struct node *right;
    
}node;


typedef struct Scope {
    struct Scope* father;
    struct Link* first;
}Scope;

typedef struct Link {
    struct Link* next;
    char* name;
    char* type;
    // אפשר להוסיף כאן מידע נוסף כמו ערך או מיקום בקוד (val, line)
}Link;

// === Function to create a new scope ===
Scope *createScope(Scope *father) {
    Scope *s = (Scope *)malloc(sizeof(Scope));
    s->father = father;
    s->first = NULL;
    return s;
}

// === Function to add a symbol to a scope ===
void addSymbol(Scope *scope, char *name, char *type) {
    Link *l = (Link *)malloc(sizeof(Link));
    l->name = strdup(name);
    l->type = strdup(type);
    l->next = scope->first;
    scope->first = l;
}


int MAIN_COUNT=0;
int semantic_error = 0;

// Global root scope
Scope* globalScope;

node *mknode(char *token, node *left, node *right);
void printtree(node *root, int indent);
void print_args(node *args);
void semanticAnalyzer(node* ast);
void checkMainExists(node* root);
void buildSymbolTable(node *n, Scope *currentScope);
int isDeclaredInScope(Scope* scope, const char* name);
void processFunctionParams(node* parsNode, Scope* funcScope); 
void traverseAST(node* n, Scope* currentScope);





int printlevel=0;
extern int yylineno;
extern char* yytext;

#line 146 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 76 "parser.y"

	struct node *node;
	char* string;
	int intval;
	


#line 327 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_BOOL = 3,                     /* T_BOOL  */
  YYSYMBOL_T_CHAR = 4,                     /* T_CHAR  */
  YYSYMBOL_T_INT = 5,                      /* T_INT  */
  YYSYMBOL_T_REAL = 6,                     /* T_REAL  */
  YYSYMBOL_T_STRING = 7,                   /* T_STRING  */
  YYSYMBOL_T_INTPTR = 8,                   /* T_INTPTR  */
  YYSYMBOL_T_CHARPTR = 9,                  /* T_CHARPTR  */
  YYSYMBOL_T_REALPTR = 10,                 /* T_REALPTR  */
  YYSYMBOL_T_IF = 11,                      /* T_IF  */
  YYSYMBOL_T_ELIF = 12,                    /* T_ELIF  */
  YYSYMBOL_T_ELSE = 13,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 14,                   /* T_WHILE  */
  YYSYMBOL_T_FOR = 15,                     /* T_FOR  */
  YYSYMBOL_T_DO = 16,                      /* T_DO  */
  YYSYMBOL_T_VAR = 17,                     /* T_VAR  */
  YYSYMBOL_T_RETURNS = 18,                 /* T_RETURNS  */
  YYSYMBOL_T_RETURN = 19,                  /* T_RETURN  */
  YYSYMBOL_T_NULL = 20,                    /* T_NULL  */
  YYSYMBOL_T_CALL = 21,                    /* T_CALL  */
  YYSYMBOL_T_TYPE = 22,                    /* T_TYPE  */
  YYSYMBOL_T_BEGIN = 23,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 24,                     /* T_END  */
  YYSYMBOL_T_DEF = 25,                     /* T_DEF  */
  YYSYMBOL_T_AND = 26,                     /* T_AND  */
  YYSYMBOL_T_NOT = 27,                     /* T_NOT  */
  YYSYMBOL_T_OR = 28,                      /* T_OR  */
  YYSYMBOL_T_DIVISION = 29,                /* T_DIVISION  */
  YYSYMBOL_T_ASSIGNMENT = 30,              /* T_ASSIGNMENT  */
  YYSYMBOL_T_EQL = 31,                     /* T_EQL  */
  YYSYMBOL_T_GREATER = 32,                 /* T_GREATER  */
  YYSYMBOL_T_GREATEREQL = 33,              /* T_GREATEREQL  */
  YYSYMBOL_T_LESS = 34,                    /* T_LESS  */
  YYSYMBOL_T_LESSEQL = 35,                 /* T_LESSEQL  */
  YYSYMBOL_T_MINUS = 36,                   /* T_MINUS  */
  YYSYMBOL_T_NOTEQL = 37,                  /* T_NOTEQL  */
  YYSYMBOL_T_PLUS = 38,                    /* T_PLUS  */
  YYSYMBOL_T_STAR = 39,                    /* T_STAR  */
  YYSYMBOL_T_ADDRESS = 40,                 /* T_ADDRESS  */
  YYSYMBOL_T_TRUE = 41,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 42,                   /* T_FALSE  */
  YYSYMBOL_T_LBRACKET = 43,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 44,                /* T_RBRACKET  */
  YYSYMBOL_T_CHAR_LTL = 45,                /* T_CHAR_LTL  */
  YYSYMBOL_T_HEX_LTL = 46,                 /* T_HEX_LTL  */
  YYSYMBOL_T_REAL_LTL = 47,                /* T_REAL_LTL  */
  YYSYMBOL_T_STRING_LITERAL = 48,          /* T_STRING_LITERAL  */
  YYSYMBOL_T_PAR_NUM = 49,                 /* T_PAR_NUM  */
  YYSYMBOL_T_DEC_LTL = 50,                 /* T_DEC_LTL  */
  YYSYMBOL_T_IDENTIFIER_LITERAL = 51,      /* T_IDENTIFIER_LITERAL  */
  YYSYMBOL_T_COMMENT = 52,                 /* T_COMMENT  */
  YYSYMBOL_T_NUMBER = 53,                  /* T_NUMBER  */
  YYSYMBOL_T_LPAREN = 54,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 55,                  /* T_RPAREN  */
  YYSYMBOL_T_COLON = 56,                   /* T_COLON  */
  YYSYMBOL_T_SEMICOLON = 57,               /* T_SEMICOLON  */
  YYSYMBOL_T_COMMA = 58,                   /* T_COMMA  */
  YYSYMBOL_T_MAIN = 59,                    /* T_MAIN  */
  YYSYMBOL_T_LENGTH = 60,                  /* T_LENGTH  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_s = 62,                         /* s  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_function_list = 64,             /* function_list  */
  YYSYMBOL_main = 65,                      /* main  */
  YYSYMBOL_function = 66,                  /* function  */
  YYSYMBOL_parameter_list = 67,            /* parameter_list  */
  YYSYMBOL_parameter = 68,                 /* parameter  */
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_type_ret = 70,                  /* type_ret  */
  YYSYMBOL_var_list = 71,                  /* var_list  */
  YYSYMBOL_var_list_inner = 72,            /* var_list_inner  */
  YYSYMBOL_var = 73,                       /* var  */
  YYSYMBOL_var_a = 74,                     /* var_a  */
  YYSYMBOL_block = 75,                     /* block  */
  YYSYMBOL_stmt_list = 76,                 /* stmt_list  */
  YYSYMBOL_stmt = 77,                      /* stmt  */
  YYSYMBOL_do_while_stmt = 78,             /* do_while_stmt  */
  YYSYMBOL_if_stmt = 79,                   /* if_stmt  */
  YYSYMBOL_elif_list = 80,                 /* elif_list  */
  YYSYMBOL_else_clause = 81,               /* else_clause  */
  YYSYMBOL_suite = 82,                     /* suite  */
  YYSYMBOL_assignment_stmt = 83,           /* assignment_stmt  */
  YYSYMBOL_lhs = 84,                       /* lhs  */
  YYSYMBOL_call_expr = 85,                 /* call_expr  */
  YYSYMBOL_expr_list = 86,                 /* expr_list  */
  YYSYMBOL_expr = 87                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   132,   132,   142,   148,   155,   162,   169,   173,   174,
     178,   191,   214,   237,   256,   261,   269,   277,   278,   279,
     280,   281,   282,   283,   284,   288,   294,   295,   299,   300,
     312,   320,   327,   334,   340,   346,   353,   358,   365,   371,
     377,   389,   392,   395,   403,   406,   411,   412,   415,   418,
     423,   428,   431,   434,   437,   439,   444,   453,   473,   474,
     485,   486,   492,   493,   498,   504,   508,   516,   527,   530,
     533,   544,   545,   546,   547,   549,   550,   551,   552,   553,
     554,   556,   557,   559,   560,   561,   562,   564,   566,   569,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_BOOL", "T_CHAR",
  "T_INT", "T_REAL", "T_STRING", "T_INTPTR", "T_CHARPTR", "T_REALPTR",
  "T_IF", "T_ELIF", "T_ELSE", "T_WHILE", "T_FOR", "T_DO", "T_VAR",
  "T_RETURNS", "T_RETURN", "T_NULL", "T_CALL", "T_TYPE", "T_BEGIN",
  "T_END", "T_DEF", "T_AND", "T_NOT", "T_OR", "T_DIVISION", "T_ASSIGNMENT",
  "T_EQL", "T_GREATER", "T_GREATEREQL", "T_LESS", "T_LESSEQL", "T_MINUS",
  "T_NOTEQL", "T_PLUS", "T_STAR", "T_ADDRESS", "T_TRUE", "T_FALSE",
  "T_LBRACKET", "T_RBRACKET", "T_CHAR_LTL", "T_HEX_LTL", "T_REAL_LTL",
  "T_STRING_LITERAL", "T_PAR_NUM", "T_DEC_LTL", "T_IDENTIFIER_LITERAL",
  "T_COMMENT", "T_NUMBER", "T_LPAREN", "T_RPAREN", "T_COLON",
  "T_SEMICOLON", "T_COMMA", "T_MAIN", "T_LENGTH", "$accept", "s",
  "program", "function_list", "main", "function", "parameter_list",
  "parameter", "type", "type_ret", "var_list", "var_list_inner", "var",
  "var_a", "block", "stmt_list", "stmt", "do_while_stmt", "if_stmt",
  "elif_list", "else_clause", "suite", "assignment_stmt", "lhs",
  "call_expr", "expr_list", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-71)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,   -23,    30,  -111,   -15,    19,  -111,     3,    23,  -111,
      19,  -111,    -1,    19,    47,    47,    19,   413,    32,  -111,
      44,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,    37,
      46,    47,    53,    63,    66,  -111,    83,  -111,    95,   413,
      24,    24,   413,  -111,    95,  -111,    83,    68,    83,  -111,
    -111,  -111,    71,  -111,    24,    83,   149,    70,  -111,    24,
     102,   102,    77,   102,    81,  -111,    90,    19,  -111,   164,
    -111,  -111,  -111,    79,   104,    82,    -4,    88,   132,  -111,
     102,   102,   102,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
     -11,  -111,   102,   102,  -111,   259,   275,   100,   215,   105,
     102,  -111,  -111,  -111,   102,  -111,   108,     6,    70,  -111,
     102,  -111,  -111,   365,   102,   102,   304,   185,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     180,    -5,    97,  -111,    65,   334,   365,   117,   109,   111,
    -111,   229,   351,   319,  -111,  -111,   376,   376,  -111,    59,
      59,    59,    59,    59,   -26,    59,   -26,  -111,  -111,  -111,
    -111,  -111,  -111,   102,   116,   201,  -111,    72,    70,    70,
    -111,  -111,  -111,    49,   245,  -111,    65,   118,    70,  -111,
    -111,   102,   120,  -111,   100,  -111,   119,  -111,   290,   180,
     126,    70,   180,  -111,   128,  -111,  -111,    24,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       9,     0,     0,     2,     6,     5,     8,     0,     0,     1,
       9,     7,     0,     4,    15,    15,     3,     0,     0,    14,
       0,    20,    18,    17,    19,    21,    22,    23,    24,     0,
       0,     0,     0,     0,    27,    13,    27,    16,     0,     0,
       0,     0,     0,    26,    28,    25,    27,     0,    27,    12,
      43,    10,     0,    29,     0,    27,     0,     0,    11,     0,
     101,   101,     0,   101,     0,    42,    65,    54,    53,     0,
      45,    43,    46,     0,     0,     0,    36,     0,     0,    99,
     101,   101,   101,    97,    98,    95,    93,    94,    96,    92,
      90,    91,   101,   101,   100,     0,     0,     0,     0,     0,
     101,    41,    44,    51,   101,    52,     0,     0,     0,    30,
     101,    83,    85,    84,   101,   101,     0,     0,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
       9,     0,     0,    50,   101,     0,    64,     0,    37,    38,
      31,     0,     0,     0,    87,    86,    81,    82,    74,    75,
      77,    78,    79,    80,    72,    76,    71,    73,    53,    63,
      58,    47,    48,   101,     0,    68,    66,    39,     0,     0,
      56,    88,    89,    60,     0,    67,   101,     0,     0,    32,
      33,   101,     0,    57,     0,    69,    40,    34,     0,     9,
       0,     0,     9,    61,     0,    35,    59,     0,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,    48,   178,     8,   171,   159,    -8,  -111,
     -13,   148,  -111,   -88,   -40,  -111,   -47,   -54,  -111,  -111,
    -111,  -110,   -90,  -111,   -52,    17,   -55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    67,     5,     6,    18,    19,    29,    46,
      40,    43,    44,    77,   158,    69,   159,    50,    72,   173,
     183,   160,    73,    74,    94,   164,   165
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    51,    71,   120,    75,    95,    96,   132,    98,    70,
       1,    47,    11,   129,    58,    71,    68,    75,    48,    78,
     140,    11,   102,    41,    11,   111,   112,   113,     7,    68,
       9,    45,   114,    54,    52,    56,     8,   116,   117,   106,
      47,   162,    59,   115,    12,   135,    66,    48,     4,   136,
       7,   138,   107,    13,   108,   141,   139,    14,    16,   142,
     143,   181,   182,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    11,    71,    15,    75,   193,
     179,   180,   196,    38,    39,    79,    64,    30,   120,    31,
     187,   161,    80,    33,   190,   126,    17,   128,   129,    32,
      38,    31,    34,   195,    81,    82,    83,    84,   174,    36,
      85,    86,    87,    88,    37,    89,    90,    42,    91,    92,
     -70,    76,    79,    64,    55,    93,   188,    57,   177,    80,
     178,    97,    99,   100,   104,    71,   103,    75,    71,   105,
      75,    81,    82,    83,    84,   109,   110,    85,    86,    87,
      88,    66,    89,    90,   163,    91,    92,   198,   137,   134,
      60,   167,    93,    61,    62,    47,   186,   168,    63,   169,
      64,   175,    48,    65,    12,    60,   189,   191,    61,    62,
      47,   194,    10,    63,   197,    64,    20,    48,   101,    12,
      35,    60,    53,   185,    61,    62,    47,     0,     0,    63,
      66,    64,     0,    48,     0,    12,     0,     0,     0,     0,
       0,   118,     0,   119,   120,    66,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,   118,     0,   119,
     120,    66,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   118,     0,   119,   120,   145,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   118,     0,   119,   120,   176,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,   118,   133,   119,   120,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   118,   170,   119,   120,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,   118,   184,   119,   120,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   118,     0,   119,   120,
       0,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     118,   131,   119,   120,     0,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,   118,   192,   119,   120,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   144,
     118,     0,   119,   120,     0,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   172,     0,     0,   118,   166,   119,
     120,     0,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   118,     0,   119,   120,   171,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   120,     0,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    21,    22,    23,    24,
      25,    26,    27,    28
};

static const yytype_int16 yycheck[] =
{
      40,    41,    56,    29,    56,    60,    61,    97,    63,    56,
      25,    16,     4,    39,    54,    69,    56,    69,    23,    59,
     108,    13,    69,    36,    16,    80,    81,    82,    51,    69,
       0,    39,    43,    46,    42,    48,    59,    92,    93,    43,
      16,   131,    55,    54,    25,   100,    51,    23,     0,   104,
      51,    45,    56,     5,    58,   110,    50,    54,    10,   114,
     115,    12,    13,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    67,   130,    54,   130,   189,
     168,   169,   192,    17,    18,    20,    21,    55,    29,    57,
     178,   131,    27,    56,   184,    36,    49,    38,    39,    55,
      17,    57,    56,   191,    39,    40,    41,    42,   163,    56,
      45,    46,    47,    48,    51,    50,    51,    22,    53,    54,
      55,    51,    20,    21,    56,    60,   181,    56,    56,    27,
      58,    54,    51,    43,    30,   189,    57,   189,   192,    57,
     192,    39,    40,    41,    42,    57,    14,    45,    46,    47,
      48,    51,    50,    51,    57,    53,    54,   197,    50,    54,
      11,    44,    60,    14,    15,    16,    48,    58,    19,    58,
      21,    55,    23,    24,    25,    11,    56,    58,    14,    15,
      16,    55,     4,    19,    56,    21,    15,    23,    24,    25,
      31,    11,    44,   176,    14,    15,    16,    -1,    -1,    19,
      51,    21,    -1,    23,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    51,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    26,    -1,    28,
      29,    51,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    26,    -1,    28,    29,    60,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    26,    -1,    28,    29,    58,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    26,    57,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    26,    57,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    26,    57,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    56,    26,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      26,    56,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    26,    56,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    55,
      26,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    55,    -1,    -1,    26,    44,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    26,    -1,    28,    29,    44,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     3,     4,     5,     6,
       7,     8,     9,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    62,    63,    64,    65,    66,    51,    59,     0,
      65,    66,    25,    64,    54,    54,    64,    49,    67,    68,
      67,     3,     4,     5,     6,     7,     8,     9,    10,    69,
      55,    57,    55,    56,    56,    68,    56,    51,    17,    18,
      71,    71,    22,    72,    73,    69,    70,    16,    23,    75,
      78,    75,    69,    72,    71,    56,    71,    56,    75,    71,
      11,    14,    15,    19,    21,    24,    51,    64,    75,    76,
      77,    78,    79,    83,    84,    85,    51,    74,    75,    20,
      27,    39,    40,    41,    42,    45,    46,    47,    48,    50,
      51,    53,    54,    60,    85,    87,    87,    54,    87,    51,
      43,    24,    77,    57,    30,    57,    43,    56,    58,    57,
      14,    87,    87,    87,    43,    54,    87,    87,    26,    28,
      29,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      56,    56,    83,    57,    54,    87,    87,    50,    45,    50,
      74,    87,    87,    87,    55,    60,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    75,    77,
      82,    75,    83,    57,    86,    87,    44,    44,    58,    58,
      57,    44,    55,    80,    87,    55,    58,    56,    58,    74,
      74,    12,    13,    81,    57,    86,    48,    74,    87,    56,
      83,    58,    56,    82,    55,    74,    82,    56,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    64,    64,    64,
      65,    66,    66,    67,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    71,    71,    72,    72,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    79,    80,    80,
      81,    81,    82,    82,    83,    84,    84,    85,    86,    86,
      86,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     1,     2,     1,     0,
       8,    10,     8,     3,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     1,     2,
       5,     3,     5,     5,     6,     8,     1,     3,     3,     4,
       6,     4,     3,     1,     2,     1,     1,     4,     4,    10,
       3,     2,     2,     1,     1,     1,     7,     6,     0,     5,
       0,     3,     1,     1,     3,     1,     4,     5,     1,     3,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     3,     3,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* s: program  */
#line 132 "parser.y"
                {
		semanticAnalyzer((yyvsp[0].node));
		if (!semantic_error) {
			printtree((yyvsp[0].node), 0);
			printf("syntax valid\n");
		}
	}
#line 1580 "y.tab.c"
    break;

  case 3: /* program: function_list main function_list  */
#line 143 "parser.y"
        {
		(yyval.node)=mknode("CODE",(yyvsp[-2].node),(yyvsp[-1].node));
	}
#line 1588 "y.tab.c"
    break;

  case 4: /* program: main function_list  */
#line 149 "parser.y"
    {
        (yyval.node)=mknode("CODE",(yyvsp[-1].node),NULL);
    }
#line 1596 "y.tab.c"
    break;

  case 5: /* program: main  */
#line 156 "parser.y"
    {
        (yyval.node)=mknode("CODE",(yyvsp[0].node),NULL);
    }
#line 1604 "y.tab.c"
    break;

  case 6: /* program: function_list  */
#line 163 "parser.y"
    {
        (yyval.node)=mknode("CODE",(yyvsp[0].node),NULL);
    }
#line 1612 "y.tab.c"
    break;

  case 7: /* function_list: function_list function  */
#line 170 "parser.y"
        {
		(yyval.node)=mknode("",(yyvsp[-1].node),(yyvsp[0].node));
	}
#line 1620 "y.tab.c"
    break;

  case 8: /* function_list: function  */
#line 173 "parser.y"
                   {(yyval.node)=mknode("",(yyvsp[0].node),NULL);}
#line 1626 "y.tab.c"
    break;

  case 9: /* function_list: %empty  */
#line 174 "parser.y"
                      { (yyval.node) = NULL; }
#line 1632 "y.tab.c"
    break;

  case 10: /* main: T_DEF T_MAIN T_LPAREN parameter_list T_RPAREN T_COLON var_list block  */
#line 179 "parser.y"
        {
		if(strcmp((yyvsp[-6].string), "_main_") != 0)
		{
			yyerror("Missing required function: def _main_()");
			YYABORT;
		}

		 (yyval.node) = mknode("MAIN", (yyvsp[-4].node) ,mknode("VARS",(yyvsp[-1].node), (yyvsp[0].node)));	
	}
#line 1646 "y.tab.c"
    break;

  case 11: /* function: T_DEF T_IDENTIFIER_LITERAL T_LPAREN parameter_list T_RPAREN T_COLON T_RETURNS type_ret var_list block  */
#line 192 "parser.y"
    {
        node* func = mknode("FUNC", NULL, NULL);
        func->left = mknode((yyvsp[-8].string), NULL, NULL);
        node* pars = mknode("PARS", (yyvsp[-6].node), NULL);
        char ret_str[100];
        sprintf(ret_str, "RET %s", (yyvsp[-2].node)->token);
        node* ret = mknode(ret_str, NULL, NULL);
        
        // Create single VAR node for variable declarations
        if ((yyvsp[-1].node) != NULL) {
            node* var_node = mknode("", (yyvsp[-1].node), NULL);
            var_node->right = (yyvsp[0].node);  // Connect block to VAR
            ret->right = var_node;  // Connect VAR to RET
        } else {
            ret->right = (yyvsp[0].node);
        }
        
        func->right = pars;
        pars->right = ret;
        (yyval.node) = func;
    }
#line 1672 "y.tab.c"
    break;

  case 12: /* function: T_DEF T_IDENTIFIER_LITERAL T_LPAREN parameter_list T_RPAREN T_COLON var_list block  */
#line 215 "parser.y"
    {
        node* func = mknode("FUNC", NULL, NULL);
        func->left = mknode((yyvsp[-6].string), NULL, NULL);
        node* pars = mknode("PARS", (yyvsp[-4].node), NULL);
        
        // Create single VAR node for variable declarations
        if ((yyvsp[-1].node) != NULL) {
            node* var_node = mknode("", (yyvsp[-1].node), NULL);
            var_node->right = (yyvsp[0].node);  // Connect block to VAR
            pars->right = var_node;  // Connect VAR to PARS
        } else {
            pars->right = (yyvsp[0].node);
        }
        
        func->right = pars;
        (yyval.node) = func;
    }
#line 1694 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list T_SEMICOLON parameter  */
#line 237 "parser.y"
                                         {
        // Case: We're adding a new parameter to an existing list.
        if ((yyvsp[-2].node) == NULL) {
            // If the existing list is empty, start the list with this parameter.
            (yyval.node) = (yyvsp[0].node);
        } else {
            // Traverse to the end of the current parameter list.
            node* current = (yyvsp[-2].node);
            while (current->right != NULL)
                current = current->right;

            // Append the new parameter to the end of the list.
            current->right = (yyvsp[0].node);

            // Return the head of the updated list.
            (yyval.node) = (yyvsp[-2].node);
        }
    }
#line 1717 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter  */
#line 256 "parser.y"
                {
        // Case: This is the first (and only) parameter so far.
        (yyval.node) = (yyvsp[0].node);
    }
#line 1726 "y.tab.c"
    break;

  case 15: /* parameter_list: %empty  */
#line 261 "parser.y"
                  {
        // Case: No parameters at all (e.g., empty parameter list)
        (yyval.node) = NULL;
    }
#line 1735 "y.tab.c"
    break;

  case 16: /* parameter: T_PAR_NUM type T_COLON T_IDENTIFIER_LITERAL  */
#line 269 "parser.y"
                                                {
        char param_str[100];
        sprintf(param_str, "(%s %s %s)", (yyvsp[-3].string), (yyvsp[-2].node)->token, (yyvsp[0].string));
        (yyval.node) = mknode(strdup(param_str), NULL, NULL);
    }
#line 1745 "y.tab.c"
    break;

  case 17: /* type: T_INT  */
#line 277 "parser.y"
               { (yyval.node) = mknode("INT", NULL, NULL); }
#line 1751 "y.tab.c"
    break;

  case 18: /* type: T_CHAR  */
#line 278 "parser.y"
               { (yyval.node) = mknode("CHAR", NULL, NULL); }
#line 1757 "y.tab.c"
    break;

  case 19: /* type: T_REAL  */
#line 279 "parser.y"
               { (yyval.node) = mknode("REAL", NULL, NULL); }
#line 1763 "y.tab.c"
    break;

  case 20: /* type: T_BOOL  */
#line 280 "parser.y"
               { (yyval.node) = mknode("BOOL", NULL, NULL); }
#line 1769 "y.tab.c"
    break;

  case 21: /* type: T_STRING  */
#line 281 "parser.y"
               { (yyval.node) = mknode("STRING", NULL, NULL); }
#line 1775 "y.tab.c"
    break;

  case 22: /* type: T_INTPTR  */
#line 282 "parser.y"
               { (yyval.node) = mknode("INT*", NULL, NULL); }
#line 1781 "y.tab.c"
    break;

  case 23: /* type: T_CHARPTR  */
#line 283 "parser.y"
               { (yyval.node) = mknode("CHAR*", NULL, NULL); }
#line 1787 "y.tab.c"
    break;

  case 24: /* type: T_REALPTR  */
#line 284 "parser.y"
               { (yyval.node) = mknode("REAL*", NULL, NULL); }
#line 1793 "y.tab.c"
    break;

  case 25: /* type_ret: type  */
#line 288 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1799 "y.tab.c"
    break;

  case 26: /* var_list: T_VAR var_list_inner  */
#line 294 "parser.y"
                                     { (yyval.node) = mknode("VAR", (yyvsp[0].node), NULL);}
#line 1805 "y.tab.c"
    break;

  case 27: /* var_list: %empty  */
#line 295 "parser.y"
                 { (yyval.node) = NULL; }
#line 1811 "y.tab.c"
    break;

  case 28: /* var_list_inner: var  */
#line 299 "parser.y"
                                        { (yyval.node) = (yyvsp[0].node); }
#line 1817 "y.tab.c"
    break;

  case 29: /* var_list_inner: var var_list_inner  */
#line 300 "parser.y"
                                        { 
        if ((yyvsp[0].node) == NULL) {
            (yyval.node) = (yyvsp[-1].node);
        } else {
            node* temp = mknode("", (yyvsp[-1].node), NULL);
            temp->right = (yyvsp[0].node);
            (yyval.node) = temp;
        }
    }
#line 1831 "y.tab.c"
    break;

  case 30: /* var: T_TYPE type T_COLON var_a T_SEMICOLON  */
#line 313 "parser.y"
{

  (yyval.node) = mknode((yyvsp[-3].node)->token, (yyvsp[-1].node), NULL);
}
#line 1840 "y.tab.c"
    break;

  case 31: /* var_a: T_IDENTIFIER_LITERAL T_COMMA var_a  */
#line 321 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s,%s", (yyvsp[-2].string), (yyvsp[0].node)->token);
    (yyval.node) = mknode(strdup(combined), (yyvsp[0].node), NULL);
}
#line 1850 "y.tab.c"
    break;

  case 32: /* var_a: T_IDENTIFIER_LITERAL T_COLON T_CHAR_LTL T_COMMA var_a  */
#line 328 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s=%s,%s", (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[0].node)->token);
    (yyval.node) = mknode(strdup(combined), (yyvsp[0].node), NULL);
}
#line 1860 "y.tab.c"
    break;

  case 33: /* var_a: T_IDENTIFIER_LITERAL T_COLON T_DEC_LTL T_COMMA var_a  */
#line 335 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s=%d,%s", (yyvsp[-4].string),(yyvsp[-2].intval),(yyvsp[0].node)->token);
    (yyval.node) = mknode(strdup(combined), (yyvsp[0].node), NULL);
}
#line 1870 "y.tab.c"
    break;

  case 34: /* var_a: T_IDENTIFIER_LITERAL T_LBRACKET T_DEC_LTL T_RBRACKET T_COMMA var_a  */
#line 341 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s[%d],%s", (yyvsp[-5].string), (yyvsp[-3].intval), (yyvsp[0].node)->token);
    (yyval.node) = mknode(strdup(combined), (yyvsp[0].node), NULL);
}
#line 1880 "y.tab.c"
    break;

  case 35: /* var_a: T_IDENTIFIER_LITERAL T_LBRACKET T_DEC_LTL T_RBRACKET T_COLON T_STRING_LITERAL T_COMMA var_a  */
#line 347 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s[%d]=%s, %s", (yyvsp[-7].string), (yyvsp[-5].intval), (yyvsp[-2].string), (yyvsp[0].node)->token);
    (yyval.node) = mknode(strdup(combined), (yyvsp[0].node), NULL);
}
#line 1890 "y.tab.c"
    break;

  case 36: /* var_a: T_IDENTIFIER_LITERAL  */
#line 354 "parser.y"
{	
    (yyval.node) = mknode((yyvsp[0].string), NULL, NULL);
}
#line 1898 "y.tab.c"
    break;

  case 37: /* var_a: T_IDENTIFIER_LITERAL T_COLON T_CHAR_LTL  */
#line 359 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s=%s", (yyvsp[-2].string), (yyvsp[0].string));
    (yyval.node) = mknode(strdup(combined), NULL, NULL);
}
#line 1908 "y.tab.c"
    break;

  case 38: /* var_a: T_IDENTIFIER_LITERAL T_COLON T_DEC_LTL  */
#line 366 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s=%d", (yyvsp[-2].string),(yyvsp[0].intval));
    (yyval.node) = mknode(strdup(combined), NULL, NULL);
}
#line 1918 "y.tab.c"
    break;

  case 39: /* var_a: T_IDENTIFIER_LITERAL T_LBRACKET T_DEC_LTL T_RBRACKET  */
#line 372 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s[%d]", (yyvsp[-3].string), (yyvsp[-1].intval));
    (yyval.node) = mknode(strdup(combined), NULL, NULL);
}
#line 1928 "y.tab.c"
    break;

  case 40: /* var_a: T_IDENTIFIER_LITERAL T_LBRACKET T_DEC_LTL T_RBRACKET T_COLON T_STRING_LITERAL  */
#line 378 "parser.y"
{
    char combined[256];
    sprintf(combined, "%s[%d]=%s", (yyvsp[-5].string), (yyvsp[-3].intval), (yyvsp[0].string));
    (yyval.node) = mknode(strdup(combined), NULL, NULL);
}
#line 1938 "y.tab.c"
    break;

  case 41: /* block: T_BEGIN var_list stmt_list T_END  */
#line 389 "parser.y"
                                      {
        (yyval.node) = mknode("BODY", (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1946 "y.tab.c"
    break;

  case 42: /* block: T_BEGIN var_list T_END  */
#line 392 "parser.y"
                             {
        (yyval.node) = mknode("BODY", (yyvsp[-1].node), NULL);
    }
#line 1954 "y.tab.c"
    break;

  case 43: /* block: do_while_stmt  */
#line 395 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1960 "y.tab.c"
    break;

  case 44: /* stmt_list: stmt_list stmt  */
#line 403 "parser.y"
                   {
        (yyval.node) = mknode("", (yyvsp[-1].node), (yyvsp[0].node)); 
    }
#line 1968 "y.tab.c"
    break;

  case 45: /* stmt_list: stmt  */
#line 406 "parser.y"
          {(yyval.node) = mknode("", (yyvsp[0].node), NULL);}
#line 1974 "y.tab.c"
    break;

  case 47: /* stmt: T_WHILE expr T_COLON block  */
#line 412 "parser.y"
                               {
        (yyval.node) = mknode("WHILE", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1982 "y.tab.c"
    break;

  case 48: /* stmt: T_WHILE expr T_COLON assignment_stmt  */
#line 415 "parser.y"
                                        {
        (yyval.node) = mknode("WHILE", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1990 "y.tab.c"
    break;

  case 49: /* stmt: T_FOR T_LPAREN assignment_stmt T_SEMICOLON expr T_SEMICOLON assignment_stmt T_RPAREN T_COLON block  */
#line 418 "parser.y"
                                                                                                       {
        node* for_control = mknode("FORCTRL", (yyvsp[-7].node), mknode("", (yyvsp[-5].node), (yyvsp[-3].node)));
        (yyval.node) = mknode("FOR", for_control, (yyvsp[0].node));
    }
#line 1999 "y.tab.c"
    break;

  case 50: /* stmt: T_RETURN expr T_SEMICOLON  */
#line 423 "parser.y"
                              {
        char ret_str[100];
        sprintf(ret_str, "RET %s", (yyvsp[-1].node)->token);
        (yyval.node) = mknode(ret_str, NULL, NULL);
    }
#line 2009 "y.tab.c"
    break;

  case 51: /* stmt: assignment_stmt T_SEMICOLON  */
#line 428 "parser.y"
                                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2017 "y.tab.c"
    break;

  case 52: /* stmt: call_expr T_SEMICOLON  */
#line 431 "parser.y"
                          {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2025 "y.tab.c"
    break;

  case 53: /* stmt: block  */
#line 434 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2033 "y.tab.c"
    break;

  case 54: /* stmt: function_list  */
#line 437 "parser.y"
                  {(yyval.node)=(yyvsp[0].node);}
#line 2039 "y.tab.c"
    break;

  case 55: /* stmt: do_while_stmt  */
#line 439 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2045 "y.tab.c"
    break;

  case 56: /* do_while_stmt: T_DO T_COLON var_list block T_WHILE expr T_SEMICOLON  */
#line 445 "parser.y"
    {
        node* do_node = mknode("", (yyvsp[-4].node), (yyvsp[-3].node));     // var_list and block
        (yyval.node) = mknode("DOWHILE", do_node, (yyvsp[-1].node));      // whole do-while
    }
#line 2054 "y.tab.c"
    break;

  case 57: /* if_stmt: T_IF expr T_COLON suite elif_list else_clause  */
#line 454 "parser.y"
{
        node* if_node = mknode("IF", (yyvsp[-4].node), (yyvsp[-2].node)); // (IF condition, suite)
        
        // Combine IF and ELIFs if present
        node* full_if = if_node;
        if ((yyvsp[-1].node)) {
            full_if = mknode("IF-CHAIN", if_node, (yyvsp[-1].node)); // (IF-CHAIN if, elif list)
        }

        // Combine with ELSE if present
        if ((yyvsp[0].node)) {
            (yyval.node) = mknode("IF-ELSE", full_if, (yyvsp[0].node)); // (IF-ELSE <if+elif>, else)
        } else {
            (yyval.node) = full_if;
        }
    }
#line 2075 "y.tab.c"
    break;

  case 58: /* elif_list: %empty  */
#line 473 "parser.y"
                { (yyval.node) = NULL; }
#line 2081 "y.tab.c"
    break;

  case 59: /* elif_list: elif_list T_ELIF expr T_COLON suite  */
#line 474 "parser.y"
                                        {
        node* elif_node = mknode("ELIF", (yyvsp[-2].node), (yyvsp[0].node));
        if ((yyvsp[-4].node)) {
            (yyval.node) = mknode("ELIF-CHAIN", (yyvsp[-4].node), elif_node);
        } else {
            (yyval.node) = elif_node;
        }
    }
#line 2094 "y.tab.c"
    break;

  case 60: /* else_clause: %empty  */
#line 485 "parser.y"
                { (yyval.node) = NULL; }
#line 2100 "y.tab.c"
    break;

  case 61: /* else_clause: T_ELSE T_COLON suite  */
#line 486 "parser.y"
                         { (yyval.node) = mknode("ELSE", (yyvsp[0].node), NULL); }
#line 2106 "y.tab.c"
    break;

  case 64: /* assignment_stmt: lhs T_ASSIGNMENT expr  */
#line 498 "parser.y"
                          {
        (yyval.node) = mknode("=", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2114 "y.tab.c"
    break;

  case 65: /* lhs: T_IDENTIFIER_LITERAL  */
#line 505 "parser.y"
    {
        (yyval.node) = mknode((yyvsp[0].string), NULL, NULL);
    }
#line 2122 "y.tab.c"
    break;

  case 66: /* lhs: T_IDENTIFIER_LITERAL T_LBRACKET expr T_RBRACKET  */
#line 509 "parser.y"
    {
        (yyval.node) = mknode((yyvsp[-3].string), mknode("[", (yyvsp[-1].node), mknode("]", NULL, NULL)), NULL);
    }
#line 2130 "y.tab.c"
    break;

  case 67: /* call_expr: T_CALL T_IDENTIFIER_LITERAL T_LPAREN expr_list T_RPAREN  */
#line 516 "parser.y"
                                                            {
        node* call = mknode("CALL", NULL, NULL);
        call->left = mknode((yyvsp[-3].string), NULL, NULL);
        if ((yyvsp[-1].node)) {
            call->right = (yyvsp[-1].node);
        }
        (yyval.node) = call;
    }
#line 2143 "y.tab.c"
    break;

  case 68: /* expr_list: expr  */
#line 527 "parser.y"
         {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2151 "y.tab.c"
    break;

  case 69: /* expr_list: expr T_COMMA expr_list  */
#line 530 "parser.y"
                             {
        (yyval.node) = mknode("", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2159 "y.tab.c"
    break;

  case 70: /* expr_list: %empty  */
#line 533 "parser.y"
                  {
        (yyval.node) = NULL;
    }
#line 2167 "y.tab.c"
    break;

  case 71: /* expr: expr T_PLUS expr  */
#line 544 "parser.y"
                           { (yyval.node) = mknode("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2173 "y.tab.c"
    break;

  case 72: /* expr: expr T_MINUS expr  */
#line 545 "parser.y"
                           { (yyval.node) = mknode("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2179 "y.tab.c"
    break;

  case 73: /* expr: expr T_STAR expr  */
#line 546 "parser.y"
                           { (yyval.node) = mknode("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2185 "y.tab.c"
    break;

  case 74: /* expr: expr T_DIVISION expr  */
#line 547 "parser.y"
                           { (yyval.node) = mknode("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2191 "y.tab.c"
    break;

  case 75: /* expr: expr T_EQL expr  */
#line 549 "parser.y"
                           { (yyval.node) = mknode("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2197 "y.tab.c"
    break;

  case 76: /* expr: expr T_NOTEQL expr  */
#line 550 "parser.y"
                           { (yyval.node) = mknode("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2203 "y.tab.c"
    break;

  case 77: /* expr: expr T_GREATER expr  */
#line 551 "parser.y"
                           { (yyval.node) = mknode(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2209 "y.tab.c"
    break;

  case 78: /* expr: expr T_GREATEREQL expr  */
#line 552 "parser.y"
                           { (yyval.node) = mknode(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2215 "y.tab.c"
    break;

  case 79: /* expr: expr T_LESS expr  */
#line 553 "parser.y"
                           { (yyval.node) = mknode("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2221 "y.tab.c"
    break;

  case 80: /* expr: expr T_LESSEQL expr  */
#line 554 "parser.y"
                           { (yyval.node) = mknode("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2227 "y.tab.c"
    break;

  case 81: /* expr: expr T_AND expr  */
#line 556 "parser.y"
                           { (yyval.node) = mknode("&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2233 "y.tab.c"
    break;

  case 82: /* expr: expr T_OR expr  */
#line 557 "parser.y"
                           { (yyval.node) = mknode("||", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2239 "y.tab.c"
    break;

  case 83: /* expr: T_NOT expr  */
#line 559 "parser.y"
                           { (yyval.node) = mknode("!", (yyvsp[0].node), NULL); }
#line 2245 "y.tab.c"
    break;

  case 84: /* expr: T_ADDRESS expr  */
#line 560 "parser.y"
                           { (yyval.node) = mknode("&", (yyvsp[0].node), NULL); }
#line 2251 "y.tab.c"
    break;

  case 85: /* expr: T_STAR expr  */
#line 561 "parser.y"
                           { (yyval.node) = mknode("DEREF", (yyvsp[0].node), NULL); }
#line 2257 "y.tab.c"
    break;

  case 86: /* expr: T_LENGTH expr T_LENGTH  */
#line 562 "parser.y"
                           { (yyval.node) = mknode("LENGTH", (yyvsp[-1].node), NULL); }
#line 2263 "y.tab.c"
    break;

  case 87: /* expr: T_LPAREN expr T_RPAREN  */
#line 564 "parser.y"
                             { (yyval.node) = mknode("()", (yyvsp[-1].node), NULL); }
#line 2269 "y.tab.c"
    break;

  case 88: /* expr: T_IDENTIFIER_LITERAL T_LBRACKET expr T_RBRACKET  */
#line 566 "parser.y"
                                                    {
        (yyval.node) = mknode((yyvsp[-3].string), mknode("[", (yyvsp[-1].node), mknode("]", NULL, NULL)), NULL);
    }
#line 2277 "y.tab.c"
    break;

  case 89: /* expr: T_IDENTIFIER_LITERAL T_LPAREN expr T_RPAREN  */
#line 569 "parser.y"
                                                {
        (yyval.node) = mknode((yyvsp[-3].string), mknode("(", (yyvsp[-1].node), mknode(")", NULL, NULL)), NULL);
    }
#line 2285 "y.tab.c"
    break;

  case 90: /* expr: T_IDENTIFIER_LITERAL  */
#line 574 "parser.y"
                           { (yyval.node) = mknode((yyvsp[0].string), NULL, NULL); }
#line 2291 "y.tab.c"
    break;

  case 91: /* expr: T_NUMBER  */
#line 575 "parser.y"
                           { (yyval.node) = mknode((yyvsp[0].string), NULL, NULL); }
#line 2297 "y.tab.c"
    break;

  case 92: /* expr: T_DEC_LTL  */
#line 576 "parser.y"
                           { char temp[20]; sprintf(temp, "%d", (yyvsp[0].intval)); (yyval.node) = mknode(strdup(temp), NULL, NULL); }
#line 2303 "y.tab.c"
    break;

  case 93: /* expr: T_HEX_LTL  */
#line 577 "parser.y"
                           { (yyval.node) = mknode((yyvsp[0].string), NULL, NULL); }
#line 2309 "y.tab.c"
    break;

  case 94: /* expr: T_REAL_LTL  */
#line 578 "parser.y"
                           { (yyval.node) = mknode((yyvsp[0].string), NULL, NULL); }
#line 2315 "y.tab.c"
    break;

  case 95: /* expr: T_CHAR_LTL  */
#line 579 "parser.y"
                           { (yyval.node) = mknode((yyvsp[0].string), NULL, NULL); }
#line 2321 "y.tab.c"
    break;

  case 96: /* expr: T_STRING_LITERAL  */
#line 580 "parser.y"
                           { (yyval.node) = mknode((yyvsp[0].string), NULL, NULL); }
#line 2327 "y.tab.c"
    break;

  case 97: /* expr: T_TRUE  */
#line 581 "parser.y"
                           { (yyval.node) = mknode("true", NULL, NULL); }
#line 2333 "y.tab.c"
    break;

  case 98: /* expr: T_FALSE  */
#line 582 "parser.y"
                           { (yyval.node) = mknode("false", NULL, NULL); }
#line 2339 "y.tab.c"
    break;

  case 99: /* expr: T_NULL  */
#line 583 "parser.y"
                          { (yyval.node) = mknode("null", NULL, NULL); }
#line 2345 "y.tab.c"
    break;

  case 101: /* expr: %empty  */
#line 585 "parser.y"
                { (yyval.node) = NULL;}
#line 2351 "y.tab.c"
    break;


#line 2355 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 589 "parser.y"

#include "lex.yy.c"

int main()
{
    globalScope = createScope(NULL);
    return yyparse();
}

void printtree(node *root, int indent)
{
    if(!root || semantic_error==1)
        return;
        
    // Print indentation
    for(int i=0;i<indent;i++)
        printf(" ");
    
    // Special case for function name (no parentheses)
    if(root->token && (root->token[0] >= 'a' && root->token[0] <= 'z')) {
        printf("%s\n", root->token);
        if(root->right) {
            printtree(root->right, indent);
        }
        return;
    }
    
    // Special handling for assignment (=)
    if(strcmp(root->token, "=") == 0) {
        printf("(= %s\n", root->left->token);
        if(root->right) {
            printtree(root->right, indent+2);
        }
        for(int i=0;i<indent;i++) printf(" ");
        printf(")\n");
        return;
    }
    
    // Special handling for arithmetic operators (+, -, *, /)
    if(strcmp(root->token, "+") == 0 || 
       strcmp(root->token, "-") == 0 ||
       strcmp(root->token, "*") == 0 || 
       strcmp(root->token, "/") == 0) {
        printf("(%s", root->token);
        if(root->left && root->right) {
            printf(" %s %s", root->left->token, root->right->token);
        }
        printf(")\n");
        return;
    }
    
    // Special handling for comparison operators
    if(strcmp(root->token, ">") == 0 || 
       strcmp(root->token, "<") == 0 ||
       strcmp(root->token, ">=") == 0 || 
       strcmp(root->token, "<=") == 0 ||
       strcmp(root->token, "==") == 0 ||
       strcmp(root->token, "!=") == 0) {
        printf("(%s %s %s)\n", root->token, root->left->token, root->right->token);
        return;
    }


    


if (strcmp(root->token, "DOWHILE") == 0) {
    printf("(DOWHILE\n");

    // Print the DO body
    for (int i = 0; i < indent + 4; i++) printf(" ");
   printf("(DO\n"); 
    printtree(root->left, indent + 8);  // body
    for (int i = 0; i < indent + 4; i++) printf(" ");
    printf(")\n");

    // Print the WHILE condition
    for (int i = 0; i < indent + 4; i++) printf(" ");
    printf("(WHILE\n");
    printtree(root->right, indent + 8);  // condition
    for (int i = 0; i < indent + 4; i++) printf(" ");
    printf(")\n");

    for (int i = 0; i < indent; i++) printf(" ");
    printf(")\n");
    return;
}

    
    // Special handling for IF-ELSE
  if (strcmp(root->token, "IF-ELSE") == 0) {
    printf("(IF-ELSE\n");

    // Print the IF or IF-CHAIN part
//  for (int i = 0; i < indent + 4; i++) printf(" ");
    printtree(root->left, indent + 4);

    // Print the ELSE part if it exists
    if (root->right && strcmp(root->right->token, "ELSE") == 0) {
        for (int i = 0; i < indent + 4; i++) printf(" ");
        printf("(ELSE\n");

        if (root->right->left) {
            printtree(root->right->left, indent + 8);
        }

        for (int i = 0; i < indent + 4; i++) printf(" ");
        printf(")\n");
    }

    for (int i = 0; i < indent; i++) printf(" ");
    printf(")\n");
    return;
}

    
    // Print opening parenthesis and token
    printf("(%s", root->token);

    // Special handling for PARS node to print each parameter in a row
if (strcmp(root->token, "PARS") == 0) {
    printf("\n");

    // Traverse the parameter list stored in left-linked chain
    node* param = root->left;
    while (param) {
        for (int i = 0; i < indent + 4; i++) printf(" ");
        printf("%s\n", param->token);
        param = param->right;
    }

    // After printing parameters, print the rest (like VAR or BODY)
    if (root->right) {
        printtree(root->right, indent + 4);
    }

    // Closing ) for PARS
    for (int i = 0; i < indent; i++) printf(" ");
    printf(")\n");
    return;
}

    
    // Special handling for empty BODY
    if(strcmp(root->token, "BODY") == 0 && !root->left && !root->right) {
        printf(")\n");
        return;
    }
    
    // Special handling for CALL
    if(strcmp(root->token, "CALL") == 0) {
        printf(" %s", root->left->token);
        if(root->right) {
            printf(" ");
            print_args(root->right);
        }
        printf(")\n");
        return;
    }
    
    // If no children and not BODY, close parenthesis on same line
    if(!root->left && !root->right) {
        printf(")\n");
        return;
    }
    
    printf("\n");
    
    // Print children
    if(root->left) {
        printtree(root->left, indent+4);
    }
    if(root->right) {
        printtree(root->right, indent+4);
    }
    
    // Print closing parenthesis for block structures
    if(strcmp(root->token, "CODE") == 0 || 
       strcmp(root->token, "FUNC") == 0 || 
       strcmp(root->token, "PARS") == 0 || 
       strcmp(root->token, "BODY") == 0 ||
       strcmp(root->token, "VAR") == 0) {
        for(int i=0;i<indent;i++)
            printf(" ");
        printf(")\n");
    }
}

void print_args(node *args)
{
    if(!args)
        return;
    
    if(args->token && strlen(args->token) > 0)
        printf("%s", args->token);
    else {
        if(args->left)
            print_args(args->left);
        if(args->right) {
            printf(", ");
            print_args(args->right);
        }
    }
}

int yyerror(char *e)
{
    int yydebug=1;
    fflush(stdout);
    if(strcmp(yytext, "_main_")==0)
         printf("Semantic Error (code 1): multiple definitions of 'main' function\n");
    else
        {fprintf(stderr,"ERROR:%s at line %d\n",e,yylineno);
        fprintf(stderr,"Token: '%s'\n",yytext);}
    return 0;
}

node *mknode(char *token,node *left,node *right)
{
    node *newnode =(node*)malloc(sizeof(node));
    char *newstr =(char*)malloc(strlen(token)+1);
    strcpy(newstr,token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return newnode;
}



// === Function to search for a symbol in scope or any parent scopes ===
Link *findSymbol(Scope *scope, char *name) {
    while (scope) {
        for (Link *l = scope->first; l != NULL; l = l->next) {
            if (strcmp(l->name, name) == 0)
                return l;
        }
        scope = scope->father;
    }
    return NULL;
}

// Check if identifier is declared in the current scope
int isDeclaredInScope(Scope* scope, const char* name) {
    Link* curr = scope->first;
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int isDeclaredInFatherScope(Scope* scope, const char* name) {
    Link* curr = scope->father;
    
    while (curr) {
        for (Link *l = scope->first; l != NULL; l = l->next)
        {
            if (strcmp(l->name, name) == 0)
                return l;
        }
        curr = scope -> father; 
    }
    return 0;
}

// === Recursive function to build symbol tables by traversing AST ===
void buildSymbolTable(node *n, Scope *currentScope) {
    if (!n) return;

    if (strcmp(n->token, "DEREF") == 0)    // לא להתייחס, זה כדי להזכיר לי (קטורה) איפה אני 
    {
       
    }

    // Handle function definitions
    if (strcmp(n->token, "FUNC") == 0) {
        char *funcName = n->left->token;  // function name is in left
        addSymbol(currentScope, funcName, "function");

        Scope *funcScope = createScope(currentScope);  // new scope for function

        node *pars = n->right;  // points to PARS node
        node *ret = pars->right;  // RET node

        // Handle parameters under PARS
        node *param = pars->left;
        while (param) {
            addSymbol(funcScope, param->token, "param");  // parameter name
            param = param->right;
        }

        // Handle declared variables and block
        node *body = ret->right;
        node *vars = NULL;

        if (body && body->left) {  // vars exist
            vars = body->left;
        }

        node *block = (body && body->right) ? body->right : NULL;

        // Add variables to function scope
        while (vars) {
            addSymbol(funcScope, vars->token, "var");
            vars = vars->right;
        }

        buildSymbolTable(block, funcScope);  // go into block body
    }

    // Handle main function
    else if (strcmp(n->token, "MAIN") == 0)
    {
        addSymbol(currentScope, "_main_", "void");

        Scope *mainScope = createScope(currentScope);

        buildSymbolTable(n->right, mainScope);   // var_list
        buildSymbolTable(n->right->right, mainScope);  // block
    }

    else if(strcmp(n->token, "VARS") == 0)
    {
        while(n->left != NULL)
        {
            printf("%s %s",n->left->left->left->token,n->left->left->token);
            addSymbol(currentScope,n->left->left->left->token,n->left->left->token);
        }

    }

        else if(strcmp(n->token, "BODY") == 0)
    {
        //?????
    }
    

    // Handle nested nodes (traverse the whole tree)
    buildSymbolTable(n->left, currentScope);
    buildSymbolTable(n->right, currentScope);
}



// === Function to count number of MAIN nodes in the AST ===
void checkMainExists(node *n) {
    if (!n) return;

    if (strcmp(n->token, "MAIN") == 0)
        MAIN_COUNT++;

    checkMainExists(n->left);
    checkMainExists(n->right);
}



/*parameter:
    T_PAR_NUM type T_COLON T_IDENTIFIER_LITERAL {
        char param_str[100];
        sprintf(param_str, "(%s %s %s)", $1, $2->token, $4);
        $$ = mknode(param_str, NULL, NULL);
    }
;*/

// Helper function to process parameters in correct order
void processFunctionParams(node* parsNode, Scope* funcScope) {
   
 
    node* param = parsNode->left;  // Start with the first parameter
 
    int expectedParNum = 1;

    while (param) {
        int actualParNum;
        char type[50], name[50];

        // Parse string like "(par1 INT x)"
        if (sscanf(param->token, "(par%d %s %s)", &actualParNum, type, name) == 3) {
            if (actualParNum != expectedParNum) {
                printf("Semantic Error (code 8): Parameter order mismatch. Expected par%d, got par%d\n ", expectedParNum, actualParNum);
                semantic_error = 1;
            }

            // Add parameter name (e.g., "x") to the symbol table
            addSymbol(funcScope, name, "param");
        }
         else {
            printf("Semantic Error: Invalid parameter format: %s\n", param->token);
            semantic_error = 1;
        }

        param = param->right;
        expectedParNum++;
    }
}

// Recursive semantic analysis of the AST
void traverseAST(node* n, Scope* currentScope) {
    if (!n) return;
    
    // Handle function definition node
    if (strcmp(n->token, "FUNC") == 0) {
        char* funcName = n->left->token;

        // Check for duplicate function names in current scope
        if (isDeclaredInScope(currentScope, funcName)) {
            printf("Semantic Error (code 3): Function '%s' already declared in this scope\n", funcName);
            exit(1);
        } else {
            addSymbol(currentScope, funcName, "function");
        }

        // Create a new scope for the function body
        Scope* funcScope = (Scope*)malloc(sizeof(Scope));
        funcScope->father = currentScope;
        funcScope->first = NULL;

        node* pars = n->right;          // PARS node
        node* ret = pars->right;        // RET/VAR/BLOCK node

        // Add parameters to function scope, checking for correct order
        processFunctionParams(pars, funcScope);

        // Add variables to function scope
        node* varBlock = ret->right;
        if (varBlock && strcmp(varBlock->token, "") == 0) {
            node* varDecl = varBlock->left;
            while (varDecl) {
                addSymbol(funcScope, varDecl->token, "var");
                varDecl = varDecl->right;
            }
            traverseAST(varBlock->right, funcScope);  // Traverse function block
        } else {
            traverseAST(varBlock, funcScope);  // Traverse block directly if no var node
        }
    }

    // Count main definitions
    else if (strcmp(n->token, "MAIN") == 0) {
        MAIN_COUNT++;
        if (MAIN_COUNT > 1)
        {
            printf("Semantic Error (code 1): multiple definitions of 'main' function\n");
            exit(1);
        }
        if(n->left != NULL)
        {   
            printf("Semantic Error (code 2):-------------------------------------------\n");
            exit(1);
        }
    }
     else if(strcmp(n->token,"CALL")==0)
    {
        if(!isDeclaredInFatherScope(currentScope,n->left->token))
        {
            printf("Semantic Error (code 5): ---------------------------\n");
            exit(1);
        }
        
    }

    else if(strcmp(n->token,"=")==0)
    {
        if(!isDeclaredInScope(currentScope,n->left->token))
        {
            printf("not in current scope");
            if(!isDeclaredInFatherScope(currentScope,n->left->token))
            {
                printf("Semantic Error (code 6): ---------------------------\n");
                exit(1);
            }
        }

    }

    // Continue traversal
    traverseAST(n->left, currentScope);
    traverseAST(n->right, currentScope);
}

// Semantic analysis entry point
void semanticAnalyzer(node* ast) {
    globalScope = (Scope*)malloc(sizeof(Scope));
    globalScope->father = NULL;
    globalScope->first = NULL;

    traverseAST(ast, globalScope);

    if (MAIN_COUNT == 0)
        printf("Semantic Error (code 1): 'main' function not defined\n");
    else       
        printf("Semantic OK\n");
   
}
