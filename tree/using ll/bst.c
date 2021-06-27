#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "bst.h"

void initBST(BST* t)
{
    (*t)=NULL;
}
void insertNode(BST *t,int key)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    if((*t)==NULL)
    {
        (*t)=temp;
        return;
    }
    else if((*t)->left==NULL && (*t)->right==NULL)
    {
        
        if(key > (*t)->key)
        {
            temp->parent=(*t);
            (*t)->right=temp;
        }
        else if(key < (*t)->key)
        {
            temp->parent=(*t);
            (*t)->left=temp;
        }
        else
        {
            free(temp);
        }
    }
    else
    {
        if((*t)->key > key)
            insertNode(&((*t)->left),key);
        else
            insertNode(&((*t)->right),key);
    }
}
void removeNode(BST *t,int key)
{
    if((*t)->key==key)
    {
        if((*t)->left==NULL && (*t)->right==NULL)
        {
            node *temp=(*t)->parent;
            if(temp->key > (*t)->key)
                temp->left=NULL;
            else
                temp->right=NULL;
            free(*t);
        }
        else if((*t)->left!=NULL)
        {
            node *curr,*trail;
            curr=(*t)->left;
            trail=NULL;
            while(curr->right!=NULL)
            {
                trail=curr;
                curr=curr->right;
            }
            trail->right=NULL;
            curr->left=(*t)->left;
            curr->right=(*t)->right;
            if((*t)->parent->key > key)
                (*t)->parent->left=curr;
            else
                (*t)->parent->right=curr;
            free(*t);
        }
        else
        {
            node *curr,*trail;
            curr=(*t)->right;
            trail=NULL;
            while(curr->left!=NULL)
            {
                trail=curr;
                curr=curr->left;
            }
            trail->left=NULL;
            curr->left=(*t)->left;
            curr->right=(*t)->right;
            if((*t)->parent->key > key)
                (*t)->parent->left=curr;
            else
                (*t)->parent->right=curr;
            free(*t); 
        }
    }
    else if((*t)->key < key)
        removeNode(&((*t)->right),key);
    else
        removeNode(&((*t)->left),key);   
}
int search(BST t,int key)
{
    if(t==NULL)
        return 0;
    if(t->key == key)
    {   
        return 1;
    }
    else if(t->key > key)
        return search(t->left,key);
    else
        return search(t->right,key);
}
void postorder(BST t)
{
    if(t==NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    printf("%d--",t->key);
}
void Display_Level(BST t,int level)
{
    if(t==NULL)
        return;
    else if(level==0)
        printf("%s",t->key);
    else if(level>0)
    {
        Display_Level(t->left,level-1);
        Display_Level(t->right,level-1);
    }
}

void destroyTree(BST *t)
{
    if(*t==NULL)
        return;
    destroyTree(&((*t)->left));
    destroyTree(&((*t)->right));
    free(*t);
    *t=NULL;
}