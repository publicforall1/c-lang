#include <assert.h>
#include <limits.h>
#include <stdio.h>

int get_max(int num1, int num2);
int max_sum(int arr[], int last_index);

static int A[] = {0, 2, -3, 4, 5, -6, 7, -8, -5, 3, 9};
static int last_index = 10;

int main(int argc, char const* argv[]) {
    assert(max_sum(A, last_index) == 12);
    return 0;
}

int get_max(int num1, int num2) { return num1 > num2 ? num1 : num2; }

int max_sum(int arr[], int last_index) {
    int dp[last_index + 1], max;
    dp[0] = max = arr[0];
    for (int i = 1; i <= last_index; i++) {
        dp[i] = get_max(arr[i], dp[i - 1] + arr[i]);
        max = dp[i] > max ? dp[i] : max;
    }
    return max;
}
