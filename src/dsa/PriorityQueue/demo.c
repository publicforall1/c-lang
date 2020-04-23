#include "lib/max_heap.h"
#include "lib/min_heap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEST_ELEMENT 10000

void testMaxHeap();
void testMinHeap();

int main(void) {
    testMaxHeap();
    testMinHeap();
    return 0;
}

void testMaxHeap() {
    srand(time(NULL));
    MaxHeap max_heap;
    init_heap(&max_heap);

    for (int i = 0; i < MAX_TEST_ELEMENT; ++i) {
        Key k;
        k.x = rand();
        printf("insert element %d/%d...\n", i + 1, MAX_TEST_ELEMENT);
        insert_max_heap(&max_heap, k);
    }

    int i = 0;
    int max_value;
    if (!is_empty_heap(max_heap)) {
        max_value = extract_max(&max_heap).x;
        printf("test extract max %d/%d...\n", ++i, MAX_TEST_ELEMENT);
    }

    while (!is_empty_heap(max_heap)) {
        printf("test extract max %d/%d...\n", ++i, MAX_TEST_ELEMENT);
        Key k = extract_max(&max_heap);
        assert(k.x <= max_value);
        max_value = k.x;
    }
}

void testMinHeap() {
    srand(time(NULL));
    MinHeap min_heap;
    init_heap(&min_heap);

    for (int i = 0; i < MAX_TEST_ELEMENT; ++i) {
        Key k;
        k.x = rand();
        printf("insert element %d/%d...\n", i + 1, MAX_TEST_ELEMENT);
        insert_min_heap(&min_heap, k);
    }

    int i = 0;
    int min_value;
    if (!is_empty_heap(min_heap)) {
        min_value = extract_min(&min_heap).x;
        printf("test extract min %d/%d...\n", ++i, MAX_TEST_ELEMENT);
    }

    while (!is_empty_heap(min_heap)) {
        printf("test extract min %d/%d...\n", ++i, MAX_TEST_ELEMENT);
        Key k = extract_min(&min_heap);
        assert(k.x >= min_value);
        min_value = k.x;
    }
}

