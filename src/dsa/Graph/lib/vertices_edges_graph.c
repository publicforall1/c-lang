// Implementing Simple Undirected Graph using Matrix of Vertices - Edges
// Properties:
//     - Simple undirected graph/multigraph
//     - No self-loop
//
//   E d g e
// V 0 0 0 0
// e 0 0 0 0
// r 0 0 0 0
// t 0 0 0 0
// e 0 0 0 0
// x 0 0 0 0

#include "vertices_edges_graph.h"

void init_graph(Graph* g, int vertices, int edges) {
    g->number_of_vertices = vertices;
    g->number_of_edges = edges;

    for (int i = 1; i <= vertices; ++i) {
        for (int j = 1; j <= edges; ++j) {
            g->graph[i][j] = 0;
        }
    }
}

void add_edge(Graph* g, int edge, int vertex1, int vertex2) {
    g->graph[vertex1][edge] = 1;
    g->graph[vertex2][edge] = 1;
}

int is_adjacent(Graph g, int vertex1, int vertex2) {
    for (int i = 1; i <= g.number_of_edges; ++i) {
        if (g.graph[vertex1][i] == 1 && g.graph[vertex2][i] == 1) {
            return 1;
        }
    }
    return 0;
}

int degree(Graph g, int vertex) {
    int d = 0;
    for (int i = 1; i <= g.number_of_edges; ++i) {
        d += g.graph[vertex][i];
    }
    return d;
}

List get_adjacents(Graph g, int vertex) {
    List adjacents;
    init_list(&adjacents);

    for (int i = 1; i <= g.number_of_edges; ++i) {
        if (is_adjacent(g, i, vertex) && i != vertex) {
            append(&adjacents, i);
        }
    }

    return adjacents;
}
