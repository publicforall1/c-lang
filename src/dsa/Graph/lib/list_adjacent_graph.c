// Implementing directed graph using list of adjacents
// 
// V [], []
// e [], []
// r [], []
// t [], []
// e [], []
// x [], []

#include "list_adjacent_graph.h"

void init_graph(Graph* g, int vertices) {
    g->number_of_vertices = vertices;
    for (int i = 1; i <= vertices; ++i) {
        init_list(&(g->out_adjacents[i]));
        init_list(&(g->in_adjacents[i]));
    }
} // O(n)

void add_edge(Graph* g, int vertex1, int vertex2) {
    // directed
    // vertex1 -> vertex2
    append(&(g->out_adjacents[vertex1]), vertex2);
    append(&(g->in_adjacents[vertex2]), vertex1);
} // O(1)

int is_adjacent(Graph g, int vertex1, int vertex2) {
    // true if vertex1 -> vertex2
    return is_exist(g.out_adjacents[vertex1], vertex2);
} // O(n)

int degree(Graph g, int vertex) {
    // directed
    int out_degree = length(g.out_adjacents[vertex]);
    int in_degree = length(g.in_adjacents[vertex]);

    return out_degree + in_degree;
} // O(1)