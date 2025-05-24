#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Node* createNum(int value) {
    Node *n = malloc(sizeof(Node));
    n->type = NUM_NODE;
    n->num = value;
    return n;
}

Node* createVar(char *var) {
    Node *n = malloc(sizeof(Node));
    n->type = VAR_NODE;
    n->var = strdup(var);
    return n;
}

Node* createBinOp(char op, Node *left, Node *right) {
    Node *n = malloc(sizeof(Node));
    n->type = BINOP_NODE;
    n->binop.op = op;
    n->binop.left = left;
    n->binop.right = right;
    return n;
}

Node* createAssign(char *var, Node *val) {
    Node *n = malloc(sizeof(Node));
    n->type = ASSIGN_NODE;
    n->assign.var = strdup(var);
    n->assign.value = val;
    return n;
}

Node* createReturn(Node *val) {
    Node *n = malloc(sizeof(Node));
    n->type = RETURN_NODE;
    n->ret = val;
    return n;
}

void printAST(Node *node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; i++) printf("  ");
    switch (node->type) {
        case NUM_NODE: printf("NUM(%d)\n", node->num); break;
        case VAR_NODE: printf("VAR(%s)\n", node->var); break;
        case BINOP_NODE:
            printf("BINOP(%c)\n", node->binop.op);
            printAST(node->binop.left, indent + 1);
            printAST(node->binop.right, indent + 1);
            break;
        case ASSIGN_NODE:
            printf("ASSIGN(%s)\n", node->assign.var);
            printAST(node->assign.value, indent + 1);
            break;
        case RETURN_NODE:
            printf("RETURN\n");
            printAST(node->ret, indent + 1);
            break;
    }
}