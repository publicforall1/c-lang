// checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code"

#include "testcase.h"
#include <math.h>
#include <stdio.h>

int isPrime(int number);

int main(void) {

    testIntToInt(isPrime, "Testcase/prime_number.txt");

    return 0;
}

int isPrime(int number) {
    int flag = 1;

    // validate input
    if (number < 2)
        return 0;

    for (int i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            flag = 0;
    return flag;
}
// Pseudo Code
/* Check Prime Number Or Not
Expected Sample:
1 -> 0 (False)
2 -> 1 (True)
3 -> 1
4 -> 0
5 -> 1
6 -> 0

for(int i = 2; i <= sqrt(number); i++):
    if (n % i == 0)
        flag = 0;

*/
