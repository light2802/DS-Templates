#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int isFull(heap h)
{
    if(h.last==-1)
   return 0;
 
   return (ceil(log2(h.last)) == floor(log2(h.last)));
}

void init_heap(heap *h)
{
    h->root=NULL;
    h->last=-1;
}

void heapify_up_down(heap h, int i)
{
    int *arr=h.root;
    int n=h.last;
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
   
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
   
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
  
    if (smallest != i) { 
        swap(&arr[i], &arr[smallest]); 
        heapify_up_down(h, smallest); 
    } 
}

void heapify_down_up(heap h, int i)
{ 
    
    int *arr=h.root;
    int n=h.last;
    int parent = (i - 1) / 2; 
  
    if (arr[i] < arr[parent])
    { 
        swap(&arr[i], &arr[parent]); 
        heapify_down_up(h, parent); 
    } 
} 

void insert(heap *h, int key)
{
    if(h->root==NULL)
        h->root=calloc(1,sizeof(int));
    else if(isFull(*h))
        h->root=realloc(h->root,sizeof(int)*( (h->last+1) + 2 * (h->last+1) ));
    h->last++;
    h->root[h->last]=key;
    heapify_down_up(*h, h->last-1);
}

int pop(heap *h)
{
    if(h->last==-1)
        return INT_MIN;
    int top=h->root[0];
    h->root[0]=h->root[h->last];
    h->last--;
    heapify_up_down(*h,0);
    return top;
}

void print(heap h) 
{ 
    for (int i = 0; i <= h.last; i++) 
        printf("%d ",h.root[i]); 
}