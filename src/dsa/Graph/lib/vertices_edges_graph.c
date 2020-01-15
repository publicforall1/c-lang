// Implementing Simple Undirected Graph using Matrix of Vertices - Edges
// Properties:
//     - Simple undirected graph/multigraph
//     - No self-loop

#include "vertices_edges_graph.h"
#include "assert.h"

void init_graph(Graph* G, int vertices, int edges) {
    G->number_of_vertices = vertices;
    G->number_of_edges = edges;

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < edges; ++j) {
            G->graph[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int edge, int vertex1, int vertex2) {
    // Turn data to real index (array index count from 0)
    --vertex1;
    --vertex2;
    --edge;
    G->graph[vertex1][edge] = 1;
    G->graph[vertex2][edge] = 1;
}

int is_adjacent(Graph G, int vertex1, int vertex2) {
    --vertex1;
    --vertex2;
    int ajacent = 0;
    for (int i = 0; i < G.number_of_edges; ++i) {
        if (G.graph[vertex1][i] == 1 && G.graph[vertex2][i] == 1) {
            ajacent = 1;
        }
    }
    return ajacent;
}

int degree(Graph G, int vertex) {
    --vertex;
    int d = 0;
    for (int i = 0; i < G.number_of_edges; ++i) {
        if (G.graph[vertex][i] == 1) {
            ++d;
        }
    }
    return d;
}
