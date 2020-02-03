// Implementing directed graph using list of adjacents
//
// V [], []
// e [], []
// r [], []
// t [], []
// e [], []
// x [], []

#include "list_adjacent_graph.h"
#include <stdio.h>

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

List get_adjacents(Graph g, int vertex) {
    List adjacents;
    init_list(&adjacents);

    for (int i = 1; i <= g.number_of_vertices; ++i) {
        if (is_adjacent(g, vertex, i) && i != vertex) {
            append(&adjacents, i);
        }
    }

    return adjacents;
} // O(n^2)

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
