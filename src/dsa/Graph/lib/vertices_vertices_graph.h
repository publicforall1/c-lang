#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NUMBER_OF_VERTICES 100
#include "list/list.h"

typedef struct Graph {
    int matrix[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_VERTICES];
    int number_of_vertices;
} Graph;

void init_graph(Graph* G, int vertices);
void add_edge(Graph* G, int vertex1, int vertex2);
int is_adjacent(Graph G, int vertex1, int vertex2);
int degree(Graph G, int vertex);
List get_adjacents(Graph G, int vertex);

#endif
