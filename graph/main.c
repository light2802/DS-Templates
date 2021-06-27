/*
File Name: main_c
Author: Aarya Chaumal
*/

#include <stdio.h>
#include "graph.h"
//Problem: GRAPH ALGOS BFS,DFS
int main()
{

    graph g;
    init(&g,5);         //Vertices will as numbers in form : (A-0), (B-1), (C-2) ...
    graph_list g_list;

    add_edge(&g,0,1,-1);
    add_edge(&g,0,2,4);

    add_edge(&g,1,2,3);
    add_edge(&g,1,3,2);
    add_edge(&g,1,4,2);

    add_edge(&g,3,1,1);
    add_edge(&g,3,2,5);

    add_edge(&g,4,3,-3);

    g_list=convert_matrix_to_list(g);
    
    printf("Graph:\n");
    for(int i=0;i<g_list.edges;i++)
    {
        printf("%d->%d  (%d)\n",g_list.list[i].src,g_list.list[i].dest,g_list.list[i].weight);
    }
    
    printf("Min distances :\n");
    int* distances;
    for(int i=0;i<g_list.vertices;i++)
    {
        printf("From %d:\n",i);
        distances=shortest_dist_bellman_ford(g_list,i);
        for(int j=0;j<g_list.vertices;j++)
        {
            printf("%d  ",distances[j]);
        }
        printf("\n");
    }
    
    return 0;
}
