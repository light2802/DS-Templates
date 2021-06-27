#ifndef BST_h_INCLUDED
#define BST_h_INCLUDED

typedef struct node{
    int key;
    struct node *left, *right, *parent;
} node;

typedef node* BST;

void initBST(BST* t);
void insertNode(BST *t,int key);
void removeNode(BST *t,int key);
int search(BST t,int key);
void postorder(BST t);
void Display_Level(BST t,int level);
void destroyTree(BST *t);

#endif //BST_h_INCLUDED
