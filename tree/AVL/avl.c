#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

void init(AVL_TREE *root)
{
    *root=NULL;
}

int max_of(int x, int y)
{
    return x>=y?x:y;
}

int height(AVL_TREE root)
{
    if(root == NULL)
        return -1;
    else
        return 1 + max_of(height(root->left), height(root->right));
}

int calc_balance(AVL_TREE root)
{
    return height(root->left) - height(root->right);
}

AVL_TREE rotate_LL(AVL_TREE root)      //Same as rotating z Right
{
    node* parent=root->parent;
    node *left=root->left;
    node* left_right=left->right;

    left->right=root;
    left->parent=parent;
    root->left=left_right;
    root->parent=left;
    if(left_right != NULL)
        left_right->parent=root;
    if(parent != NULL)
    {
        if(parent->left==root)
            parent->left=left;
        else
            parent->right=left;
    }
    root->balance_factor=calc_balance(root);
    left->balance_factor=calc_balance(left);

    return left;
}

AVL_TREE rotate_RR(AVL_TREE root)       //Same as rotating Left z left
{
    node* parent=root->parent;
    node *right=root->right;
    node *right_left=right->left;
    
    right->left=root;
    right->parent=parent;
    root->right=right_left;
    root->parent=right;
    if(right_left != NULL)
        right_left->parent=root;
    if( parent != NULL)
    {
        if(parent->left==root)
            parent->left=right;
        else
            parent->right=right;
    }
    root->balance_factor=calc_balance(root);
    right->balance_factor=calc_balance(right);

    return right;
}

AVL_TREE insert_at_notRoot(AVL_TREE root, int month, AVL_TREE parent)
{
    if(root == NULL)
    {
        node* new;
        new=(node*)malloc(sizeof(node));
        new->left=new->right=NULL;
        new->balance_factor=0;
        new->month=month;
        new->parent=parent;
        if(parent->month > month)
            parent->left=new;
        else
            parent->right=new;
        node *z=new,*y=NULL,*x=NULL;
        while(z != NULL)
        {
            z->balance_factor=calc_balance(z);
            if(z->balance_factor>1 || z->balance_factor<-1)
            {
                if(z->left == y && y->left == x)
                    z=rotate_LL(z);
                else if(z->left == y && y->right == x)
                {
                    y=rotate_RR(y);
                    z=rotate_LL(z);
                }
                else if(z->right == y && y->right == x)
                    z=rotate_RR(z);
                else
                {
                    y=rotate_LL(y);
                    z=rotate_RR(z);
                }
            }
            x=y;
            y=z;
            z=z->parent;
        }
        return y;
    }
    if(root->month > month)
        return insert_at_notRoot(root->left, month, root);
    else if(root->month < month)
        return insert_at_notRoot(root->right, month, root);
    else
        return root;
}

void insert(AVL_TREE *root, int month)
{
    if(*root==NULL)
    {
        node* new;
        new=(node*)malloc(sizeof(node));
        new->left=new->right=new->parent=NULL;
        new->balance_factor=0;
        new->month=month;
        *root=new;
    }
    else
        *root=insert_at_notRoot(*root, month, *root);
}

void remove_node(AVL_TREE *root,int month)
{
    if((*root)->month == month)
    {
        if((*root)->left==NULL && (*root)->right==NULL)
        {
            node *temp=(*root)->parent;
            if(temp!=NULL)
            {
                if(temp->month > (*root)->month)
                    temp->left=NULL;
                else
                    temp->right=NULL;
                temp->balance_factor=calc_balance(temp);
            }
            free(*root);
            (*root)=NULL;
        }
        else if((*root)->left!=NULL)
        {
            node *curr,*trail;
            curr=(*root)->left;
            trail=NULL;
            while(curr->right!=NULL)
            {
                trail=curr;
                curr=curr->right;
            }
            if(trail!=NULL)
            {
                trail->right=NULL;
                trail->balance_factor=calc_balance(trail);
            }
            curr->left=(*root)->left;
            curr->right=(*root)->right;
            curr->balance_factor=calc_balance(curr);
            if((*root)->parent != NULL)
            {
                if((*root)->parent->month > month)
                    (*root)->parent->left=curr;
                else
                    (*root)->parent->right=curr;
                (*root)->parent->balance_factor=calc_balance((*root)->parent);
            }
            free(*root);
            (*root)=NULL;
        }
        else
        {
            node *curr,*trail;
            curr=(*root)->right;
            trail=NULL;
            while(curr->left!=NULL)
            {
                trail=curr;
                curr=curr->left;
            }
            if(trail!= NULL)
            {
                trail->left=NULL;
                trail->balance_factor=calc_balance(trail);
            }
            curr->left=(*root)->left;
            curr->right=(*root)->right;
            curr->balance_factor=calc_balance(curr);
            if((*root)->parent != NULL)
            {
                if((*root)->parent->month > month)
                    (*root)->parent->left=curr;
                else
                    (*root)->parent->right=curr;
                (*root)->parent->balance_factor=calc_balance((*root)->parent);
            }
            free(*root); 
            (*root)=NULL;
        }
    }
    else if((*root)->month < month)
        remove_node(&((*root)->right),month);
    else
        remove_node(&((*root)->left),month);   
}

void traverse(AVL_TREE root)
{
    if(root != NULL)
    {
        printf("%d - %d\n", root->month, root->balance_factor);
        traverse(root->left);
        traverse(root->right);
    }
}

void destroy(AVL_TREE *root)
{
    if(*root != NULL)
    {
        destroy(&((*root)->left));
        destroy(&((*root)->right));
        free(*root);
        *root = NULL;
    }
}