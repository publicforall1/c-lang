#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NUMBER_OF_VERTICES 200
#define MAX_NUMBER_OF_EDGES 400

typedef struct Graph {
    int graph[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_EDGES];
    int number_of_vertices;
    int number_of_edges;
} Graph;

void init_graph(Graph* G, int vertices, int edges);
void add_edge(Graph* G, int edge, int vertex1, int vertex2);
int is_adjacent(Graph G, int vertex1, int vertex2);
int degree(Graph G, int vertex);

#endif