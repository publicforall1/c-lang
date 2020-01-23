#include "heap.h"
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} // O(1)

int is_leaf(Heap h, Node x) {
    Node left = 2 * x;
    Node right = 2 * x + 1;
    return (left > h.length || right > h.length);
} // O(1)

void init_heap(Heap* h) { h->length = 0; } // O(1)

void append_heap(Heap* h, Key k) {
    h->length++;
    h->keys[h->length] = k;
} // O(1)

Key max(Heap h) { return h.keys[1]; } // O(1)

Key extract_max(Heap* h) {
    Key max_value = h->keys[1];
    h->keys[1] = h->keys[h->length];
    h->length--;
    max_heapify(h, 1);
    return max_value;
} // O(log n)

void max_heapify(Heap* h, Node x) {
    if (is_leaf(*h, x)) {
        return;
    }

    Node left = 2 * x;
    Node right = 2 * x + 1;

    Key left_key = h->keys[left];
    Key right_key = h->keys[right];

    Node largest = left_key > right_key ? left : right;
    Key* p_largest_key = &(h->keys[largest]);
    Key* p_x_key = &(h->keys[x]);

    if (*p_largest_key > *p_x_key) {
        swap(p_largest_key, p_x_key);
        max_heapify(h, largest);
    }
} // O(log n)

void build_max_heap(Heap* h) {
    for (int i = h->length / 2; i >= 1; --i) {
        max_heapify(h, i);
    }
} // O(n log n)

void increase_key(Heap* h, Node x, Key k) {
    h->keys[x] = k;
    Node parent = x / 2;
    max_heapify(h, parent);
} // O(log n)

void print_heap_sort(Heap h) {
    printf("Sorted list: [ ");
    while (h.length != 0) {
        printf("%d ", extract_max(&h));
    }
    printf("]\n");
} // O(n log n)

void show_heap(Heap h) {
    printf("# Start Heap\n");
    for (int i = 1; i <= h.length; ++i) {
        printf("Node: %d -> Key: %d\n", i, h.keys[i]);
    }
    printf("# End Heap\n");
} // O(n)
