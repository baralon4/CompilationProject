%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%option yylineno
%x COMMENT_MODE
%%

"#->" { BEGIN(COMMENT_MODE); }                      // Start comment mode
<COMMENT_MODE>"<-#" { BEGIN(INITIAL); }             // End comment mode
<COMMENT_MODE>\n   { yylineno++; }                  // Still count newlines inside comment
<COMMENT_MODE>.    ;                               //Ignore anything inside comment


[ \t\r\n]+ ;
bool	{ return T_BOOL; }
char	{ return T_CHAR; }
int	{ return T_INT; }
real	{ return T_REAL; }
string	{ return T_STRING; }
int\*	{ return T_INTPTR; }
char\*	{ return T_CHARPTR; }
real\*  { return T_REALPTR; }
if      { return T_IF; }
elif    { return T_ELIF; }
else    { return T_ELSE; }
while     { return T_WHILE; }
for       { return T_FOR; }
var       { return T_VAR; }
par[0-9]+ { yylval.string=strdup(yytext); return T_PAR_NUM; }
return    { return T_RETURN; }
null      { return T_NULL; }
do        { return T_DO; }
returns   { return T_RETURNS; }
begin     { return T_BEGIN; }
end       { return T_END; }
def       { return T_DEF; }
call      { return T_CALL; }
and       { return T_AND; }
not       { return T_NOT; }
or        { return T_OR; }
_main_	  { yylval.string = strdup(yytext); return T_MAIN; }
type      { return T_TYPE; }
"/"       { return T_DIVISION; }
"="       { return T_ASSIGNMENT; }
"=="      { return T_EQL; }
">"       { return T_GREATER; }
">="      { return T_GREATEREQL; }
"<"       { return T_LESS; }
"<="      { return T_LESSEQL; }
"-"       { return T_MINUS; }
"!="      { return T_NOTEQL; }
"+"       { return T_PLUS; }
"*"       { return T_STAR; }
"&"       { return T_ADDRESS; }
"("       { return T_LPAREN; }
")"       { return T_RPAREN; }
":"       { return T_COLON; }
";"       { return T_SEMICOLON; }
","	  { return T_COMMA; }
"["	  { return T_LBRACKET; }
"]"	  { return T_RBRACKET; } 
"|"   { return T_LENGTH; } 


true      { return T_TRUE; }
false     { return T_FALSE; }

[\n] {yylineno++; }


0|[1-9][0-9]*   { yylval.intval=atoi(yytext); return T_DEC_LTL;}


'[a-zA-Z]' { yylval.string = strdup(yytext); return T_CHAR_LTL;}


0(x|X)[0-9A-F]+ { yylval.string = strdup(yytext); return T_HEX_LTL;}



[-+]?[0-9]*\.?[0-9]*[eE]?[-+]?[0-9]+ {yylval.string= strdup(yytext); return T_REAL_LTL;}


\"([^\"\n]|\\n)*\"   { yylval.string = strdup(yytext); return T_STRING_LITERAL;}


[a-zA-Z][a-zA-Z0-9_]*     { yylval.string = strdup(yytext); return T_IDENTIFIER_LITERAL;}








.   { printf("Error: Unrecognized char '%c' at line %d\n", yytext[0],yylineno); return yytext[0];}



%%