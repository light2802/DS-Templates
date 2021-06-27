/*
File Name: main_c
Author: Aarya Chaumal
*/

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//Problem: Heap Sort

void heap_sort(int *arr, int size)
{
    heap h;
    init_heap(&h);
    for(int i=0; i<size; i++)
        insert(&h, arr[i]);
    for(int i=0; i<size; i++)
        printf("%d\n",pop(&h));
}

int main(int argc, char **argv)
{
    // FILE *f;
    // int file_count=0;
    // while(argc > 1)
    // {
    //     file_count++;
    //     fopen(argv[file_count], "r");
    //     int *arr = NULL;
    //     int size=-1;
    //     printf("FILE : %s\n",argv[file_count]);
    //     while(!feof(f))
    //     {
    //         size++;
    //         arr=realloc(arr, sizeof(int) * (size+1) );
    //         printf("dd");
    //         fscanf(f,"%d,", &arr[size]);
    //     }
    //     printf("dd");
    //     for(int i=0;i<=size;i++)
    //         printf("%d ",arr[i]);
    //     heap_sort(arr,size);
    //     printf("FILE : %s\n",argv[file_count]);
    //     printf("Sorted Array : \n");
    //     for(int i=0;i<=size;i++)
    //         printf("%d ",arr[i]);
    //     printf("\n");
    //     size=0;
    //     arr=realloc(arr, 0 );
    //     fclose(f);
    //     argc--;
    // }

    //Temporary Driver Code
    //Code for taking input array from file not working
    int arr[9]={9,8,7,6,25,-4,31,20,1};     //RAndom Array
    heap_sort(arr,9);
    return 0;
}
