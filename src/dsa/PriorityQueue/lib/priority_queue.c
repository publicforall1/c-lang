#include "priority_queue.h"

void init_heap(P_Queue* q) { q->length = 0; }

int is_empty_heap(P_Queue q) { return q.length == 0; }

Node left_child(P_Queue q, Node n) { return 2 * n + 1; }

Node right_child(P_Queue q, Node n) { return 2 * n + 2; }

Node parent(P_Queue q, Node n) { return (n - 1) / 2; }

int is_valid_node(P_Queue q, Node n) { return (n > -1 && n < q.length); }

