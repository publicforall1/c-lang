/* Minimum spanning tree :: Kruskal's algorithm */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Unimportant things, you can ignore it. */
#define CAN_T_DO_ANYTHING "We can't do anything.\n"
#define STILL_EXIT_WITH_SUCCESS_CODE "Program is still exit with 0 code.\n"
#define OUT_OF_MEMORY "Because OUT OF MEMORY\n"
#define CAN_NOT_OPEN_FILE "Because CAN NOT OPEN FILE\n"
/* Unimportant things, you can ignore it. */

typedef struct {
    int a, b, w; // node: a, b ; weight: w
} Edge;

int comparator(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->w - e2->w;
}

int find(int parent[], int v) {
    if (parent[v] == -1)
        return v;
    return find(parent, parent[v]);
}

void my_union(int parent[], int u, int v) { parent[v] = u; }

int find_cost(const char* file_name) {
    // map stdin with file*
    FILE* fp = freopen(file_name, "rt", stdin);

    if (fp == NULL) {
        printf(
            CAN_T_DO_ANYTHING CAN_NOT_OPEN_FILE STILL_EXIT_WITH_SUCCESS_CODE);
        exit(0);
    }

    int n, m; // m: number of edges, n: number of vertices;
    scanf("%d%d", &n, &m);
    Edge* edges = (Edge*)malloc(sizeof(Edge) * (m));

    if (edges == NULL) {
        printf(CAN_T_DO_ANYTHING OUT_OF_MEMORY STILL_EXIT_WITH_SUCCESS_CODE);
        exit(0);
    }

    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);

    fclose(fp);
    // sort edges by ascending order (weight)
    qsort(edges, m, sizeof(Edge), comparator);

    // init parent array as Disjoint Set
    int* parent = (int*)malloc(sizeof(int) * (n + 1)); // vertex is count from 1
    for (int i = 1; i <= n; ++i)
        parent[i] = -1;

    int min_cost = 0;
    for (int i = 0; i < m; ++i) {
        Edge e = edges[i];
        int a_position = find(parent, e.a);
        int b_position = find(parent, e.b);

        if (a_position != b_position) {
            my_union(parent, a_position, b_position);
            min_cost += e.w;
        }
    }

    free(parent);
    free(edges);
    return min_cost;
}

int main(void) {
    assert(find_cost("./input/Kruskal/kruskal01.inp") == 19);
    assert(find_cost("./input/Kruskal/kruskal03.inp") == 52);
    return 0;
}
