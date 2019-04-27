// checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code"

#include "testcase.h"
#include <stdio.h>

int get_gcd(int a, int b);

int main(void) {

  test2IntToInt(get_gcd, "Testcase/gcd.txt");

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

// *-* Pseudo Code *-*
/* Find Greatest Common Divisor using Euclid Alogrithm

Expected Sample:
a = 15, b = 10
15 % 10 = 5
10 % 5 = 0
-> gcd = 5
---------------
a = 24, b = 36
36 % 24 = 12
24 % 12 = 0
-> gcd = 12
---------------
a = 18, b = 24
24 % 18 = 6
18 % 6 = 0
-> gcd = 6
---------------
Solution:
Ensure that input number is always positive number, if not,
change it into positive
// change number to positive
a = a < 0 ? a - 2 * a : a
b = b < 0 ? b - 2 * b : b
Ensure that 2 number is not equal to 0, if one of them equal 0,
gcd = another number, if they are both equal to 0 then,
printf("Ask any girl!"); Because girl is very difficult to understand :D
if (a == 0 && b == 0)
    printf("Ask any girl!");
else if (a == 0)
    gcd = b
else if (b == 0)
    gcd = a
else{
    // euclid divisor algorithm
    while(a % b != 0)
        gcd = a % b
        a = b
        b = gcd
}
*/
