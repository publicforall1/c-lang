#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include "priority_queue.h"

typedef P_Queue MinHeap;

void min_heapify(P_Queue* q, Node n);    // O(log n)
Key extract_min(P_Queue* q);             // O(log n)
void build_min_heap(P_Queue* q);         // O(n log n)
void insert_min_heap(P_Queue* q, Key k); // O(log n)
void print_min_heap_sort(P_Queue q);     // O(n log n)

#endif
