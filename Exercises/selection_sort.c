/**
 * Program Name: Implement Selection Sort by my own way
 * Author: taiprogramer
 */
#include <stdio.h>
#include <string.h>
#define size_of_array 20

void selection_sort(int intArray[], int number_of_element, char* mode);
void swap(int* firstNumber, int* secondNumber);
void getArray(int intArray[], int number_of_element);
void printArray(int intArray[], int number_of_element);

int main(void) {

  int intArray[size_of_array] = {17, 7, 6,  4, 18, 10, 13, 19, 9, 11,
                                 16, 5, 20, 8, 3,  15, 2,  12, 1, 14};
  printf("Origin Int Array: ");
  printArray(intArray, size_of_array);
  selection_sort(intArray, size_of_array, "asc");
  printf("Ascending Int Array: ");
  printArray(intArray, size_of_array);
  selection_sort(intArray, size_of_array, "des");
  printf("Descending Int Array: ");
  printArray(intArray, size_of_array);

  return 0;
}

void selection_sort(int intArray[], int number_of_element, char* mode) {
  for (int beforeIndex = 0; beforeIndex < number_of_element - 1; beforeIndex++)
    for (int afterIndex = beforeIndex + 1; afterIndex < number_of_element;
         afterIndex++)
      if (strcmp(mode, "asc") == 0) {
        if (intArray[afterIndex] < intArray[beforeIndex])
          swap(&intArray[afterIndex], &intArray[beforeIndex]);
      } else if (strcmp(mode, "des") == 0) {
        if (intArray[afterIndex] > intArray[beforeIndex])
          swap(&intArray[afterIndex], &intArray[beforeIndex]);
      }
};

void swap(int* firstNumber, int* secondNumber) {
  int temp = *firstNumber;
  *firstNumber = *secondNumber;
  *secondNumber = temp;
};

void getArray(int intArray[], int number_of_element) {
  for (int i = 0; i < number_of_element; i++)
    scanf("%d", &intArray[i]);
};

void printArray(int intArray[], int number_of_element) {
  for (int i = 0; i < number_of_element; i++)
    printf("%d ", intArray[i]);
  printf("\n");
};
