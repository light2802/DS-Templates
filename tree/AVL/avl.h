#ifndef avl_h_INCLUDED
#define avl_h_INCLUDED

typedef struct node{
    int balance_factor;
    int month;
    struct node *left, *right, *parent;
} node;

typedef node* AVL_TREE;

void init(AVL_TREE *root);
void insert(AVL_TREE *root, int month);
void remove_node(AVL_TREE *root, int month);
void traverse(AVL_TREE root);
void destroy(AVL_TREE *root);


#endif //avl_h_INCLUDED
