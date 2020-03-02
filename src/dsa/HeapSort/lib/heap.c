#include "heap.h"
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} // O(1)

int is_leaf(P_Queue q, Node x) {
    Node left = 2 * x;
    Node right = 2 * x + 1;
    return (left > q.length || right > q.length);
} // O(1)

void init_heap(P_Queue* q) { q->length = 0; } // O(1)

void append_heap(P_Queue* q, Key k) {
    q->length++;
    q->keys[q->length] = k;
} // O(1)

Key max(P_Queue q) { return q.keys[1]; } // O(1)

Key extract_max(P_Queue* q) {
    Key max_value = q->keys[1];
    q->keys[1] = q->keys[q->length];
    q->length--;
    max_heapify(q, 1);
    return max_value;
} // O(log n)

void max_heapify(P_Queue* q, Node x) {
    if (is_leaf(*q, x)) {
        return;
    }

    Node left = 2 * x;
    Node right = 2 * x + 1;

    Key left_key = q->keys[left];
    Key right_key = q->keys[right];

    Node largest = left_key > right_key ? left : right;
    Key* p_largest_key = &(q->keys[largest]);
    Key* p_x_key = &(q->keys[x]);

    if (*p_largest_key > *p_x_key) {
        swap(p_largest_key, p_x_key);
        max_heapify(q, largest);
    }
} // O(log n)

void build_max_heap(P_Queue* q) {
    for (int i = q->length / 2; i >= 1; --i) {
        max_heapify(q, i);
    }
} // O(n log n)

void increase_key(P_Queue* q, Node x, Key k) {
    q->keys[x] = k;
    Node parent = x / 2;
    max_heapify(q, parent);
} // O(log n)

void print_heap_sort(P_Queue q) {
    printf("Sorted list: [ ");
    while (q.length != 0) {
        printf("%d ", extract_max(&q));
    }
    printf("]\n");
} // O(n log n)

void show_heap(P_Queue q) {
    printf("# Start P_Queue\n");
    for (int i = 1; i <= q.length; ++i) {
        printf("Node: %d -> Key: %d\n", i, q.keys[i]);
    }
    printf("# End P_Queue\n");
} // O(n)
