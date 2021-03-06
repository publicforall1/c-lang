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
#include <stdio.h>

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
