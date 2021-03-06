#ifndef PRIORITY_QUEUE_H

#define PRIORITY_QUEUE_H

#define MAX_NUMBER_OF_NODES 100000

typedef struct {
    int item;
    int priority;
} Key;

typedef struct {
    Key keys[MAX_NUMBER_OF_NODES];
    int size;
} P_Queue;

typedef int Node;

void init_heap(P_Queue* q);          // O(1)
int is_empty_heap(P_Queue q);        // O(1)
Node left_child(P_Queue q, Node i);  // O(1)
Node right_child(P_Queue q, Node i); // O(1)
Node parent(P_Queue q, Node i);      // O(1)

#endif
