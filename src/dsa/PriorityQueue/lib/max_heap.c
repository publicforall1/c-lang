#include "max_heap.h"
#include <stdio.h>

void max_heapify(P_Queue* q, Node n) {
    Node l = left_child(*q, n);
    Node r = right_child(*q, n);

    Node node_with_largest_key = n;

    if (is_valid_node(*q, l))
        node_with_largest_key = l;

    if (is_valid_node(*q, r)) {
        if (q->keys[r].x > q->keys[node_with_largest_key].x)
            node_with_largest_key = r;
    }

    if (q->keys[n].x < q->keys[node_with_largest_key].x) {
        Key temp = q->keys[n];
        q->keys[n] = q->keys[node_with_largest_key];
        q->keys[node_with_largest_key] = temp;
        max_heapify(q, node_with_largest_key);
    }
}

Key extract_max(P_Queue* q) {
    Key k = q->keys[0];
    Node last_node = q->length - 1;
    q->keys[0] = q->keys[last_node];
    q->length = q->length - 1;
    max_heapify(q, 0); // O(log n)
    return k;
}

void build_max_heap(P_Queue* q) {
    for (int i = q->length / 2 - 1; i >= 0; --i) {
        max_heapify(q, i);
    }
}

void insert_max_heap(P_Queue* q, Key k) {
    q->keys[q->length] = k;
    Node n = q->length;
    q->length++;

    while (n > 0) {
        Node p = parent(*q, n);
        if (q->keys[n].x <= q->keys[p].x)
            break;

        Key temp = q->keys[n];
        q->keys[n] = q->keys[p];
        q->keys[p] = temp;
        n = p;
    }
}

void print_max_heap_sort(P_Queue q) {
    printf("Sorted list: [ ");
    while (q.length != 0) {
        Key k = extract_max(&q);
        printf("%d ", k.x);
    }
    printf("]\n");
} // O(n log n)
