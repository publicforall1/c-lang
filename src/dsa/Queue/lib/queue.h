#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define MAX_LENGTH 30

typedef int ElementType;

typedef struct {
   ElementType value[MAX_LENGTH];
   int front, rear;
} Queue;

void makenull_queue(Queue*);
bool is_empty_queue(Queue);
bool is_full_queue(Queue);
ElementType front_queue(Queue);
void enqueue(ElementType, Queue*);
void dequeue(Queue*);
void print_queue(Queue);

#endif
