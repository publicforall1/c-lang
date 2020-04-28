#include "priority_queue.h"

void init_heap(P_Queue* q) { q->index = -1; }

int is_empty_heap(P_Queue q) { return q.index == -1; }

Node left_child(P_Queue q, Node n) { return 2 * n + 1; }

Node right_child(P_Queue q, Node n) { return 2 * n + 2; }

Node parent(P_Queue q, Node n) { return (n - 1) / 2; }

int is_valid_node(P_Queue q, Node n) { return (n >= 0 && n <= q.index); }
