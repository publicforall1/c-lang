#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define MAX_LENGTH_OF_QUEUE 100

typedef int Queue_ElementType;

typedef struct {
    Queue_ElementType value[MAX_LENGTH_OF_QUEUE];
    int front, rear;
} Queue;

void makenull_queue(Queue*);
bool is_empty_queue(Queue);
bool is_full_queue(Queue);
Queue_ElementType front_queue(Queue);
void enqueue(Queue_ElementType, Queue*);
void dequeue(Queue*);
void print_queue(Queue);

#endif
