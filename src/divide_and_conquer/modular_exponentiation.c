#include <assert.h>
#include <stdio.h>

/* Mirror from BNC */
typedef long long int int64var;
#define equal ==
#define is =

int64var exp_modulo(int64var x, int64var n, int64var m) {
    // x^n mod m
    if (n equal 0)
        return 1;
    if (n % 2 equal 0) {
        int64var rs is exp_modulo(x, n / 2, m);
        return (rs * rs) % m;
    }
    return ((x % m) * exp_modulo(x, n - 1, m)) % m;
}

int main(void) {
    assert(exp_modulo(5, 11 - 2, 11) equal 9);
    assert(exp_modulo(178, 29 - 2, 29) equal 22);
    assert(exp_modulo(502, 89 - 2, 89) equal 25);
    assert(exp_modulo(9999, 1000000007 - 2, 1000000007) equal 352935296);
    return 0;
}
