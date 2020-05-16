#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b);
int max_3num(int a, int b, int c);
int max_cross_sum(int arr[], int last_index);
int max_sum(int arr[], int last_index);

#define SIZE 10000

int main(int argc, char const* argv[]) {

    srand(time(NULL));
    int arr[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        arr[i] = rand();

    max_sum(arr, SIZE - 1);

    return 0;
}

int max(int a, int b) { return a > b ? a : b; }
int max_3num(int a, int b, int c) { return max(max(a, b), c); }

int max_cross_sum(int arr[], int last_index) {
    int sum = 0;
    int left_sum = INT_MIN;
    int mid = last_index / 2;
    for (int i = mid; i >= 0; --i) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= last_index; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return max_3num(left_sum + right_sum, left_sum, right_sum);
}

int max_sum(int arr[], int last_index) {
    if (last_index == 0) {
        return arr[0];
    }
    int mid = last_index / 2;
    // call max-sum on left-side
    int left = max_sum(arr, mid);
    // call max-sum on right-side
    int right = max_sum(arr + mid + 1, last_index - mid - 1);
    // call max-sum that cross middle point
    int cross = max_cross_sum(arr, last_index);
    return max_3num(left, right, cross);
}
