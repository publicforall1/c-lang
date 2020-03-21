#include "ni_marco.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b);
int partition(int array[], int left, int right);   // O(n)
void quick_sort(int array[], int left, int right); // O(n log n) // O(n^2)
void test_quick_sort();

int main(void) {

    test_quick_sort();

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right) {
    int pivot = array[left];
    int i = left, j = right;

    while (i < j) {
        while (array[i] <= pivot && i <= right)
            ++i;

        while (array[j] > pivot && j >= left)
            --j;

        if (i < j)
            swap(&(array[i]), &(array[j]));
    }

    swap(&(array[left]), &(array[j]));
    return j;
} // O(n)

void quick_sort(int array[], int left, int right) {
    if (left >= right)
        return;

    int pivot = partition(array, left, right);
    quick_sort(array, left, pivot - 1);
    quick_sort(array, pivot + 1, right);
} // O(n log n) // O(n^2)

void test_quick_sort() {
    srand(time(NULL));
    int array[ONE_MILION];
    // generate array of random numbers
    for (int i = 0; i < ONE_MILION; ++i)
        array[i] = rand();

    quick_sort(array, 0, ONE_MILION - 1);

    for (int i = 0; i < ONE_MILION - 1; ++i)
        assert(array[i] <= array[i + 1]);
}
