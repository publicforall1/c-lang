/* checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code" */

#include <stdio.h>

int reverse_number(int number);

int main(void) { return 0; }

int reverse_number(int number) {
    int numberReversed = 0;
    while (number != 0) {
        numberReversed = numberReversed * 10 + number % 10;
        number /= 10;
    }
    return numberReversed;
}

/* ============ Pseudo Code ============ */
/* Reverse Number
Expected Sample:
123 -> 321
5768 -> 8657
9876 -> 6789
HandTouched:
numberReversed = 0
123 % 10 = 3 (numberReversed * 10 + 3 = 3)
123 / 10 = 12

12 % 10 = 2 (numberReversed * 10 + 2 = 32)
12 / 10 = 1

1 % 10 = 1 (numberReversed * 10 + 1 = 321)
1 / 10 = 0 -> break

while(n != 0):
    numberReversed = numberReversed * 10 + n % 10
    n /= 10

*/