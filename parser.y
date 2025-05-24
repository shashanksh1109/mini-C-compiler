%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%union {
    int num;
    char* id;
    struct Node* node;  // ✅ Use "struct Node*" here (forward declaration safe)
}

%{
#include "ast.h"  // ✅ Move AFTER %union so Node is defined AFTER usage
Node *root;
void yyerror(const char *s);
int yylex(void);
%}

%token <num> NUM
%token <id> ID
%token INT RETURN

%type <node> stmt expr program

%%

program:
    stmt_list           { root = $1; }
    ;

stmt_list:
    stmt                { $$ = $1; }
    | stmt_list stmt    { $$ = $2; }  // Optionally build a block AST here
    ;

expr:
    NUM                     { $$ = createNum($1); }
    | ID                    { $$ = createVar($1); }
    | expr '+' expr         { $$ = createBinOp('+', $1, $3); }
    | expr '*' expr         { $$ = createBinOp('*', $1, $3); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}