#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// [macros]
// change this value at your own risk.
#define MAX_NUMBER_OF_FIB 68
// [bnc]
typedef long long int int64var;
#define equal ==

void init_fib_array(int64var fib_arr[]);
int64var fib(int p, int64var fib_arr[]);

int main(int argc, char const* argv[]) {
    int64var fib_arr[MAX_NUMBER_OF_FIB];
    init_fib_array(fib_arr);
    FILE* test_file_p = fopen("input/fib.txt", "rt");
    if (test_file_p == NULL) {
        printf("Can not open test file.\n");
        exit(0);
    }
    for (size_t p = 0; p < MAX_NUMBER_OF_FIB; p++) {
        int64var expected, actual;
        fscanf(test_file_p, "%lld", &expected);
        actual = fib(p, fib_arr);
        assert(expected equal actual);
    }
    fclose(test_file_p);
    return 0;
}

void init_fib_array(int64var fib_arr[]) {
    for (size_t i = 0; i < MAX_NUMBER_OF_FIB; i++) {
        fib_arr[i] = -1;
    }
    fib_arr[0] = 0;
    fib_arr[1] = 1;
}

int64var fib(int p, int64var* fib_arr) {
    // [get fib at $p position, start from 0]
    // [fib(0) == 0; fib(1) == 1]
    if (p < 2)
        return fib_arr[p];
    if (fib_arr[p] != -1)
        return fib_arr[p];
    fib_arr[p] = fib(p - 1, fib_arr) + fib(p - 2, fib_arr);
    return fib_arr[p];
}
