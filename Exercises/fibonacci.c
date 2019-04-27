// checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code"

#include <stdio.h>
#include <stdlib.h>

void validateInput(int n);
void printFibSequence(int* fibSequence, int fibLength, char* separateChar);

int main() {
  int n;

  printf("How many numbers you want to see: ");
  scanf("%d", &n);

  validateInput(n);

  // malloc for n integers
  int* fibSequence = (int*)malloc(n * sizeof(int));
  if (fibSequence == NULL) {
    fprintf(stderr, "Error: Cannot allocation memory.");
    exit(0);
  }
  // init first, second number of fibonacci sequence
  *fibSequence = 0;
  *(fibSequence + 1) = 1;

  // start from third element
  for (int i = 2; i < n; i++)
    *(fibSequence + i) = *(fibSequence + i - 1) + *(fibSequence + i - 2);

  printFibSequence(fibSequence, n, ", ");

  free(fibSequence);
  return 0;
}

void validateInput(int n) {
  if (n < 1) {
    fprintf(stderr, "n less than 1");
    exit(0);
  } else if (n == 1) {
    printf("%d", 0); // first number of fibonacci sequence
    exit(0);
  }
}

void printFibSequence(int* fibSequence, int fibLength, char* separateChar) {
  for (int i = 0; i < fibLength; i++) {
    printf("%d", *(fibSequence + i));
    // if not last character, add separateChar to it
    if (i < fibLength - 1)
      printf("%s", separateChar);
  }
}
// *-* Pseudo Code *-*
/* Fibonacci Numbers Generate

stdin: integer denote how many numbers user want to print out screen.
stdout: Fibonacci Sequence
    0 1 1 2 3 5 8
solution:
    get(n)
    fibPointer = memory allocation n integers
    init first, second value;
    for i in range(n):
        if (i == 0 or i == 1)
            pass
        *(fibPointer + i) = *(fibPointer + i - 1) + *(fibPointer + i - 2)


resource: https://en.wikipedia.org/wiki/Fibonacci_number

*/