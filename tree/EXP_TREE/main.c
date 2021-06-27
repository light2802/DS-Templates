/*
File Name: main_c
Author: Aarya Chaumal
*/

#include "exp_tree.h"
#include <stdio.h>

//Problem: Expression tree
int main()
{
    EXP_TREE root;
    
    root=init("2 + 3 / 4");
    printf("\n");
    traverse(root);
    printf("\nFinal Answer : %f",compute(root));
    return 0;
}
