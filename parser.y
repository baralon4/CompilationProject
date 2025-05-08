%{
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
%}

%union {
	struct node *node;
	char* string;
	int intval;
	

}

%token T_BOOL T_CHAR T_INT T_REAL T_STRING
%token T_INTPTR T_CHARPTR T_REALPTR
%token T_IF T_ELIF T_ELSE T_WHILE T_FOR T_DO
%token T_VAR T_RETURNS T_RETURN T_NULL T_CALL T_TYPE
%token T_BEGIN T_END T_DEF 
%token T_AND T_NOT T_OR
%token T_DIVISION T_ASSIGNMENT T_EQL T_GREATER T_GREATEREQL T_LESS T_LESSEQL T_MINUS T_NOTEQL T_PLUS T_STAR T_ADDRESS
%token T_TRUE T_FALSE
%token T_LBRACKET T_RBRACKET
%token <string> T_CHAR_LTL T_HEX_LTL T_REAL_LTL T_STRING_LITERAL T_PAR_NUM
%token <intval>  T_DEC_LTL
%token <string> T_IDENTIFIER_LITERAL
%token T_COMMENT
%token <string> T_NUMBER
%token T_LPAREN T_RPAREN
%token T_COLON
%token T_SEMICOLON
%token T_COMMA
%token <string> T_MAIN
%token T_LENGTH




%left T_OR T_AND
%left T_EQL T_NOTEQL T_GREATER T_GREATEREQL T_LESS T_LESSEQL
%left T_PLUS T_MINUS
%left T_STAR T_DIVISION

%right T_NOT 

%nonassoc T_IF
%nonassoc T_ELSE

%type <node> stmt
%type <node> program function main function_list
%type <node> type type_ret
%type <node> block stmt_list expr expr_list lhs call_expr do_while_stmt
%type <node> assignment_stmt
%type <node> parameter_list
%type <node> parameter 
%type <node> var_list var_list_inner var
%type <node> var_a
%type <node> if_stmt elif_list else_clause suite


%%
s:
	program {
		semanticAnalyzer($1);
		if (!semantic_error) {
			printtree($1, 0);
			printf("syntax valid\n");
		}
	}
;

program:
	 function_list main function_list 
	{
		$$=mknode("CODE",$1,$2);
	}
   
    |
    main function_list
    {
        $$=mknode("CODE",$1,NULL);
    }

    |

    main
    {
        $$=mknode("CODE",$1,NULL);
    }
     
    |

    function_list
    {
        $$=mknode("CODE",$1,NULL);
    } 


function_list:
	function_list function
	{
		$$=mknode("",$1,$2);
	}
	| function {$$=mknode("",$1,NULL);}
	| /* empty */ { $$ = NULL; } 
;

main:
	T_DEF T_MAIN T_LPAREN parameter_list T_RPAREN T_COLON var_list block
	{
		if(strcmp($2, "_main_") != 0)
		{
			yyerror("Missing required function: def _main_()");
			YYABORT;
		}

		 $$ = mknode("MAIN", $4 ,mknode("VARS",$7, $8));	
	}
;

function:
    T_DEF T_IDENTIFIER_LITERAL T_LPAREN parameter_list T_RPAREN T_COLON T_RETURNS type_ret var_list block
    {
        node* func = mknode("FUNC", NULL, NULL);
        func->left = mknode($2, NULL, NULL);
        node* pars = mknode("PARS", $4, NULL);
        char ret_str[100];
        sprintf(ret_str, "RET %s", $8->token);
        node* ret = mknode(ret_str, NULL, NULL);
        
        // Create single VAR node for variable declarations
        if ($9 != NULL) {
            node* var_node = mknode("", $9, NULL);
            var_node->right = $10;  // Connect block to VAR
            ret->right = var_node;  // Connect VAR to RET
        } else {
            ret->right = $10;
        }
        
        func->right = pars;
        pars->right = ret;
        $$ = func;
    }
    |
    T_DEF T_IDENTIFIER_LITERAL T_LPAREN parameter_list T_RPAREN T_COLON var_list block
    {
        node* func = mknode("FUNC", NULL, NULL);
        func->left = mknode($2, NULL, NULL);
        node* pars = mknode("PARS", $4, NULL);
        
        // Create single VAR node for variable declarations
        if ($7 != NULL) {
            node* var_node = mknode("", $7, NULL);
            var_node->right = $8;  // Connect block to VAR
            pars->right = var_node;  // Connect VAR to PARS
        } else {
            pars->right = $8;
        }
        
        func->right = pars;
        $$ = func;
    }
;



parameter_list:
    parameter_list T_SEMICOLON parameter {
        // Case: We're adding a new parameter to an existing list.
        if ($1 == NULL) {
            // If the existing list is empty, start the list with this parameter.
            $$ = $3;
        } else {
            // Traverse to the end of the current parameter list.
            node* current = $1;
            while (current->right != NULL)
                current = current->right;

            // Append the new parameter to the end of the list.
            current->right = $3;

            // Return the head of the updated list.
            $$ = $1;
        }
    }

    | parameter {
        // Case: This is the first (and only) parameter so far.
        $$ = $1;
    }

    | /* empty */ {
        // Case: No parameters at all (e.g., empty parameter list)
        $$ = NULL;
    }
;


parameter:
    T_PAR_NUM type T_COLON T_IDENTIFIER_LITERAL {
        char param_str[100];
        sprintf(param_str, "(%s %s %s)", $1, $2->token, $4);
        $$ = mknode(strdup(param_str), NULL, NULL);
    }
;

type:
    T_INT      { $$ = mknode("INT", NULL, NULL); }
  | T_CHAR     { $$ = mknode("CHAR", NULL, NULL); }
  | T_REAL     { $$ = mknode("REAL", NULL, NULL); }
  | T_BOOL     { $$ = mknode("BOOL", NULL, NULL); }
  | T_STRING   { $$ = mknode("STRING", NULL, NULL); }
  | T_INTPTR   { $$ = mknode("INT*", NULL, NULL); }
  | T_CHARPTR  { $$ = mknode("CHAR*", NULL, NULL); }
  | T_REALPTR  { $$ = mknode("REAL*", NULL, NULL); }
;

type_ret:
    type { $$ = $1; }
;



var_list:
    T_VAR var_list_inner             { $$ = mknode("VAR", $2, NULL);} 
   | /* empty */ { $$ = NULL; }
;

var_list_inner:
    var                                 { $$ = $1; }
    | var var_list_inner                { 
        if ($2 == NULL) {
            $$ = $1;
        } else {
            node* temp = mknode("", $1, NULL);
            temp->right = $2;
            $$ = temp;
        }
    }
;

var:
T_TYPE type T_COLON var_a T_SEMICOLON
{

  $$ = mknode($2->token, $4, NULL);
}
;

var_a:
T_IDENTIFIER_LITERAL T_COMMA var_a
{
    char combined[256];
    sprintf(combined, "%s,%s", $1, $3->token);
    $$ = mknode(strdup(combined), $3, NULL);
}
|
T_IDENTIFIER_LITERAL T_COLON T_CHAR_LTL T_COMMA var_a
{
    char combined[256];
    sprintf(combined, "%s=%s,%s", $1,$3,$5->token);
    $$ = mknode(strdup(combined), $5, NULL);
}
|
T_IDENTIFIER_LITERAL T_COLON T_DEC_LTL T_COMMA var_a
{
    char combined[256];
    sprintf(combined, "%s=%d,%s", $1,$3,$5->token);
    $$ = mknode(strdup(combined), $5, NULL);
}
| T_IDENTIFIER_LITERAL T_LBRACKET T_DEC_LTL T_RBRACKET T_COMMA var_a
{
    char combined[256];
    sprintf(combined, "%s[%d],%s", $1, $3, $6->token);
    $$ = mknode(strdup(combined), $6, NULL);
}
|T_IDENTIFIER_LITERAL T_LBRACKET T_DEC_LTL T_RBRACKET T_COLON T_STRING_LITERAL T_COMMA var_a
{
    char combined[256];
    sprintf(combined, "%s[%d]=%s, %s", $1, $3, $6, $8->token);
    $$ = mknode(strdup(combined), $8, NULL);
}
|
T_IDENTIFIER_LITERAL
{	
    $$ = mknode($1, NULL, NULL);
}
|
T_IDENTIFIER_LITERAL T_COLON T_CHAR_LTL 
{
    char combined[256];
    sprintf(combined, "%s=%s", $1, $3);
    $$ = mknode(strdup(combined), NULL, NULL);
}
|
T_IDENTIFIER_LITERAL T_COLON T_DEC_LTL 
{
    char combined[256];
    sprintf(combined, "%s=%d", $1,$3);
    $$ = mknode(strdup(combined), NULL, NULL);
}
| T_IDENTIFIER_LITERAL T_LBRACKET T_DEC_LTL T_RBRACKET
{
    char combined[256];
    sprintf(combined, "%s[%d]", $1, $3);
    $$ = mknode(strdup(combined), NULL, NULL);
}
|T_IDENTIFIER_LITERAL T_LBRACKET T_DEC_LTL T_RBRACKET T_COLON T_STRING_LITERAL
{
    char combined[256];
    sprintf(combined, "%s[%d]=%s", $1, $3, $6);
    $$ = mknode(strdup(combined), NULL, NULL);
}
;




block:
     T_BEGIN var_list stmt_list T_END {
        $$ = mknode("BODY", $2, $3);
    }
    | T_BEGIN var_list T_END {
        $$ = mknode("BODY", $2, NULL);
    }
    | do_while_stmt { $$ = $1; }

;




stmt_list:
    stmt_list stmt {
        $$ = mknode("", $1, $2); 
    }
  |  stmt {$$ = mknode("", $1, NULL);}
;


stmt:
   if_stmt
  | T_WHILE expr T_COLON block {
        $$ = mknode("WHILE", $2, $4);
    }
 | T_WHILE expr T_COLON assignment_stmt {
        $$ = mknode("WHILE", $2, $4);
    }
  | T_FOR T_LPAREN assignment_stmt T_SEMICOLON expr T_SEMICOLON assignment_stmt T_RPAREN T_COLON block {
        node* for_control = mknode("FORCTRL", $3, mknode("", $5, $7));
        $$ = mknode("FOR", for_control, $10);
    }
 
  | T_RETURN expr T_SEMICOLON {
        char ret_str[100];
        sprintf(ret_str, "RET %s", $2->token);
        $$ = mknode(ret_str, NULL, NULL);
    }
  | assignment_stmt T_SEMICOLON {
        $$ = $1;
    }
  | call_expr T_SEMICOLON {
        $$ = $1;
    }
  | block {
        $$ = $1;
    }
  | function_list {$$=$1;}
  
  | do_while_stmt { $$ = $1; }

 ;

do_while_stmt:
    T_DO T_COLON var_list block T_WHILE expr T_SEMICOLON
    {
        node* do_node = mknode("", $3, $4);     // var_list and block
        $$ = mknode("DOWHILE", do_node, $6);      // whole do-while
    }
;


if_stmt:
    T_IF expr T_COLON suite elif_list else_clause
{
        node* if_node = mknode("IF", $2, $4); // (IF condition, suite)
        
        // Combine IF and ELIFs if present
        node* full_if = if_node;
        if ($5) {
            full_if = mknode("IF-CHAIN", if_node, $5); // (IF-CHAIN if, elif list)
        }

        // Combine with ELSE if present
        if ($6) {
            $$ = mknode("IF-ELSE", full_if, $6); // (IF-ELSE <if+elif>, else)
        } else {
            $$ = full_if;
        }
    }
;

elif_list:
    /* empty */ { $$ = NULL; }
  | elif_list T_ELIF expr T_COLON suite {
        node* elif_node = mknode("ELIF", $3, $5);
        if ($1) {
            $$ = mknode("ELIF-CHAIN", $1, elif_node);
        } else {
            $$ = elif_node;
        }
    }
;

else_clause:
    /* empty */ { $$ = NULL; }
  | T_ELSE T_COLON suite { $$ = mknode("ELSE", $3, NULL); }
  
;


suite:
    block       
  | stmt     
;


assignment_stmt:
    lhs T_ASSIGNMENT expr {
        $$ = mknode("=", $1, $3);
    }
;

lhs:
    T_IDENTIFIER_LITERAL 
    {
        $$ = mknode($1, NULL, NULL);
    }
    | T_IDENTIFIER_LITERAL T_LBRACKET expr T_RBRACKET 
    {
        $$ = mknode($1, mknode("[", $3, mknode("]", NULL, NULL)), NULL);
    }
;


call_expr:
    T_CALL T_IDENTIFIER_LITERAL T_LPAREN expr_list T_RPAREN {
        node* call = mknode("CALL", NULL, NULL);
        call->left = mknode($2, NULL, NULL);
        if ($4) {
            call->right = $4;
        }
        $$ = call;
    }
;

expr_list:
    expr {
        $$ = $1;
    }
    | expr T_COMMA expr_list {
        $$ = mknode("", $1, $3);
    }
    | /* empty */ {
        $$ = NULL;
    }
;






expr:
    expr T_PLUS expr       { $$ = mknode("+", $1, $3); }
  | expr T_MINUS expr      { $$ = mknode("-", $1, $3); }
  | expr T_STAR expr       { $$ = mknode("*", $1, $3); } 
  | expr T_DIVISION expr   { $$ = mknode("/", $1, $3); }

  | expr T_EQL expr        { $$ = mknode("==", $1, $3); }
  | expr T_NOTEQL expr     { $$ = mknode("!=", $1, $3); }
  | expr T_GREATER expr    { $$ = mknode(">", $1, $3); }
  | expr T_GREATEREQL expr { $$ = mknode(">=", $1, $3); }
  | expr T_LESS expr       { $$ = mknode("<", $1, $3); }
  | expr T_LESSEQL expr    { $$ = mknode("<=", $1, $3); }

  | expr T_AND expr        { $$ = mknode("&&", $1, $3); }
  | expr T_OR expr         { $$ = mknode("||", $1, $3); }

  | T_NOT expr             { $$ = mknode("!", $2, NULL); }
  | T_ADDRESS expr         { $$ = mknode("&", $2, NULL); }
  | T_STAR expr            { $$ = mknode("DEREF", $2, NULL); }
  | T_LENGTH expr T_LENGTH { $$ = mknode("LENGTH", $2, NULL); }

  | T_LPAREN expr T_RPAREN   { $$ = mknode("()", $2, NULL); }

  | T_IDENTIFIER_LITERAL T_LBRACKET expr T_RBRACKET {
        $$ = mknode($1, mknode("[", $3, mknode("]", NULL, NULL)), NULL);
    }
  | T_IDENTIFIER_LITERAL T_LPAREN expr T_RPAREN {
        $$ = mknode($1, mknode("(", $3, mknode(")", NULL, NULL)), NULL);
    }


  | T_IDENTIFIER_LITERAL   { $$ = mknode($1, NULL, NULL); }
  | T_NUMBER               { $$ = mknode($1, NULL, NULL); }
  | T_DEC_LTL              { char temp[20]; sprintf(temp, "%d", $1); $$ = mknode(strdup(temp), NULL, NULL); }
  | T_HEX_LTL              { $$ = mknode($1, NULL, NULL); }
  | T_REAL_LTL             { $$ = mknode($1, NULL, NULL); }
  | T_CHAR_LTL             { $$ = mknode($1, NULL, NULL); }
  | T_STRING_LITERAL       { $$ = mknode($1, NULL, NULL); }
  | T_TRUE                 { $$ = mknode("true", NULL, NULL); }
  | T_FALSE                { $$ = mknode("false", NULL, NULL); }
  | T_NULL                { $$ = mknode("null", NULL, NULL); }
  | call_expr
  | /* empty */ { $$ = NULL;}

;

%%
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