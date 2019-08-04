/**
 * Program Name: Implement Selection Sort by my own way
 * Author: taiprogramer
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define size 20

void selection_sort(int arr[], int number_of_element, bool is_asc);
void swap(int* a, int* b);
void show_array(int arr[], int number_of_element);

int main(void) {

    int arr[size] = {17, 7, 6,  4, 18, 10, 13, 19, 9, 11,
                                   16, 5, 20, 8, 3,  15, 2,  12, 1, 14};
    printf("Origin Int Array: ");
    show_array(arr, size);
    selection_sort(arr, size, 1);
    printf("Ascending Int Array: ");
    show_array(arr, size);
    selection_sort(arr, size, 0);
    printf("Descending Int Array: ");
    show_array(arr, size);

    return 0;
}

void selection_sort(int arr[], int number_of_element, bool is_asc) {
    /**
     * @ Warning:
     * - Keep calm & read the code.
     * - is_asc: asc stands for ascending
     * 
     */
    int i = 0, j = 0;
    for (i = 0; i < number_of_element - 1; i++)
        for (j = i + 1; j < number_of_element; j++)
                is_asc 
                ? 
                (arr[j] < arr[i] ? swap(&arr[j], &arr[i]) : (void)1)
                :
                (arr[j] > arr[i] ? swap(&arr[j], &arr[i]) : (void)1);

}

void swap(int* a, int* b) {
    // using XOR operator
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void show_array(int arr[], int number_of_element) {
    int i = 0;
    while(i < number_of_element){
        printf("%d ", arr[i]);
        ++i;
    }
    printf("\n");
}
