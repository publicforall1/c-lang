#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include "priority_queue.h"

typedef P_Queue MaxHeap;

void max_heapify(P_Queue* q, Node i);    // O(log n)
Key extract_max(P_Queue* q);             // O(log n)
void build_max_heap(P_Queue* q);         // O(n log n)
void insert_max_heap(P_Queue* q, Key k); // O(log n)
void print_max_heap_sort(P_Queue q);     // O(n log n)

#endif
