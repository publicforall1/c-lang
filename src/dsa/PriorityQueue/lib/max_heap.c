#include "max_heap.h"
#include <stdio.h>

void max_heapify(P_Queue* q, Node i) {
    Node l = left_child(*q, i);
    Node r = right_child(*q, i);
    Node largest = i;

    if (l < q->size && q->keys[l].priority > q->keys[i].priority)
        largest = l;
    if (r < q->size && q->keys[r].priority > q->keys[largest].priority)
        largest = r;
    if (largest != i) {
        Key temp = q->keys[i];
        q->keys[i] = q->keys[largest];
        q->keys[largest] = temp;
        max_heapify(q, largest);
    }
}

Key extract_max(P_Queue* q) {
    Key k = q->keys[0];
    q->keys[0] = q->keys[q->size - 1];
    --(q->size);
    max_heapify(q, 0);
    return k;
}

void build_max_heap(P_Queue* q) {
    for (int i = q->size / 2 - 1; i >= 0; --i)
        max_heapify(q, i);
}

void insert_max_heap(P_Queue* q, Key k) {
    q->keys[q->size++] = k;
    Node i = q->size - 1;

    Node p = parent(*q, i);
    while (i != 0 && q->keys[p].priority < q->keys[i].priority) {
        Key temp = q->keys[i];
        q->keys[i] = q->keys[p];
        q->keys[p] = temp;
        i = p;
        p = parent(*q, i);
    }
}

void print_max_heap_sort(P_Queue q) {
    printf("Sorted list: [ ");
    while (!is_empty_heap(q)) {
        Key k = extract_max(&q);
        printf("%d ", k.item);
    }
    printf("]\n");
} // O(n log n)
