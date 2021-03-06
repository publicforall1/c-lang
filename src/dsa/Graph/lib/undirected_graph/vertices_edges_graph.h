#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NUMBER_OF_VERTICES 200
#define MAX_NUMBER_OF_EDGES 400
#define UNVISITED 0
#define VISITED 1
#define INFINITY 999

#include "../list/list.h"
#include "../queue/circular_queue.h"
#include "../stack/stack.h"

typedef struct Graph {
    int graph[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_EDGES];
    int vertices;
    int edges;
    int visited[MAX_NUMBER_OF_VERTICES];
    int parent[MAX_NUMBER_OF_VERTICES];   // for have_cycle()
    int distance[MAX_NUMBER_OF_VERTICES]; // for Dijkstra shortest-path
                                          // algorithm
    int weight[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_VERTICES];
} Graph;

// Classic
void init_graph(Graph* G, int vertices, int edges); // O(vertices * edges)
void add_edge(Graph* G, int edge, int vertex1, int vertex2); // O(1)
int is_adjacent(Graph G, int vertex1, int vertex2);          // O(n)
int degree(Graph G, int vertex);                             // O(n)

// Medium
List get_adjacents(Graph g, int vertex); // O(n)
// Medium :: Graph traversal
void reset_visited(Graph* g); // O(n)
void dfs(Graph* g, int vertex, List* traversal);
void dfs_using_stack(Graph* g, int start_vertex, List* traversal);
void bfs_using_queue(Graph* g, int start_vertex, List* traversal);
int is_connected(Graph g);          // O(Complexity(dfs))
void find_and_set_parent(Graph* g); // for have_cycle
int have_cycle(Graph g);            // O(Complexity(dfs))
void add_weight(Graph* g, int x, int y, int weight);
void Dijkstra_find_and_set_distance(Graph* g, int source_vertex);

#endif
