#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NUMBER_OF_VERTICES 200
#define MAX_NUMBER_OF_EDGES 400

#include "list/list.h"
#include "queue/circular_queue.h"
#include "stack/stack.h"

typedef struct Graph {
    int graph[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_EDGES];
    int number_of_vertices;
    int number_of_edges;
} Graph;

void init_graph(Graph* G, int vertices, int edges); // O(vertices * edges)
void add_edge(Graph* G, int edge, int vertex1, int vertex2); // O(1)
int is_adjacent(Graph G, int vertex1, int vertex2);          // O(n)
int degree(Graph G, int vertex);                             // O(n)
List get_adjacents(Graph G, int vertex);                     // O(n)
void dfs(Graph g, int start, int* visited);
void dfs_using_stack(Graph g, int start, int* visited);
void bfs_using_queue(Graph g, int start, int* visited);

#endif
