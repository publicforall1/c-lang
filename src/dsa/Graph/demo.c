#include "assert.h"
// #include "lib/vertices_edges_graph.h" // (1)
#include "lib/vertices_vertices_graph.h" // (2)
#include <stdio.h>

/* Undirected - Graph
1 - 2
| \ |
3 - 4
*/

Graph setup_vertices_edges_graph();
Graph setup_vertices_vertices_graph();

int main(void) {

    // Graph g = setup_vertices_edges_graph(); // (1)
    Graph g = setup_vertices_vertices_graph(); // (2)

    assert(degree(g, 1) == 3);
    assert(degree(g, 2) == 2);
    assert(is_adjacent(g, 1, 2) == 1);
    assert(is_adjacent(g, 2, 3) == 0);

    return 0;
}

// // (1)
// Graph setup_vertices_edges_graph() {
//     Graph g;
//     init_graph(&g, 4, 5);
//     add_edge(&g, 1, 1, 2);
//     add_edge(&g, 2, 1, 3);
//     add_edge(&g, 3, 1, 4);
//     add_edge(&g, 4, 2, 4);
//     add_edge(&g, 5, 3, 4);
//     return g;
// }

// (2)
Graph setup_vertices_vertices_graph() {
    Graph g;
    init_graph(&g, 4);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 4);
    return g;
}
