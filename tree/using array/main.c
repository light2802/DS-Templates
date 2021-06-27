/*
File Name: main_c
Author: Aarya Chaumal
*/
#include "tree.h"
#include <stdio.h>

//Problem: 
int main()
{
   init();
   while(1)
    {
        int choice=6;
        printf("\nMENU\n(Tree already initialized)\n");
        printf("1)Insert Node\n");
        printf("2)Preorder Traversal\n");
        printf("3)Inorder Traversal\n");
        printf("4)Postorder Traversal\n");
        printf("5)Is Complete BST ??\n");
        printf("6)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int data; 
                printf("Enter data : ");
                scanf("%d",&data);
                insert(data);
                printf("Node addded\n");
                break;
            }
            case 2:
            {
                traverse(-1);
                printf("\n");
                break;
            }
            case 3:
            {
                traverse(0);
                printf("\n");
                break;
            }
            case 4:
            {
                traverse(1);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("Tree is Complete : %s",is_complete()?"True":"False");
                printf("\n");
                break;
            }
            default:
            {   
                printf("Tree Destroyed :)");
                return 0;
            }
        }
    }
    return 0;
}
