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
// - Trust me! It really works.

#include "vertices_edges_graph.h"
#include <stdio.h>

void init_graph(Graph* g, int vertices, int edges) {
    g->vertices = vertices;
    g->edges = edges;

    for (int i = 1; i <= vertices; ++i) {
        for (int j = 1; j <= edges; ++j)
            g->graph[i][j] = 0;
    }
} // O(vertices * edges)

void add_edge(Graph* g, int edge, int vertex1, int vertex2) {
    g->graph[vertex1][edge] = 1;
    g->graph[vertex2][edge] = 1;
} // O(1)

int is_adjacent(Graph g, int vertex1, int vertex2) {
    for (int i = 1; i <= g.edges; ++i)
        if (g.graph[vertex1][i] == 1 && g.graph[vertex2][i] == 1)
            return 1;

    return 0;
} // O(n)

int degree(Graph g, int vertex) {
    int d = 0;
    for (int i = 1; i <= g.edges; ++i)
        d += g.graph[vertex][i];
    return d;
} // O(n)

List get_adjacents(Graph g, int vertex) {
    List adjacents;
    init_list(&adjacents);

    for (int i = 1; i <= g.vertices; ++i)
        if (is_adjacent(g, i, vertex) && i != vertex)
            append(&adjacents, i);

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

int is_connected(Graph g) {
    List trav;
    init_list(&trav);
    dfs(&g, 1, &trav);
    return length(trav) == g.vertices;
}

void find_and_set_parent(Graph* g) {
    for (int i = 1; i <= g->vertices; ++i)
        g->parent[i] = -1;

    for (int i = 1; i <= g->vertices; ++i) {
        List neighbor = get_adjacents(*g, i);
        for (int j = 1; j <= length(neighbor); ++j) {
            int vertex = value_at(neighbor, j);
            if (g->parent[vertex] == -1) {
                g->parent[vertex] = i;
            }
        }
    }
    g->parent[1] = -1;
}

int have_cycle(Graph g) {
    find_and_set_parent(&g);
    Stack s;
    makenull_stack(&s);
    push_stack(1, &s);

    while (!is_empty_stack(s)) {
        int vertex = top_stack(s);
        pop_stack(&s);

        if (g.visited[vertex] == VISITED)
            continue;

        g.visited[vertex] = VISITED;
        List adjacents = get_adjacents(g, vertex);
        for (int i = 1; i <= length(adjacents); ++i) {
            int v = value_at(adjacents, i);
            push_stack(value_at(adjacents, i), &s);
            if (g.visited[v] == VISITED && g.parent[vertex] != v) {
                return 1;
            }
        }
    }
    return 0;
}

int min(int a, int b) { return a < b ? a : b; }

void add_weight(Graph* g, int x, int y, int weight) {
    g->weight[x][y] = weight;
    g->weight[y][x] = weight;
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
