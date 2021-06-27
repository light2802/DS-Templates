#ifndef tree_h_INCLUDED
#define tree_h_INCLUDED

typedef struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
} node; 

typedef node* TREE;

void TREE_insert(TREE *root, int data);
int maxwidth(TREE root);

#endif //tree_h_INCLUDED
