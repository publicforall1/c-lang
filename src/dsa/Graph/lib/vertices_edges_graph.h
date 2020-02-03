#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NUMBER_OF_VERTICES 200
#define MAX_NUMBER_OF_EDGES 400

#include "list/list.h"
#include "stack/stack.h"
#include "queue/circular_queue.h"
typedef struct Graph {
    int graph[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_EDGES];
    int number_of_vertices;
    int number_of_edges;
    int visited[MAX_NUMBER_OF_VERTICES];
} Graph;

void init_graph(Graph* G, int vertices, int edges);
void add_edge(Graph* G, int edge, int vertex1, int vertex2);
int is_adjacent(Graph G, int vertex1, int vertex2);
int degree(Graph G, int vertex);
List get_adjacents(Graph G, int vertex);
void mark_visited(Graph* g, int vertex);
int is_visited(Graph g, int vertex);
void dfs(Graph* g, int start);
void reset_visted(Graph* g); // O(n)
void dfs_using_stack(Graph* g, int start);
void bfs_using_queue(Graph* g, int start);

#endif