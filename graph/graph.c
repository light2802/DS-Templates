#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void init(graph* g, int vertices)
{
    g->vertices=vertices;
    g->edges = (int **)malloc(vertices * sizeof(int *));
    for(int i=0; i<vertices; i++)
        g->edges[i] = (int *)calloc(vertices, sizeof(int));
}

void add_edge(graph* g, int src, int dest, int weight)
{
    g->edges[src][dest]=weight;
}

void remove_edge(graph* g, int src, int dest)
{
    g->edges[src][dest]=0;
}

void remove_vertex(graph* g, int src);

graph_list convert_matrix_to_list(graph g)
{
    graph_list g_list;
    g_list.list=(edge*)malloc(sizeof(edge));
    g_list.edges=0;
    g_list.vertices=g.vertices;
    for(int i=0;i<g.vertices;i++)
    {
        for(int j=0;j<g.vertices;j++)
        {
            if(!g.edges[i][j])
                continue;
            g_list.edges++;
            g_list.list=(edge*)realloc(g_list.list,g_list.edges*sizeof(edge));
            g_list.list[g_list.edges-1].src=i;
            g_list.list[g_list.edges-1].dest=j;
            g_list.list[g_list.edges-1].weight=g.edges[i][j];
        }
    }
    return g_list;
}

void destroy(graph* g)
{
    for(int i=0;i<=g->vertices;i++)
    {
        g->edges[i]=(int*)realloc(g->edges[i],0);
    }
    free(g->edges);
}

void dfs(graph* g)
{
    int* visited=(int*)calloc(g->vertices,sizeof(int));
    int top=-1;
    int* stack=(int*)malloc(sizeof(int)*(g->vertices * g->vertices));
    stack[++top]=0;
    int i;
    while(top>=0)
    {
        i=stack[top--];
        if(!visited[i])
        {
            visited[i]=1;
            printf("%d--",i);
        }
        for(int j=0;j<g->vertices;j++)
        {
            if(g->edges[i][j] && !visited[j])
                stack[++top]=j;
        }
    }
    free(stack);
}

void bfs(graph* g)
{
    int* visited=(int*)calloc(g->vertices,sizeof(int));
    int* queue;
    int front,rear;
    queue=(int*)malloc(sizeof(int)* (g->vertices)*(g->vertices) );
    rear=0;
    front=0;
    queue[front]=0;
    visited[0]=1;
    while(front!=-1)
    {
        int x=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==g->vertices-1)
            front=0;
        else
            front++;
        printf("%d--",x);
        for(int i=0;i<g->vertices;i++)
        {
            if( !visited[i] && g->edges[x][i])
            {
                if(front==-1)
                {
                    front=0;
                    rear=0;
                }
                else if(rear==g->vertices-1 && front!=0)
                    rear=0;
                else
                    rear++;
                queue[rear]=i;
                visited[i]=1;
            }
        }
        visited[x]=1;
    }
    free(queue);
}

int has_loop(graph g)
{
    int* visited=(int*)calloc(g.vertices,sizeof(int));
    int top=-1;
    int* stack=(int*)malloc(sizeof(int)*(g.vertices * g.vertices));
    stack[++top]=0;
    int i;
    while(top>=0)
    {
        i=stack[top--];
        if(!visited[i])
            visited[i]=1;
        else
        {
            free(stack);
            free(visited);
            return 1;
        }
        for(int j=0;j<g.vertices;j++)
        {
            if(g.edges[i][j] && !visited[j])
                stack[++top]=j;
        }
    }
    free(stack);
    free(visited);
    return 0;
}

graph min_spanning_kruskal(graph g)
{
    graph min;
    init(&min,g.vertices);
    edge* sorted_edges=(edge*)malloc(sizeof(edge));
    int edges=0;
    for(int i=0;i<g.vertices;i++)       //make a list of edges present in the original graph
    {
        for(int j=0;i>j;j++)
        {
            if(!g.edges[i][j])
                continue;
            edges++;
            sorted_edges=(edge*)realloc(sorted_edges,edges*sizeof(edge));
            sorted_edges[edges-1].src=i;
            sorted_edges[edges-1].dest=j;
            sorted_edges[edges-1].weight=g.edges[i][j];
        }
    }

    for(int i=0;i<edges;i++)        //sort the edges according to weight (simple bubble sort)
    {
        for(int j=0;j<edges-i-1;j++)
        {
            if(sorted_edges[j].weight > sorted_edges[j+1].weight)
            {
                edge temp=sorted_edges[j];
                sorted_edges[j]=sorted_edges[j+1];
                sorted_edges[j+1]=temp;
            }
        }
    }

    int actual_edges=0;
    for(int i=0;i<edges && actual_edges<g.vertices;i++)     //Add edge to graph if it forms a loop remove it , continue adding edges till V-1 edges
    {
        add_edge(&min,sorted_edges[i].src,sorted_edges[i].dest,sorted_edges[i].weight);
        actual_edges++;
        if(has_loop(min))
        {
            remove_edge(&min,sorted_edges[i].src,sorted_edges[i].dest);
            actual_edges--;
        }
    }

    return min;
}

int* shortest_dist_bellman_ford(graph_list g, int src)
{
    int* distances=(int*)malloc(sizeof(int)*g.vertices);
    for(int i=0;i<g.vertices;i++)
        distances[i]=INT_MAX/2;
    distances[src]=0;
    for(int i=0;i<g.vertices-1;i++)
    {
        for(int j=0;j<g.edges;j++)
        {
            if(distances[g.list[j].dest]>(distances[g.list[j].src]+g.list[j].weight))
                distances[g.list[j].dest]=distances[g.list[j].src]+g.list[j].weight;
        }
    }
    return distances;
}