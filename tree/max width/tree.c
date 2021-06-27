#include "tree.h"
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void width(TREE root, int level, int arr[])
{
    arr[level]++;
    if(root == NULL)
        return;
    else
    {
        width(root->left, level-1,arr);
        width(root->right, level-1, arr);
    }
}
int max_element(int arr[],int h)
{
    int max=0;
    for(int i=0;i<=h;h++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}
int height(TREE root)
{
    if(root == NULL)
        return 0;
    else
    {
        return MAX(height(root->left), height(root->right))+1;
    }
}

int maxwidth(TREE root)
{
    int *arr;
    int h=height(root);
    arr=(int*)calloc(sizeof(int),h);
    width(root,h,arr);
    return max_element(arr,h);
}

void TREE_insert(TREE *root, int data)
{
    
    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    if(*root==NULL)
    {
        *root=new;
        return;
    }
    node *p;
    p=*root;
    if(data==p->data)
    {
        free(new);
        return;
    }
    else if(data<p->data)
        TREE_insert(&(p->left),data);
    else
        TREE_insert(&(p->right),data);
}