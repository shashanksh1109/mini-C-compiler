#include <stdio.h>
#include "parser.tab.h"
#include "ast.h"

extern int yyparse(void);
extern Node *root;

int main() {
    printf("Enter C code:\n");
    yyparse();
    if (root) {
        printf("\nAbstract Syntax Tree:\n");
        printAST(root, 0);
    } else {
        printf("No AST generated.\n");
    }
    return 0;
}