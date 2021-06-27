#include <stdlib.h>
#include<stddef.h>
#include<stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef node* list;

void print_list(node *start)
{
    
    while(start)
    {
        printf("%d-->",start->data);
        start=start->next;
    }

}
void add_to_beginning(node *start, int d)
{
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=d;
    new_node->next=start;
    start=new_node;
}
void add_to_end(node *start, int d)
{
    if(!start)
        {
            node *new_node=(node*)malloc(sizeof(node));
            new_node->data=d;
            new_node->next=start;
            start=new_node; 
        }
    else
    {
        while(start->next)
        {
            start=start->next;
        }
        node *new_node=(node*)malloc(sizeof(node));
        new_node->data=d;
        new_node->next=NULL;
        start->next=new_node;
    }
    
}
void add_to_position(node *start, int d, int pos)
{
    for(int i=0;i<pos-1;i++)
    {
        start=start->next;
    }
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=d;
    new_node->next=start->next;
    start->next=new_node;
}
// void remove_from_beginning(node *start);
// void remove_from_end(node *start);
// void remove_from_position(node *start, int position);
// void delete_list(node *start);