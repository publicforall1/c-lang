#include "assert.h"
#include "lib/vertices_edges_graph.h"
#include <stdio.h>

int main(void) {
    FILE* fp = freopen("./data/graph.txt", "rt", stdin);
    // Check null
    if (!fp)
        return 0;

    int number_of_vertices, number_of_edges;
    scanf("%d%d", &number_of_vertices, &number_of_edges);

    Graph g;
    init_graph(&g, number_of_vertices, number_of_edges);

    for (int i = 1; i <= number_of_edges; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add_edge(&g, i, x, y);
    }
    // setup visited
    int visited[number_of_vertices + 1];
    for (int i = 1; i <= number_of_vertices; ++i)
        visited[i] = 0;

    // dfs(g, 1, visited);
    // dfs_using_stack(g, 1, visited);
    // bfs_using_queue(g, 1, visited);

    fclose(fp);
    return 0;
}
