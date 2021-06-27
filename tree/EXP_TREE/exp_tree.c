#include "exp_tree.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int is_operator(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*' || x == '(' || x == ')')
        return 1;
    return 0;
}
int precedence(char x)
{
    switch (x)
    {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
    }
}
int ctoi(char x)
{
    switch (x)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
    }
}
float operate(float a, float b, char op)
{
    switch (op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}
EXP_TREE init(char* exp)
{
    node* n_stack[100];
    char c_stack[100];
    int n_top=-1,c_top=-1;
    int j=0;
    while(exp[j]!='\0')
    {
        if (exp[j]==' ')
        {
            j++;
            continue;
        }
        else if(isdigit(exp[j]))
        {
            float number=0;
            char temp_char;
            do
            {
                temp_char=exp[j++];
                number*=10;
                number+=ctoi(temp_char);
            }while(isdigit(exp[j]));
            float decimal=0;
            if(exp[j]=='.')
            {
                j++;
                while(isdigit(exp[j]))
                {
                    temp_char=exp[j++];
                    decimal*=10;
                    decimal+=ctoi(temp_char);
                }
            }
            number+=pow(decimal,-floor(log10(decimal)+1));      //for no. of decimal digits
            node *temp;
            temp=(node*)malloc(sizeof(node));
            temp->operand=number;
            temp->type=1;
            temp->left=temp->right= NULL;
            n_stack[++n_top]=temp;
        }
        else if(is_operator(exp[j]))
        {
            if(exp[j]=='(')
            {
                c_stack[++c_top]=exp[j];
            }
            else if(exp[j]==')')
            {
                while(c_top!=-1 && c_stack[c_top]!='(')
                {
                    node *op,*op1,*op2;
                    op=(node*)malloc(sizeof(node)); 
                    op->operator=c_stack[c_top--];
                    op->type=0;
                    op1=n_stack[n_top];
                    n_stack[n_top--]=NULL;
                    op2=n_stack[n_top];
                    n_stack[n_top--]=NULL;                       
                    op->left=op2;
                    op->right=op1;
                    n_stack[++n_top]=op;
                    c_top--;
                }
            }
            else
            {
                while(c_top!=-1 && c_stack[c_top]!='(' && precedence(exp[j]) <= precedence(c_stack[c_top]))
                {
                    node *op,*op1,*op2;
                    op=(node*)malloc(sizeof(node)); 
                    op->operator=c_stack[c_top--];
                    op->type=0;
                    op1=n_stack[n_top];
                    n_stack[n_top--]=NULL;
                    op2=n_stack[n_top];
                    n_stack[n_top--]=NULL;                       
                    op->left=op2;
                    op->right=op1;
                    n_stack[++n_top]=op;
                }
                c_stack[++c_top]=exp[j];
            }
            j++;
        }
        else
            j++;
    }
    while(c_top!=-1)
    {
        node *op,*op1,*op2;
        op=(node*)malloc(sizeof(node)); 
        op->operator=c_stack[c_top--];
        op->type=0;
        op1=n_stack[n_top];
        n_stack[n_top--]=NULL;
        op2=n_stack[n_top];
        n_stack[n_top--]=NULL;                       
        op->left=op2;
        op->right=op1;
        n_stack[++n_top]=op;
    }
    return n_stack[0];
}
void traverse(EXP_TREE root)
{
    if(root==NULL)
        return;
    traverse(root->left);
    if(root->type)
        printf("%f ",root->operand);
    else
        printf("%c ",root->operator);
    traverse(root->right);
}

float compute(EXP_TREE root)
{
    printf("\n");
    traverse(root);
    if(root!=NULL)
    {
        if(root->type==1)
            return root->operand;
        else
        {
            float x = compute(root->left);
            float y = compute(root->right);
            return operate(x,y,root->operand);
        }
    }
}