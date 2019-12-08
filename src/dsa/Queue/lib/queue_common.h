/* This file store common function prototypes that every type of queue will have */

#include <stdbool.h>
void makenull_queue(Queue*);
bool is_empty_queue(Queue);
bool is_full_queue(Queue);
Queue_ElementType front_queue(Queue);
void enqueue(Queue_ElementType, Queue*);
void dequeue(Queue*);
void print_queue(Queue);

