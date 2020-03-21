#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000 // 1 milion

void merge(int array[], int left, int middle, int right); // O(m + n)
void merge_sort(int array[], int left, int right);        // O(n log n)
void test_merge_sort();

int main(void) {

    test_merge_sort();

    return 0;
}

void merge(int array[], int left, int middle, int right) {
    // first array: left -> middle
    // second array: middle + 1 -> right
    int i = left;
    int j = middle + 1;
    int k = 0;
    int temp_result_array[right - left + 1];

    while (i <= middle && j <= right) {
        if (array[i] <= array[j]) {
            temp_result_array[k++] = array[i++];
            continue;
        }
        if (array[i] > array[j]) {
            temp_result_array[k++] = array[j++];
            continue;
        }
    }
    for (; i <= middle; ++i)
        temp_result_array[k++] = array[i];

    for (; j <= right; ++j)
        temp_result_array[k++] = array[j];

    // copy result array to original array
    for (int offset = 0; offset < k; ++offset)
        array[left + offset] = temp_result_array[offset];
} // O(m + n)

void merge_sort(int array[], int left, int right) {
    if (left >= right)
        return;

    int middle = (left + right) / 2;
    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);
    merge(array, left, middle, right);
}

void test_merge_sort() {
    srand(time(NULL));
    int array[MAX_SIZE];
    // generate array of random numbers
    for (int i = 0; i < MAX_SIZE; ++i)
        array[i] = rand();

    merge_sort(array, 0, MAX_SIZE - 1);

    for (int i = 0; i < MAX_SIZE - 1; ++i)
        assert(array[i] <= array[i + 1]);
}

// respect to my history
// void merge(int first_array[], int first_length, int second_array[],
//            int second_length, int result_array[]) {
//     int i, j, k;
//     i = j = k = 0;
//     while (i < first_length && j < second_length) {
//         if (first_array[i] <= second_array[j]) {
//             result_array[k++] = first_array[i++];
//             continue;
//         }

//         if (first_array[i] > second_array[j]) {
//             result_array[k++] = second_array[j++];
//             continue;
//         }
//     }
//     for (; i < first_length; ++i)
//         result_array[k++] = first_array[i];

//     for (; j < second_length; ++j)
//         result_array[k++] = second_array[j];
// } // O(first_length + second_length)
