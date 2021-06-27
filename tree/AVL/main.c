/*
File Name: main_c
Author: Aarya Chaumal
*/

#include <stdio.h>
#include "avl.h"

//Problem: 
int main()
{
    AVL_TREE root;
    init(&root);
    while(1)
    {
        int choice=5;
        printf("Menu (TREE already initialised)\n");
        printf("1.Insert Node\n");
        printf("2.Delete Node\n");
        printf("3.Traverse (Preorder)\n");
        printf("4.Delete Tree\n");
        printf("5.Exit\n");
        scanf("%d",&choice);
        if(choice>=5)
        {
            destroy(&root);
            break;
        }
        switch(choice)
        {
            case 1:
            {
                int key;
                printf("Enter Key\n");
                scanf("%d",&key);
                insert(&root,key);
                break;
            }
            case 2:
            {
                int key;
                printf("Enter Key\n");
                scanf("%d",&key);
                remove_node(&root,key);
                break;
            }
            case 3:
            {
                traverse(root);
                break;
            }
            case 4:
            {
                destroy(&root);
                init(&root);
            }
        }
    }
    
    return 0;
}
