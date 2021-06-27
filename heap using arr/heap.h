#ifndef heap_h_INCLUDED
#define heap_h_INCLUDED

typedef struct heap {
    int* root;
    int last;
} heap;

//ALL FUNCTIONS FOR CREATING A MIN HEAP

void init_heap(heap *h);
void heapify_up_down(heap h, int i);
void heapify_down_up(heap h, int i);
void insert(heap *h, int key);
int pop(heap *h);
int isFull(heap h);
void print(heap h);
#endif //heap_h_INCLUDED
