// Implement undirected graph using matrix of vertices - vertices
// Properties:
//     - Self-loop
//     - Multigraph
//     - Directed-graph (Not implement yet)

//   V e r t e x
// V 0 0 0 0 0 0
// e 0 0 0 0 0 0
// r 0 0 0 0 0 0
// t 0 0 0 0 0 0
// e 0 0 0 0 0 0
// x 0 0 0 0 0 0

#include "vertices_vertices_graph.h"

void init_graph(Graph* G, int vertices) {
    G->number_of_vertices = vertices;
    for (int i = 1; i <= vertices; ++i) {
        for (int j = 1; j <= vertices; j++) {
            G->matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int vertex1, int vertex2) {
    G->matrix[vertex1][vertex2] += 1;
    G->matrix[vertex2][vertex1] += 1;
}

int is_adjacent(Graph G, int vertex1, int vertex2) {
    return G.matrix[vertex1][vertex2] > 0;
}

int degree(Graph G, int vertex) {
    int deg = 0;
    for (int i = 1; i <= G.number_of_vertices; ++i) {
        deg += G.matrix[i][vertex];
    }
    return deg;
}

List get_adjacents(Graph G, int vertex) {
    List adjacents;
    init_list(&adjacents);

    for (int i = 1; i <= G.number_of_vertices; ++i) {
        if (is_adjacent(G, i, vertex) && i != vertex) {
            append(&adjacents, i);
        }
    }

    return adjacents;
}
