#include "assert.h"
#include "lib/vertices_vertices_graph.h"
#include <stdio.h>

/* Undirected - Graph
1 - 2
| \ |
3 - 4
*/

Graph setup_graph();

int main(void) {
    printf("Test vertices - vertices graph");
    Graph g = setup_graph();
    List adjacents_of_1 = get_adjacents(g, 1);
    List adjacents_of_2 = get_adjacents(g, 2);
    List adjacents_of_3 = get_adjacents(g, 3);

    assert(degree(g, 1) == 3);
    assert(degree(g, 2) == 2);
    assert(degree(g, 3) == 2);
    assert(degree(g, 4) == 3);

    assert(is_adjacent(g, 1, 2) == 1);
    assert(is_adjacent(g, 2, 1) == 1);
    assert(is_adjacent(g, 2, 3) == 0);
    assert(is_adjacent(g, 2, 4) == 1);
    assert(is_adjacent(g, 4, 2) == 1);

    // adjacents_of_1 test
    assert(value_at(adjacents_of_1, 1) == 2);
    assert(value_at(adjacents_of_1, 2) == 3);
    assert(value_at(adjacents_of_1, 3) == 4);

    // adjacents_of_2 test
    assert(value_at(adjacents_of_2, 1) == 1);
    assert(value_at(adjacents_of_2, 2) == 4);

    // adjacents_of_3 test
    assert(value_at(adjacents_of_3, 1) == 1);
    assert(value_at(adjacents_of_3, 2) == 4);
    printf(" -> Done\n");
    return 0;
}

Graph setup_graph() {
    Graph g;
    init_graph(&g, 4);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 4);
    return g;
}
