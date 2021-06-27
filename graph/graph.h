#ifndef graph_h_INCLUDED
#define graph_h_INCLUDED

typedef struct edge
{
    int src,dest,weight;
} edge;

typedef struct graph
{
    int vertices;
    int **edges;
} graph;

typedef struct graph_list
{
    int edges,vertices;
    edge* list;
} graph_list;

void init(graph* g, int vertices);
void add_vertex(graph* g);
void add_edge(graph* g, int src, int dest, int weight);
void remove_edge(graph* g, int src, int dest);
void remove_vertex(graph* g, int src);
graph_list convert_matrix_to_list(graph g);
void dfs(graph* g);
void bfs(graph* g);
int has_loop(graph g);
graph min_spanning_kruskal(graph g);
int* shortest_dist_bellman_ford(graph_list g, int src);
void destroy(graph* g);
#endif //graph_h_INCLUDED
