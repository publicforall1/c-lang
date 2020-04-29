#include "min_heap.h"
#include <stdio.h>

void min_heapify(P_Queue* q, Node i) {
    Node l = left_child(*q, i);
    Node r = right_child(*q, i);
    Node smallest = i;

    if (l < q->size && q->keys[l].priority < q->keys[i].priority)
        smallest = l;
    if (r < q->size && q->keys[r].priority < q->keys[smallest].priority)
        smallest = r;
    if (smallest != i) {
        Key temp = q->keys[i];
        q->keys[i] = q->keys[smallest];
        q->keys[smallest] = temp;
        min_heapify(q, smallest);
    }
}

Key extract_min(P_Queue* q) {
    if (q->size == 1)
        return q->keys[--(q->size)];

    Key k = q->keys[0];
    q->keys[0] = q->keys[q->size - 1];
    --(q->size);
    min_heapify(q, 0);
    return k;
}

void build_min_heap(P_Queue* q) {
    for (int i = q->size / 2 - 1; i >= 0; --i)
        min_heapify(q, i);
}

void insert_min_heap(P_Queue* q, Key k) {
    q->keys[q->size++] = k;
    Node i = q->size - 1;

    Node p = parent(*q, i);
    while (i != 0 && q->keys[p].priority > q->keys[i].priority) {
        Key temp = q->keys[i];
        q->keys[i] = q->keys[p];
        q->keys[p] = temp;
        i = p;
        p = parent(*q, i);
    }
}

void print_min_heap_sort(P_Queue q) {
    printf("Sorted list: [ ");
    while (!is_empty_heap(q)) {
        Key k = extract_min(&q);
        printf("%d ", k.item);
    }
    printf("]\n");
} // O(n log n)
