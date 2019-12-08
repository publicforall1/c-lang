#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define MAX_LENGTH_OF_QUEUE 100

typedef int Queue_ElementType;

typedef struct Circular_Queue {
    Queue_ElementType value[MAX_LENGTH_OF_QUEUE];
    int front, rear;
} Queue;

#include "queue_common.h" // include common function prototypes

#endif
