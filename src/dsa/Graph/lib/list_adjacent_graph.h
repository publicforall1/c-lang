#ifndef LIST_ADJACENT_GRAPH
#define LIST_ADJACENT_GRAPH

#include "list/list.h"
#define MAX_NUMBER_OF_VERTICES 100

typedef struct {
    List out_adjacents[MAX_NUMBER_OF_VERTICES]; // x -> this
    List in_adjacents[MAX_NUMBER_OF_VERTICES]; // this -> x
    int number_of_vertices;
} Graph;

void init_graph(Graph* g, int vertices); // O(n)
void add_edge(Graph* g, int vertex1, int vertex2); // O(1)
int is_adjacent(Graph g, int vertex1, int vertex2); // O(n)
int degree(Graph g, int vertex); // O(1)

#endif