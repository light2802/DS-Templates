#ifndef exp_tree_h_INCLUDED
#define exp_tree_h_INCLUDED

typedef struct node
{
    float operand;
    char operator;
    int type;
    struct node *left, *right;
} node;

typedef node* EXP_TREE;

void traverse(EXP_TREE root);

EXP_TREE init(char* exp);

float compute(EXP_TREE root);
#endif //exp_tree_h_INCLUDED
