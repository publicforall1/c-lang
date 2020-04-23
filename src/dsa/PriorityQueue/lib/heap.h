#ifndef HEAP_H
#define HEAP_H
#include "priority_queue.h"

void init_heap(P_Queue* q);                   // O(1)
int is_leap(P_Queue q, Node x);               // O(1)
void append_heap(P_Queue* q, Key k);          // O(1)
void max_heapify(P_Queue* q, Node x);         // O(log n)
void build_max_heap(P_Queue* q);              // O(n log n)
Key max(P_Queue q);                           // O(1)
Key extract_max(P_Queue* q);                  // O(log n)
void increase_key(P_Queue* q, Node x, Key k); // O(log n)
void print_heap_sort(P_Queue q);              // O(n log n)
void show_heap(P_Queue q);                    // O(n)

#endif