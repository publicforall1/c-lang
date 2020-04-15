/**
 * Program Name: Implement Interchange Sort by my own way
 * Author: taiprogramer
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10000

void interchange_sort(int arr[], int number_of_element, bool is_asc);
void swap(int* a, int* b);
void show_array(int arr[], int number_of_element);
void test_interchange_sort();

int main(void) {

    test_interchange_sort();

    return 0;
}

void test_interchange_sort() {
    srand(time(NULL));
    int arr[SIZE];

    // generate random number
    for (int i = 0; i < SIZE; ++i)
        arr[i] = rand();

    interchange_sort(arr, SIZE, 1); // sort by ascending
    for (int i = 0; i < SIZE - 1; ++i)
        assert(arr[i] <= arr[i + 1]);

    interchange_sort(arr, SIZE, 0); // sort by descending
    for (int i = 0; i < SIZE - 1; ++i)
        assert(arr[i] >= arr[i + 1]);
}

void interchange_sort(int arr[], int number_of_element, bool is_asc) {
    /**
     * @ Warning:
     * - Keep calm & read the code.
     * - is_asc: asc stands for ascending
     *
     */
    int i = 0, j = 0;
    for (i = 0; i < number_of_element - 1; i++)
        for (j = i + 1; j < number_of_element; j++)
            is_asc ? (arr[j] < arr[i] ? swap(&arr[j], &arr[i]) : (void)1)
                   : (arr[j] > arr[i] ? swap(&arr[j], &arr[i]) : (void)1);
}

void swap(int* a, int* b) {
    // using XOR operator
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void show_array(int arr[], int number_of_element) {
    int i = 0;
    while (i < number_of_element) {
        printf("%d ", arr[i]);
        ++i;
    }
    printf("\n");
}
