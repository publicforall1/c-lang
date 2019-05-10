/**
 * Program Name: Pascal's Triangle
 * Decription: Print Pascal's triangle based on number of rows
 * Author: taiprogramer
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    /* 2D array -> good solution at this time
    // great input : 0 < n < 41 */
    int i, j;
    unsigned int n;
    long arr[40][40];

    printf("Enter height: ");
    scanf("%u", &n);

    /* validate input for safety */
    if (n < 1 || n > 40) {
        printf("\nBad Signal :: Number of rows\n");
        exit(1);
    }

    /* Step 1: initial values for 2 first rows
    // all elements of two first rows will be 1
    // 1 x xxxxxxxxxxxxxxxx
    // 1 1 xxxxxxxxxxxxxxxx */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < i + 1; j++) {
            arr[i][j] = 1;
        }
    }

    /* calculate value for all rows remainder
    // if n > 2, do this block */
    for (i = 2; i < n; i++) {
        for (j = 0; j < i + 1; j++) {
            /* if first or last element of row -> set this value equal to 1 */
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
    }
    /* ============ Print Triangle ============ */
    for (i = 0; i < n; i++) {
        for (j = 0; j < i + 1; j++) {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    }
}

/* Pascal's Triangle Form
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
... */
