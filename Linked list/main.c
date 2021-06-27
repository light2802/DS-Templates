/*
File Name: main
Author: Aarya Chaumal
*/
#include <stdlib.h>
#include<limits.h>
#include<stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef node* ptr;
void print_list(ptr start)
{
    printf("START-->");
    while(start)
    {
        printf("%d-->",start->data);
        start=start->next;
    }
    printf("NULL");
}
void add_to_beginning(ptr *start, int d)
{
    ptr new_node=(node*)malloc(sizeof(node));
    new_node->data=d;
    new_node->next=*start;
    *start=new_node;
}
void add_to_end(ptr *start, int d)
{
    if(!(*start))
        {
            ptr new_node=(node*)malloc(sizeof(node));
            new_node->data=d;
            new_node->next=*start;
            *start=new_node; 
        }
    else
    {
        ptr temp=*start;
        while(temp->next)
        {
            temp=temp->next;
        }
        ptr new_node=(node*)malloc(sizeof(node));
        new_node->data=d;
        new_node->next=NULL;
        temp->next=new_node;
    }
}
int add_to_position(ptr *start, int d, int pos)
{
    ptr temp=*start;
    for(int i=0;i<pos-1;i++)
    {
        if(temp!=NULL)
        {
            return 1;
        }
        temp=temp->next;
    }
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=d;
    new_node->next=temp->next;
    temp->next=new_node;
    return 0;
}
int remove_from_beginning(ptr *start)
{
    if(*start)
    {
        ptr temp=*start;
        int ret;
        temp=temp->next;
        ret=(*start)->data;
        free(*start);
        *start=temp;
        return ret;
    }
    else
    {
        return INT_MIN;
    }
    
}
int remove_from_end(ptr *start)
{
    
    if(*start)
    {
        ptr temp=*start;
        int ret;
        while((temp->next)->next)
        {
            temp=temp->next;
        }
        ret=(temp->next)->data;
        free(temp->next);
        temp->next=NULL;
        return ret;
    }
    else
    {
        return INT_MIN;
    }
}
int remove_from_position(ptr *start, int pos)
{
    int ret;
    if(pos==0)
        return remove_from_beginning(start);
    if(*start)
    {
        ptr temp=*start,temp1;
        int i=0;
        while(i<pos-1)
        {
            if(temp->next==NULL)
                return INT_MIN;
            temp=temp->next;
            i++;
        }
        temp1=temp->next;
        ret=temp1->data;
        temp->next=temp1->next;
        free(temp1);
        return ret;
    }
    else
    {
        return INT_MIN;
    }
}
int delete_list(node **start)
{
    int i=0;
    ptr temp=*start;
    if(*start==NULL)
        return 0;
    while(temp->next)
    {
        i++;
        temp=temp->next;
    }
    temp=*start;
    for(i;i>0;i--)
    {
        remove_from_position(start,i-1);
    }
    *start=NULL;
    return 0;
}

ptr reverse_list(ptr *start)
{
    ptr start_new,temp;
    temp=(*start);
    while(temp!=NULL)
    {
        add_to_beginning(&start_new,temp->data);
        temp=temp->next;
    }
    delete_list(start);
    *start=start_new;
}

void print_even(ptr start)
{
    while(start!=NULL)
    {
        printf("%d-->",start->data);
        start=start->next;
        if(start==NULL)
            break;
        start=start->next;
    }
}

int mid(ptr start)
{
    int ret,len=0;
    ptr temp;
    temp=start;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    if(len%2)
    {
        len=(len-1)/2;
        temp=start;
        while(len)
        {
            ret=temp->data;
            temp=temp->next;
            len--;
        }
        return ret;
    }
    return INT_MIN;
}

int main()
{
    ptr start;
    start=NULL;
    int ch,data,pos;
    add_to_beginning(&start,0);
    add_to_beginning(&start,1);
    add_to_beginning(&start,2);
    add_to_beginning(&start,3);
    add_to_beginning(&start,4);
    //add_to_beginning(&start,5);
    print_list(start);
    printf("\n");
    print_even(start);
    printf("\n");
    reverse_list(&start);
    print_list(start);
    printf("\n");
    printf("%d",mid(start));
    return 0;
}
