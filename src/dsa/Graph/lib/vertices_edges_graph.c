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

void init_graph(Graph* G, int vertices, int edges) {
    G->number_of_vertices = vertices;
    G->number_of_edges = edges;

    for (int i = 1; i <= vertices; ++i) {
        for (int j = 1; j <= edges; ++j) {
            G->graph[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int edge, int vertex1, int vertex2) {
    G->graph[vertex1][edge] = 1;
    G->graph[vertex2][edge] = 1;
}

int is_adjacent(Graph G, int vertex1, int vertex2) {
    int ajacent = 0;
    for (int i = 1; i <= G.number_of_edges; ++i) {
        if (G.graph[vertex1][i] == 1 && G.graph[vertex2][i] == 1) {
            ajacent = 1;
        }
    }
    return ajacent;
}

int degree(Graph G, int vertex) {
    int d = 0;
    for (int i = 0; i <= G.number_of_edges; ++i) {
        if (G.graph[vertex][i] == 1) {
            ++d;
        }
    }
    return d;
}

List get_adjacents(Graph G, int vertex) {
    List adjacents;
    init_list(&adjacents);
    int temp[G.number_of_vertices + 1];

    for (int i = 1; i <= G.number_of_edges; ++i) {
        if (G.graph[vertex][i] == 1) {
            for (int j = 1; j <= G.number_of_vertices; ++j) {
                if (G.graph[j][i] == 1 && j != vertex) {
                    temp[j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= G.number_of_vertices; ++i) {
        if (temp[i] == 1) {
            append(&adjacents, i);
        }
    }

    return adjacents;
}
