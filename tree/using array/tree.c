#include<stdio.h>
#include <limits.h>
#include "tree.h"
int tree[100];
void init()
{
    for(int i=0; i<100; i++)
        tree[i]=INT_MIN;
}
void insert(int data)
{
    int i=0;
    while(i<100)
    {
        if(tree[i]==INT_MIN)
        {
            tree[i]=data;
            return;
        }
        else
        {
            if(tree[i]>data)
                i=i*2+1;
            else if(tree[i]<data)
                i=i*2+2;
            else
                return;
        }
    }
}
void traverse(int type)
{
    switch(type)
    {
        case -1:
        {
            int i=0;
            int stack[100];
            int top=0;
            stack[top]=i;
            while(top>=0)
            {
                i=stack[top--];
                printf("%d,",tree[i]);
                if(tree[i*2+1]!=INT_MIN)
                {
                    stack[++top]=i*2+2;
                }
                if(tree[i*2+2]!=INT_MIN)
                {
                    stack[++top]=i*2+1;
                }
            }
            break;
        }
        case 1:
        {
            int i=0;
            int stack[100];
            int top=-1;
            do
            {
                while (i>=0 && tree[i]!=INT_MIN)
                {
                    stack[++top]=i*2+2;
                    stack[++top]=i;
                    i=i*2+1;
                }
                i=stack[top--];
                if(tree[i*2+2]!=INT_MIN && stack[top]==(i*2+2))
                {
                    int x;
                    x=stack[top--];
                    stack[++top]=i;
                    i=x;
                }
                else
                {
                    if(tree[i]!=INT_MIN)
                        printf("%d,",tree[i]);
                    i=-1;
                }
            }while(top>=0);
            break;
        }
        case 0:
        {
            int i=0;
            int stack[100];
            int top=-1;
            while(1)
            {
                while(tree[i]!=INT_MIN)
                {
                    stack[++top]=i;
                    i=2*i+1;
                }
                if(tree[i]==INT_MIN && top>=0)
                {
                    int x=stack[top--];
                    printf("%d,",tree[x]);
                    i=2*x+2;
                }
                else if(tree[i]==INT_MIN && top<0)
                    break;
            }
            break;
        }
    }
}
int count(int root)
{
    if (tree[root]==INT_MIN) 
        return 0; 
    return (1 + count(2*root+1) + count(2*root+2));
}
int isComplete_at_node (unsigned int index, int number_nodes) 
{ 
    if (tree[index] == INT_MIN) 
        return 1;  
    if (index >= number_nodes) 
        return 0; 
    return (isComplete_at_node(2*index+1,number_nodes) && isComplete_at_node(2*index+2,number_nodes)); 
}
int is_complete()
{
    return isComplete_at_node(0,count(0));
}