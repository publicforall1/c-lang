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

int have_cycle(Graph g) {
    int recursion_stack[g.vertices + 1];
    Stack s;
    makenull_stack(&s);
    push_stack(1, &s);

    while (!is_empty_stack(s)) {
        int vertex = top_stack(s);
        pop_stack(&s);

        if (g.visited[vertex] == VISITED)
            continue;

        // Do anything you want with single node/vertex
        g.visited[vertex] = VISITED;
        recursion_stack[vertex] = 1;
        List adjacents = get_adjacents(g, vertex);
        for (int i = 1; i <= length(adjacents); ++i) {
            int v = value_at(adjacents, i);
            push_stack(v, &s);
            if (recursion_stack[v] == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int min(int a, int b) { return a < b ? a : b; }

void dfs_for_Tarjan(Graph* g, int vertex, Stack* s, int on_stack[], int* k) {
    if (g->visited[vertex] == VISITED)
        return;

    g->visited[vertex] = VISITED;
    push_stack(vertex, s);
    on_stack[vertex] = 1;
    g->lowlink[vertex] = *k;
    g->time[vertex] = *k;
    *k = *k + 1;
    List adjacents = get_adjacents(*g, vertex);
    for (int i = 1; i <= length(adjacents); ++i) {
        int v = value_at(adjacents, i);
        if (on_stack[v] == 1) {
            g->lowlink[vertex] = min(g->lowlink[v], g->lowlink[vertex]);
            break;
        }
        dfs_for_Tarjan(g, v, s, on_stack, k);
    }
}

int Tarjan_find_sccs(Graph g) {
    // return: no. strongly connected components

    int on_stack[g.vertices + 1];
    int k = 1;
    int count = 0;

    for (int i = 1; i <= g.vertices; ++i) {
        if (g.visited[i] == VISITED)
            continue;

        Stack s;
        makenull_stack(&s);
        for (int i = 1; i <= g.vertices; ++i)
            on_stack[i] = 0;

        dfs_for_Tarjan(&g, i, &s, on_stack, &k);

        if (!is_empty_stack(s))
            ++count;
    }

    return count;
}

void add_weight(Graph* g, int x, int y, int weight) {
    g->weight[x][y] = weight;
}

void Dijkstra_find_and_set_distance(Graph* g, int source_vertex) {
    int size = g->vertices + 1;
    int marked[size];
    int num_mark = 0;
    for (int i = 1; i <= g->vertices; ++i)
        g->distance[i] = INFINITY;

    for (int i = 1; i <= g->vertices; ++i)
        marked[i] = 0;

    g->distance[source_vertex] = 0;
    marked[source_vertex] = 1;
    ++num_mark;
    List neighbor = get_adjacents(*g, source_vertex);
    for (int i = 1; i <= length(neighbor); ++i) {
        int v = value_at(neighbor, i);
        g->distance[v] = g->weight[source_vertex][v];
    }

    while (num_mark < g->vertices) {
        // find min weight of unmark node
        int w = INFINITY;
        int new_source_vertex;
        for (int i = 1; i <= g->vertices; ++i) {
            if (marked[i])
                continue;

            if (g->distance[i] < w) {
                w = g->distance[i];
                new_source_vertex = i;
            }
        }
        // mark new_source_vertex as marked
        marked[new_source_vertex] = 1;
        List neighbor = get_adjacents(*g, new_source_vertex);
        for (int i = 1; i <= length(neighbor); ++i) {
            int v = value_at(neighbor, i);
            int min_value =
                min(g->distance[v], g->weight[new_source_vertex][v] +
                                        g->distance[new_source_vertex]);
            g->distance[v] = min_value;
        }
        ++num_mark;
    }
}
