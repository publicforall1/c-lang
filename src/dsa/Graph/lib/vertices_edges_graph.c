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
#include <stdio.h>

void init_graph(Graph* g, int vertices, int edges) {
    g->number_of_vertices = vertices;
    g->number_of_edges = edges;

    for (int i = 1; i <= vertices; ++i) {
        for (int j = 1; j <= edges; ++j) {
            g->graph[i][j] = 0;
        }
    }

    for (int i = 1; i <= vertices; ++i) {
        g->visited[i] = 0;
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

    for (int i = 1; i <= g.number_of_vertices; ++i) {
        if (is_adjacent(g, i, vertex) && i != vertex) {
            append(&adjacents, i);
        }
    }

    return adjacents;
}

void mark_visited(Graph* g, int vertex) { g->visited[vertex] = 1; }

int is_visited(Graph g, int vertex) { return g.visited[vertex]; }

void dfs(Graph* g, int start) {
    if (is_visited(*g, start)) {
        return;
    }

    // Do anything you want with single node/vertex
    // printf("\n%d", start);
    mark_visited(g, start);

    List adjacents = get_adjacents(*g, start);
    for (int i = 1; i <= length(adjacents); ++i) {
        int vertex = value_at(adjacents, i);
        dfs(g, vertex);
    }
}

void reset_visted(Graph* g) {
    for (int i = 1; i <= g->number_of_vertices; ++i) {
        g->visited[i] = 0;
    }
} // O(n)

void dfs_using_stack(Graph* g, int start) {
    Stack s;
    makenull_stack(&s);
    push_stack(start, &s);

    while (!is_empty_stack(s)) {
        int vertex = top_stack(s);
        pop_stack(&s);

        if (!is_visited(*g, vertex)) {
            // Do anything you want with single node/vertex
            // printf("\n%d", vertex);
            mark_visited(g, vertex);
            List adjacents = get_adjacents(*g, vertex);
            for (int i = 1; i <= length(adjacents); ++i) {
                push_stack(value_at(adjacents, i), &s);
            }
        }
    }
}

void bfs_using_queue(Graph* g, int start) {
    Queue q;
    makenull_queue(&q);
    enqueue(start, &q);

    while (!is_empty_queue(q)) {
        int vertex = front_queue(q);
        dequeue(&q);

        if (!is_visited(*g, vertex)) {
            // Do anything you want with single node/vertex
            // printf("\n%d", vertex);
            mark_visited(g, vertex);
            List adjacents = get_adjacents(*g, vertex);
            for (int i = 1; i <= length(adjacents); ++i) {
                enqueue(value_at(adjacents, i), &q);
            }
        }
    }
}
