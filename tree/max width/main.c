/*
File Name: main_c
Author: Aarya Chaumal
*/

#include "tree.h"
#include <stdio.h>

//Problem: 
int main()
{
    TREE root;
    TREE_insert(&root,5);
    TREE_insert(&root,4);
    TREE_insert(&root,1);
    TREE_insert(&root,53);
    TREE_insert(&root,42);
    TREE_insert(&root,6);
    TREE_insert(&root,9);
    TREE_insert(&root,0);
    printf("%d",maxwidth(root));
    return 0;
}
