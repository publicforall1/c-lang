#include "priority_queue.h"

void init_heap(P_Queue* q) { q->size = 0; }

int is_empty_heap(P_Queue q) { return q.size == 0; }

Node left_child(P_Queue q, Node i) { return 2 * i + 1; }

Node right_child(P_Queue q, Node i) { return 2 * i + 2; }

Node parent(P_Queue q, Node i) { return (i - 1) / 2; }
