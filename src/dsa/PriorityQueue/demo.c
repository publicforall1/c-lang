#include "lib/max_heap.h"
#include "lib/min_heap.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEST_ELEMENT 1000

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
        k.item = rand();
        k.priority = k.item;
        insert_max_heap(&max_heap, k);
    }

    int min_value = INT_MAX;
    while (!is_empty_heap(max_heap)) {
        Key k = extract_max(&max_heap);
        assert(k.item <= min_value);
        min_value = k.item;
    }
}

void testMinHeap() {
    srand(time(NULL));
    MinHeap min_heap;
    init_heap(&min_heap);

    for (int i = 0; i < MAX_TEST_ELEMENT; ++i) {
        Key k;
        k.item = rand() % 10;
        k.priority = k.item;
        insert_min_heap(&min_heap, k);
    }

    int max_value = INT_MIN;
    while (!is_empty_heap(min_heap)) {
        Key k = extract_min(&min_heap);
        assert(k.item >= max_value);
        max_value = k.item;
    }
}
