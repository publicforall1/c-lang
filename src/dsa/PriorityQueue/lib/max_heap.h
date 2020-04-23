#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include "priority_queue.h"

typedef P_Queue MaxHeap;

void init_heap(P_Queue* q);              // O(1)
int is_empty_heap(P_Queue q);                 // O(1)
Node left_child(P_Queue q, Node n);      // O(1)
Node right_child(P_Queue q, Node n);     // O(1)
Node parent(P_Queue q, Node n);          // O(1)
int is_valid_node(P_Queue q, Node n);    // O(1)
void max_heapify(P_Queue* q, Node n);    // O(log n)
Key extract_max(P_Queue* q);             // O(log n)
void build_max_heap(P_Queue* q);         // O(n log n)
void insert_max_heap(P_Queue* q, Key k); // O(log n)
void print_max_heap_sort(P_Queue q);     // O(n log n)

#endif