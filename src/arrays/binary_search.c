/**
 * Binary Search
 * - work on sorted array
 * - full explanation: CS50 Binary Search [Youtube Video]
 *
 */

#include <stdio.h>

int binary_search(int arr[], int start, int end, int lookup_value);

int binary_search(int arr[], int start, int end, int lookup_value) {
    /**
     * @return index of element if found, else return -1;
     *
     */
    if (start > end)
        return -1;

    int middle = (start + end) / 2;

    if (arr[middle] == lookup_value)
        return middle;

    if (lookup_value > arr[middle])
        return binary_search(arr, middle + 1, end, lookup_value);
    else
        return binary_search(arr, start, middle - 1, lookup_value);
}