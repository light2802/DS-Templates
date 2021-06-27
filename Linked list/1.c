/*
File Name: 1_c
Author: Aarya Chaumal
*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
struct Node* push(struct Node* head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   
    /* 2. put in the data  */
    new_node->data  = new_data;
   
    /* 3. Make next of new node as head */
    new_node->next = (head_ref);
   
    /* 4. Return address of newly allocated node */
    return new_node;
}
void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
//Problem: 
int main()
{
  /* Start with the empty list */
  struct Node* head = NULL;
  
  // Insert 6.  So linked list becomes 6->NULL
 // append(&head, 6);
  
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  head=push(head, 7);
  
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  head=push(head, 1);
  
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
 // append(&head, 4);
  
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  //insertAfter(head->next, 8);
  
  printf("\n Created Linked list is: ");
  printList(head);
  printf("%d",head->data);
  return 0;
}
