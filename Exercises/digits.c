// checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code"

#include "testcase.h"
#include <stdio.h>

int getNumberOfDigits(int n);

int main(void) {

    testIntToInt(getNumberOfDigits, "Testcase/digits.txt");

    return 0;
}

int getNumberOfDigits(int n) {
    int numberOfDigit = 1;
    while (n / 10 != 0) {
        numberOfDigit++;
        n /= 10;
    }
    return numberOfDigit;
}
// Pseudo Code
/* Find number of digits
Expected Sample:
0 -> 1
123 -> 3
9999 -> 4
12345 -> 5
HandTouched:
123.touch()
numberOfDigit = 1
123 / 10 = 12 numberOfDigit++
12 / 10 = 1 numberOfDigit++
1 / 10 = 0 -> break
Solution:
while(n / 10 != 0):
    numberOfDigit++
    n /= 10

*/