/* checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code" */

#include <stdio.h>

int reverse_number(int n);

int main(void) { 
    int n;
    while(1){
        printf("Enter your number: ");
        scanf("%d", &n);
        printf("Your reverse number is %d.\n", reverse_number(n));
    }
    return 0; 
}

int reverse_number(int n) {
    int result = 0;
    while (n != 0) {
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}

/* ============ Pseudo Code ============ */
/* Reverse Number
Expected Sample:
123 -> 321
5768 -> 8657
9876 -> 6789
HandTouched:
result = 0
123 % 10 = 3 (result * 10 + 3 = 3)
123 / 10 = 12

12 % 10 = 2 (result * 10 + 2 = 32)
12 / 10 = 1

1 % 10 = 1 (result * 10 + 1 = 321)
1 / 10 = 0 -> break

while(n != 0):
    result = result * 10 + n % 10
    n /= 10

*/
