#include <stdio.h>

void print_star(int number_of_star);
void print_space(int number_of_space);

int main(void) {

    int height;
    scanf("%d", &height);

    int number_of_star = 1;
    int number_of_space = (height - 1) * 3;

    while (number_of_space >= 0) {
        print_space(number_of_space);
        print_star(number_of_star);
        number_of_space -= 3;
        number_of_star += 2;
    }

    return 0;
}

void print_star(int number_of_star) {
    if (number_of_star == 1)
        printf("*");
    else
        for (int i = 0; i < number_of_star; i++)
            printf("*  ");

    printf("\n");
};

void print_space(int number_of_space) {
    for (int i = 0; i < number_of_space; i++)
        printf(" ");
};

// Pseudo Code
/* Print Isosceles triangle

Example:
3
      *     // 6 spaces + 1 star
   *  *  *    // 3 spaces + 1 star + 2 spaces + 1 star + 2 spaces + 1 star
*  *  *  *  * // 0 spaces + 1 star...

4
         *      // 9 spaces
      *  *  *   // 6 spaces
   *  *  *  *  *  // 3 spaces
*  *  *  *  *  *  * // 0 spaces

5
            * // 12 spaces
         *  *  *  // 9 spaces
      *  *  *  *  *  // 6 spaces
   *  *  *  *  *  *  *  // 3 spaces
*  *  *  *  *  *  *  *  * // 0 spaces

*/