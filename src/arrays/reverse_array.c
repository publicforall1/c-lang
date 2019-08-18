#include <stdio.h>

void swap(int* a, int* b);
void reverse_array(int arr[], int size);
void get_input(int arr[], int size);
void show_array(int arr[], int size);

int main(void) {
    int size;
    printf("Enter number of element: ");
    scanf("%d", &size);

    int arr[size];
    get_input(arr, size);
    reverse_array(arr, size);
    show_array(arr, size);
}

void swap(int* a, int* b) {
    // using XOR operator
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void reverse_array(int arr[], int size) {
    int i = 0, half_size = size / 2;
    while (i < half_size) {
        swap(&arr[i], &arr[size - 1 - i]);
        ++i;
    }
}

void get_input(int arr[], int size) {
    int i = 0;
    while (i < size) {
        scanf("%d", &arr[i]);
        ++i;
    }
}

void show_array(int arr[], int size) {
    int i = 0;
    while (i < size) {
        printf("%d ", arr[i]);
        ++i;
    }
    printf("\n");
}

/**
 * Reverse Array
 * valid input: array have number of elements (n) greater than zero.
 * 5 7 6 8
 * -> 8 6 7 5
 * 3 8 1 4 7 -> 7 4 1 8 3
 * find center element (n / 2)
 * swap element in left-hand side with element at right-hand side
 *      arr[i] vs arr[n - 1 - i]
 *
 *
 */
