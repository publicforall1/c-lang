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

void init_graph(Graph* G, int vertices, int edges) {
    G->vertices = vertices;
    for (int i = 1; i <= vertices; ++i) {
        for (int j = 1; j <= vertices; j++) {
            G->matrix[i][j] = 0;
        }
    }
} // O(vertices ^2)

void add_edge(Graph* G, int edge, int vertex1, int vertex2) {
    G->matrix[vertex1][vertex2] += 1;
} // O(1)

int is_adjacent(Graph G, int vertex1, int vertex2) {
    return G.matrix[vertex1][vertex2] > 0;
} // O(1)

int in_degree(Graph g, int vertex) {
    int deg = 0;
    for (int i = 1; i <= g.vertices; ++i)
        deg += g.matrix[i][vertex];

    return deg;
} // O(n)

int out_degree(Graph g, int vertex) {
    int deg = 0;
    for (int i = 1; i <= g.vertices; ++i)
        deg += g.matrix[vertex][i];

    return deg;
} // O(n)

int degree(Graph g, int vertex) {
    return in_degree(g, vertex) + out_degree(g, vertex);
} // O(n)

List get_adjacents(Graph g, int vertex) {
    List adjacents;
    init_list(&adjacents);

    for (int i = 1; i <= g.vertices; ++i) {
        if (is_adjacent(g, vertex, i) && i != vertex) {
            append(&adjacents, i);
        }
    }

    return adjacents;
} // O(n)

void reset_visited(Graph* g) {
    int i = 1;
    while (i <= g->vertices)
        g->visited[i++] = UNVISITED;
} // O(n)

void dfs(Graph* g, int vertex, List* traversal) {
    if (g->visited[vertex] == VISITED)
        return;

    append(traversal, vertex);
    g->visited[vertex] = VISITED;
    List adjacents = get_adjacents(*g, vertex);
    for (int i = 1; i <= length(adjacents); ++i) {
        int v = value_at(adjacents, i);
        dfs(g, v, traversal);
    }
}

void dfs_using_stack(Graph* g, int start_vertex, List* traversal) {
    Stack s;
    makenull_stack(&s);
    push_stack(start_vertex, &s);

    while (!is_empty_stack(s)) {
        int vertex = top_stack(s);
        pop_stack(&s);

        if (g->visited[vertex] == VISITED)
            continue;

        // Do anything you want with single node/vertex
        append(traversal, vertex);
        g->visited[vertex] = VISITED;
        List adjacents = get_adjacents(*g, vertex);
        for (int i = 1; i <= length(adjacents); ++i)
            push_stack(value_at(adjacents, i), &s);
    }
}

void bfs_using_queue(Graph* g, int start_vertex, List* traversal) {
    Queue q;
    makenull_queue(&q);
    enqueue(start_vertex, &q);

    while (!is_empty_queue(q)) {
        int vertex = front_queue(q);
        dequeue(&q);

        if (g->visited[vertex] == VISITED)
            continue;

        // Do anything you want with single node/vertex
        append(traversal, vertex);
        g->visited[vertex] = VISITED;
        List adjacents = get_adjacents(*g, vertex);
        for (int i = 1; i <= length(adjacents); ++i)
            enqueue(value_at(adjacents, i), &q);
    }
}

Graph reverse_direction(Graph g) {
    for (int i = 1; i <= g.vertices; ++i) {
        for (int j = 1; j <= g.vertices; ++j) {
            if (j == i)
                continue;

            if (g.matrix[i][j] > 0) {
                g.matrix[j][i] = g.matrix[i][j];
                g.matrix[i][j] = 0;
            }
        }
    }
    return g;
} // O(n^2)

int is_connected(Graph g) {
    Graph g1 = g;
    Graph g2 = reverse_direction(g); // O(n^2)
    List trav;                       // it's not important
    init_list(&trav);
    dfs(&g1, 1, &trav);
    dfs(&g2, 1, &trav);
    for (int i = 1; i <= g.vertices; ++i) {
        if (g1.visited[i] == UNVISITED && g2.visited[i] == UNVISITED)
            return 0;
    }
    return 1;
} // O(n^2)
