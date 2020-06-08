#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string();
int is_even(char c_num);
void exit_if_null(void* resource);
int count_even_num_in_string(const char* s, int i, int memo[], int str_len);

const char* test_case = "4645557347476";
const int test_case_result[] = {6, 5, 4, 3, 3, 3, 3, 3, 3, 2, 2, 1, 1};

int main(int argc, char const* argv[]) {
    // uncomment if you want to get user input from keyboard
    // char* s = get_string();
    // exit_if_null(s);

    int str_len = strlen(test_case);
    int memo[str_len];
    count_even_num_in_string(test_case, 0, memo, str_len);
    for (int i = 0; i < str_len; i++) {
        int expected, actual;
        expected = test_case_result[i];
        actual = memo[i];
        assert(expected == actual);
    }

    // free(s);
    return 0;
}

char* get_string() {
    char input_buffer[10005];
    fgets(input_buffer, 10005, stdin);
    input_buffer[strlen(input_buffer) - 1] = '\0';
    char* r = (char*)malloc(sizeof(char) * (strlen(input_buffer) + 1));
    strcpy(r, input_buffer);
    return r;
}

int is_even(char c_num) {
    // check if char $num is even
    // [sucess: return 1]
    // [fali: return 0]
    // convert char to int
    int num = c_num - 48;
    return num % 2 == 0;
}

void exit_if_null(void* resource) {
    if (resource == NULL)
        exit(0);
}

int count_even_num_in_string(const char* s, int i, int memo[], int str_len) {
    // count number of even number from position $i to $(strlen - 1)
    // $i start from 0
    // base case
    if (i == str_len - 1) {
        memo[i] = is_even(s[i]) ? 1 : 0;
        return memo[i];
    }
    memo[i] = is_even(s[i]) + count_even_num_in_string(s, i + 1, memo, str_len);
    return memo[i];
}
