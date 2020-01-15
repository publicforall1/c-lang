// Implement undirected graph using matrix of vertices - vertices
// Properties:
//     - Self-loop
//     - Multigraph
//     - Directed-graph (Not implement yet)

#include "vertices_vertices_graph.h"

void init_graph(Graph* G, int vertices) {
    G->number_of_vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; j++) {
            G->matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int vertex1, int vertex2) {
    // Turn data to real index (array index count from 0)
    --vertex1;
    --vertex2;
    G->matrix[vertex1][vertex2] += 1;
    G->matrix[vertex2][vertex1] += 1;
}

int is_adjacent(Graph G, int vertex1, int vertex2) {
    return G.matrix[--vertex1][--vertex2] > 0;
}

int degree(Graph G, int vertex) {
    int deg = 0;
    --vertex;
    for(int i = 0; i < G.number_of_vertices; ++i){
        deg += G.matrix[i][vertex];
    }
    return deg;
}
