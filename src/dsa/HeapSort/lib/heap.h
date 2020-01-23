#ifndef HEAP_H
#define HEAP_H
#include "priority_queue.h"

typedef P_Queue Heap;

void init_heap(Heap* h); // O(1)
int is_leap(Heap h, Node x); // O(1)
void append_heap(Heap* h, Key k); // O(1)
void max_heapify(Heap* h, Node x); // O(log n)
void build_max_heap(Heap* h); // O(n log n)
Key max(Heap h); // O(1)
Key extract_max(Heap* h); // O(log n)
void increase_key(Heap* h, Node x, Key k); // O(log n)
void print_heap_sort(Heap h); // O(n log n)
void show_heap(Heap h); // O(n)

#endif