#ifndef AST_H
#define AST_H

typedef enum { NUM_NODE, VAR_NODE, BINOP_NODE, ASSIGN_NODE, RETURN_NODE } NodeType;

typedef struct Node {
    NodeType type;
    union {
        int num;
        char *var;
        struct {
            char op;
            struct Node *left, *right;
        } binop;
        struct {
            char *var;
            struct Node *value;
        } assign;
        struct Node *ret;
    };
} Node;

Node* createNum(int value);
Node* createVar(char *var);
Node* createBinOp(char op, Node *left, Node *right);
Node* createAssign(char *var, Node *val);
Node* createReturn(Node *val);
void printAST(Node *node, int indent);

#endif