// [calculate n! mod m]
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
// MAX_M = 10^9 + 7
#define MAX_M 1000000007
// [mirror from bnc]
typedef long long int int64var;

int64var factorial_mod(int n, int m, int64var memo[]);
void exit_if_null(void* ptr);

int main(int argc, char const* argv[]) {
    int64var memo[MAX_N];
    factorial_mod(MAX_N, MAX_M, memo);
    FILE* test_file_p = fopen("input/n_fact_mod_m.txt", "rt");
    exit_if_null(test_file_p);
    for (int i = 0; i < MAX_N; i++) {
        int64var expected, actual;
        fscanf(test_file_p, "%lld", &expected);
        actual = memo[i];
        assert(expected == actual);
    }
    fclose(test_file_p);
    return 0;
}

int64var factorial_mod(int n, int m, int64var memo[]) {
    // [$memo[n] store result of $n! % $m]
    // [equation: `n! % m = ((n % m) * ((n - 1)! % m)) % m`]
    // [constraint: `n >= 0 and n < MAX_N, m >= 0 and m <= MAX_M; ..
    // [.. memo[] capacity is MAX_N`]
    // base case
    if (n == 0) {
        memo[0] = 1 % m;
        return memo[0];
    }
    memo[n] = ((n % m) * factorial_mod(n - 1, m, memo)) % m;
    return memo[n];
}

void exit_if_null(void* ptr) {
    if (ptr == NULL) {
        exit(0);
    }
}
