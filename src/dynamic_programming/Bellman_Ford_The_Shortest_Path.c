// Bellman Ford - The Shortest Path
// Written by taiprogramer.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 999
#define MAX_EDGES 1000

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int n_of_edges;
    int n_of_vertices;
} DirectedGraph;

void init_graph(DirectedGraph* g, int n_of_vertices, int n_of_edges);
void add_edge(DirectedGraph* g, int u, int v, int w);
int* Bellman_Ford_The_Shortest_Path(DirectedGraph g, int source);
DirectedGraph load_graph(const char* file_name);
int test_Bellman_Ford(const char* file_name);

int main(int argc, char const* argv[]) {
    assert(test_Bellman_Ford(
               "input/Bellman_Ford_The_Shortest_Path/BmFo1.inp") == 0);
    assert(test_Bellman_Ford(
               "input/Bellman_Ford_The_Shortest_Path/BmFo2.inp") == 1);
    return 0;
}

void init_graph(DirectedGraph* g, int n_of_vertices, int n_of_edges) {
    g->n_of_vertices = n_of_vertices;
    g->n_of_edges = 0;
}

void add_edge(DirectedGraph* g, int u, int v, int w) {
    g->edges[g->n_of_edges].u = u;
    g->edges[g->n_of_edges].v = v;
    g->edges[g->n_of_edges].w = w;
    g->n_of_edges++;
}

int* Bellman_Ford_The_Shortest_Path(DirectedGraph g, int source) {
    // [success]: return an array represent shortest path from `source` to
    // all vertices.
    // [fail - have negative cycle]: return NULL

    // vertex start from 1
    // initial step
    int* distance = (int*)malloc(sizeof(int) * (g.n_of_vertices + 1));
    for (int u = 1; u <= g.n_of_vertices; u++) {
        distance[u] = INF;
    }
    distance[source] = 0;
    // loop
    for (int v = 1; v <= g.n_of_vertices; v++) {
        for (int i = 0; i < g.n_of_edges; i++) {
            Edge e = g.edges[i];
            if (distance[e.u] + e.w < distance[e.v]) {
                distance[e.v] = distance[e.u] + e.w;
            }
        }
    }
    // check negative cycle
    for (int i = 0; i < g.n_of_edges; i++) {
        Edge e = g.edges[i];
        if (distance[e.u] + e.w < distance[e.v]) {
            free(distance);
            return NULL;
        }
    }
    return distance;
}

DirectedGraph load_graph(const char* file_name) {
    FILE* fp = fopen(file_name, "rt");
    if (fp == NULL) {
        exit(0);
    }
    DirectedGraph g;
    int n_of_vertices, n_of_edges;
    fscanf(fp, "%d%d", &n_of_vertices, &n_of_edges);
    init_graph(&g, n_of_vertices, n_of_edges);
    for (int i = 0; i < n_of_edges; ++i) {
        int u, v, w;
        fscanf(fp, "%d%d%d", &u, &v, &w);
        add_edge(&g, u, v, w);
    }
    fclose(fp);
    return g;
}

int test_Bellman_Ford(const char* file_name) {
    // [success: found cycle] return 1
    // [fail]: return 0
    DirectedGraph g = load_graph(file_name);
    int* distance = Bellman_Ford_The_Shortest_Path(g, 1);
    if (distance == NULL)
        return 1;
    free(distance);
    return 0;
}
