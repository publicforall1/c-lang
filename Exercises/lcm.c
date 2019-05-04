// checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code"

#include "testcase.h"
#include <stdio.h>

int get_gcd(int a, int b);
int get_lcm(int a, int b);

int main(void) {

    test2IntToInt(get_lcm, "Testcase/lcm.txt");

    return 0;
}

int get_gcd(int a, int b) {
    int gcd;
    // change number to positive number
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    // swap a, b if a > b, because algorithm works great when a < b;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    if (a == 0 && b == 0)
        printf("Ask any girl!");
    else if (a == 0)
        gcd = b;
    else if (b == 0)
        gcd = a;
    else {
        // from here both a & b is positive and not equal to 0
        while (a % b != 0) {
            gcd = a % b;
            a = b;
            b = gcd;
        }
    }
    return gcd;
};

int get_lcm(int a, int b) { return (a * b) / get_gcd(a, b); };

// -*- Pseudo Code -*-
/* Find Least Common Mutiple
lcm(a, b) = (a * b) / gcd(a, b);
*/