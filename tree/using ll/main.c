/*
File Name: main_c
Author: Aarya Chaumal
*/

#include <stdio.h>
#include "bst.h"
#include <stdlib.h>
//Problem: 

int max(int x, int y)
{
    if(x>y) return x;
    else return y;
}

int height(node* root)
{
    if(root == NULL)
        return -1;
    if(root->left == NULL && root->right == NULL)
        return 0;
    else
        return 1+max(height(root->left), height(root->right)); 
}

void farthest(BST root)
{
    int h=height(root);
    while(h>=0)
    {
        printf("%d--",root->key);
        h--;
        if(height(root->left)==h)
            root=root->left;
        else
            root=root->right;
    }
}

int main()
{
    BST t;
    insertNode(&t,0);
    return 0;
}
