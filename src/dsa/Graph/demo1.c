#include "lib/list_adjacent_graph.h"
#include <assert.h>

int main(void) {

    Graph g;
    init_graph(&g, 4);

    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 4);

    assert(degree(g, 1) == 3);
    assert(degree(g, 2) == 3);
    assert(is_adjacent(g, 1, 2) == 1);
    assert(is_adjacent(g, 4, 1) == 0);

    return 0;
}