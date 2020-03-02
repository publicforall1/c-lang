#ifndef PRIORITY_QUEUE_H

#define PRIORITY_QUEUE_H

#define MAX_NUMBER_OF_NODES 100

typedef int Node;
typedef int Key;

typedef struct {
    Key keys[MAX_NUMBER_OF_NODES];
    int length;
} P_Queue;

#endif