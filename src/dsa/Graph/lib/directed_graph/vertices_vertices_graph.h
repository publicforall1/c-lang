#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NUMBER_OF_VERTICES 100
#define VISITED 1
#define UNVISITED 0

#include "../list/list.h"
#include "../queue/circular_queue.h"
#include "../stack/stack.h"

typedef struct Graph {
    int matrix[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_VERTICES];
    int vertices;
    int visited[MAX_NUMBER_OF_VERTICES];
} Graph;

// Classic
void init_graph(Graph* G, int vertices, int edges);          // O(vertices ^2)
void add_edge(Graph* G, int edge, int vertex1, int vertex2); // O(1)
int is_adjacent(Graph G, int vertex1, int vertex2);          // O(1)
int in_degree(Graph g, int vertex);                          // O(n)
int out_degree(Graph g, int vertex);                         // O(n)
int degree(Graph G, int vertex);                             // O(n)

// Medium
List get_adjacents(Graph G, int vertex); // O(n)
// Medium :: Graph traversal
void reset_visited(Graph* g); // O(n)
void dfs(Graph* g, int vertex, List* traversal);
void dfs_using_stack(Graph* g, int start_vertex, List* traversal);
void bfs_using_queue(Graph* g, int start_vertex, List* traversal);

#endif
