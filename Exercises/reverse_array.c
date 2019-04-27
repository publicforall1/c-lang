#include <stdio.h>
#define arr_length 5

void swap(int* a, int* b);
void reverse_array(int arr[], int number_of_element);
void show_array(int arr[], int number_of_element);

int main(void) {
  int arr[arr_length] = {5, 7, 6, 8, 1};
  reverse_array(arr, arr_length);
  show_array(arr, arr_length);
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
};

void reverse_array(int arr[], int number_of_element) {
  for (int i = 0; i < number_of_element / 2; i++) {
    swap(&arr[i], &arr[number_of_element - 1 - i]);
  }
};

void show_array(int arr[], int number_of_element) {
  for (int i = 0; i < number_of_element; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
};

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
