#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mixup_array(char* chars);

int main(void) {

    char chars[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char force_char;
    int position_of_force_char, normal_number;

    // mix up array for perfect trick
    mixup_array(chars);

    // get setup character from magician
    printf("Enter character you want to force (A - J): ");
    scanf("%c", &force_char);

    // clear screen to start perform trick
    system("@cls||clear");

    // show welcome screen
    printf("------ Welcome To My Trick ------\n");

    // get number from audience
    printf("Type any number between 0 and 9: ");
    scanf("%d", &position_of_force_char);
    printf("\n-----------------------> %c\n", force_char);

    // find force_char in array, swap position
    for (int i = 0; i < 10; i++) {
        if (chars[i] == force_char) {
            char temp = chars[position_of_force_char];
            chars[position_of_force_char] = force_char;
            chars[i] = temp;
            // do break to make sure only 1 case.
            break;
        }
    }

    // infinity loop for magic
    while (1) {
        printf("\nType any number between 0 and 9: ");
        scanf("%d", &normal_number);
        if (normal_number == -1)
            break;
        printf("\n-----------------------> %c\n", chars[normal_number]);
    }

    return 0;
}

void mixup_array(char* chars) {

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        // get random number from 0 to 9
        int r = rand() % 10;
        // swap chars[i] with chars[r]
        char temp = chars[i];
        chars[i] = chars[r];
        chars[r] = temp;
    }
};

/* Magic :: Guess Character
User type any number between 0 and 9 -> Print character between A - J
*/