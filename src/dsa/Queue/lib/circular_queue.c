#include "circular_queue.h"
#include <stdbool.h>
#include <stdio.h>

void makenull_queue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool is_empty_queue(Queue queue) { return queue.front == -1; }

bool is_full_queue(Queue queue) {
    return ((queue.rear - queue.front + 1) % MAX_LENGTH_OF_QUEUE) == 0;
}

Queue_ElementType front_queue(Queue queue) {
    if (!is_empty_queue(queue))
        return queue.value[queue.front];

    printf("front_queue: queue is empty.\n");
}

void enqueue(Queue_ElementType element, Queue* queue) {
    if (is_full_queue(*queue)) {
        printf("enqueue: queue is full.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_LENGTH_OF_QUEUE;
    queue->value[queue->rear] = element;

    if (is_empty_queue(*queue))
        queue->front++;
}

void dequeue(Queue* queue) {
    if (is_empty_queue(*queue)) {
        printf("dequeue: queue is empty.\n");
        return;
    }

    if (queue->front == queue->rear) {
        makenull_queue(queue);
        return;
    }

    queue->front = (queue->front + 1) % MAX_LENGTH_OF_QUEUE;
}

void print_queue(Queue queue) {
    printf("[ ");
    while (!is_empty_queue(queue)) {
        printf("%d ", front_queue(queue));
        dequeue(&queue);
    }
    printf("]\n");
}
