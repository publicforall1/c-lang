/**
 * Warning: This test is only valid with Ni Graph.
 *
 */

#include "lib/directed_graph/vertices_vertices_graph.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Graph load_graph(const char* file_name);
void test_degree(Graph g);
void test_get_adjacents(Graph g);
void test_dfs(Graph g);
void test_dfs_using_stack(Graph g);
void test_bfs_using_queue(Graph g);
void test_is_connected(Graph g);

int main(void) {
    printf(
        "** Directed graph :: Implement using vertices-vertices matrix **\n\n");
    printf("-> Testing implementation...\n");
    Graph g = load_graph("./data/ni_graph.txt");
    test_degree(g);
    test_get_adjacents(g);
    test_dfs(g);
    test_dfs_using_stack(g);
    test_bfs_using_queue(g);
    test_is_connected(g);
    printf("-> Everything works great! Thanks to taiprogramer!\n\n");
    return 0;
}

Graph load_graph(const char* file_name) {
    Graph g;
    FILE* fp = freopen(file_name, "rt", stdin);
    if (fp == NULL) {
        perror("Can not open file");
        exit(0);
    }
    int vertices, edges;
    scanf("%d%d", &vertices, &edges);
    init_graph(&g, vertices, edges);
    for (int i = 1; i <= edges; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add_edge(&g, i, x, y);
    }
    return g;
}

void test_degree(Graph g) {
    assert(out_degree(g, 1) == 2);
    assert(out_degree(g, 2) == 1);
    assert(out_degree(g, 3) == 1);
    assert(out_degree(g, 4) == 2);
    assert(out_degree(g, 5) == 2);

    assert(in_degree(g, 1) == 1);
    assert(in_degree(g, 2) == 2);
    assert(in_degree(g, 3) == 2);
    assert(in_degree(g, 4) == 1);
    assert(in_degree(g, 5) == 2);

    assert(degree(g, 1) == 3);
    assert(degree(g, 2) == 3);
    assert(degree(g, 3) == 3);
    assert(degree(g, 4) == 3);
    assert(degree(g, 5) == 4);
}

void test_get_adjacents_run_test(Graph g, int start_vertex,
                                 int adjacent_result[]) {
    List l = get_adjacents(g, start_vertex);
    for (int i = 1; i <= length(l); ++i)
        assert(adjacent_result[i - 1] == value_at(l, i));
}

void test_get_adjacents(Graph g) {
    int neighbor_of_1[2] = {2, 5};
    int neighbor_of_2[1] = {4};
    int neighbor_of_3[1] = {1};
    int neighbor_of_4[3] = {3, 5};
    int neighbor_of_5[4] = {2, 3};

    test_get_adjacents_run_test(g, 1, neighbor_of_1);
    test_get_adjacents_run_test(g, 2, neighbor_of_2);
    test_get_adjacents_run_test(g, 3, neighbor_of_3);
    test_get_adjacents_run_test(g, 4, neighbor_of_4);
    test_get_adjacents_run_test(g, 5, neighbor_of_5);
}

void test_dfs_run_test(Graph g, int start_vertex, int dfs_result[]) {
    List trav;
    init_list(&trav);
    dfs(&g, start_vertex, &trav);
    for (int i = 1; i <= length(trav); ++i)
        assert(value_at(trav, i) == dfs_result[i - 1]);
}

void test_dfs(Graph g) {

    int dfs_1[5] = {1, 2, 4, 3, 5};
    int dfs_2[5] = {2, 4, 3, 1, 5};
    int dfs_3[5] = {3, 1, 2, 4, 5};
    int dfs_4[5] = {4, 3, 1, 2, 5};
    int dfs_5[5] = {5, 2, 4, 3, 1};

    test_dfs_run_test(g, 1, dfs_1);
    test_dfs_run_test(g, 2, dfs_2);
    test_dfs_run_test(g, 3, dfs_3);
    test_dfs_run_test(g, 4, dfs_4);
    test_dfs_run_test(g, 5, dfs_5);
}

void test_dfs_using_stack_run_test(Graph g, int start_vertex,
                                   int dfs_result[]) {
    List trav;
    init_list(&trav);
    dfs_using_stack(&g, start_vertex, &trav);
    for (int i = 1; i <= length(trav); ++i)
        assert(value_at(trav, i) == dfs_result[i - 1]);
}

void test_dfs_using_stack(Graph g) {
    int dfs_1[5] = {1, 5, 3, 2, 4};
    int dfs_2[5] = {2, 4, 5, 3, 1};
    int dfs_3[5] = {3, 1, 5, 2, 4};
    int dfs_4[5] = {4, 5, 3, 1, 2};
    int dfs_5[5] = {5, 3, 1, 2, 4};

    test_dfs_using_stack_run_test(g, 1, dfs_1);
    test_dfs_using_stack_run_test(g, 2, dfs_2);
    test_dfs_using_stack_run_test(g, 3, dfs_3);
    test_dfs_using_stack_run_test(g, 4, dfs_4);
    test_dfs_using_stack_run_test(g, 5, dfs_5);
}

void test_bfs_using_queue_run_test(Graph g, int start_vertex,
                                   int dfs_result[]) {
    List trav;
    init_list(&trav);
    bfs_using_queue(&g, start_vertex, &trav);
    for (int i = 1; i <= length(trav); ++i)
        assert(value_at(trav, i) == dfs_result[i - 1]);
}

void test_bfs_using_queue(Graph g) {
    int dfs_1[5] = {1, 2, 5, 4, 3};
    int dfs_2[5] = {2, 4, 3, 5, 1};
    int dfs_3[5] = {3, 1, 2, 5, 4};
    int dfs_4[5] = {4, 3, 5, 1, 2};
    int dfs_5[5] = {5, 2, 3, 4, 1};

    test_bfs_using_queue_run_test(g, 1, dfs_1);
    test_bfs_using_queue_run_test(g, 2, dfs_2);
    test_bfs_using_queue_run_test(g, 3, dfs_3);
    test_bfs_using_queue_run_test(g, 4, dfs_4);
    test_bfs_using_queue_run_test(g, 5, dfs_5);
}

void test_is_connected(Graph g) { assert(is_connected(g) == 1); }
