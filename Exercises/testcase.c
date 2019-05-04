#include "testcase.h"
#include <stdio.h>
#include <stdlib.h>

void testIntToInt(int (*func)(int), char* test_case_file) {
    // test function take 1 integer as argument & return another integer
    int pass = 0, number_of_test_case = 0;
    FILE* test_case_file_ptr = fopen(test_case_file, "r");

    if (!test_case_file_ptr) {
        printf("Can not open file.");
        exit(1);
    }

    while (1) {
        int args_1, expected_value;
        fscanf(test_case_file_ptr, "%d%d", &args_1, &expected_value);

        if (args_1 == 0 && expected_value == 0) {
            fclose(test_case_file_ptr);
            break;
        }

        number_of_test_case++;
        if (func(args_1) == expected_value)
            pass++;
    }

    printSummary(pass, number_of_test_case);
};

void test2IntToInt(int (*func)(int, int), char* test_case_file) {
    // test function take 2 integers as argument & return another integer
    int pass = 0, number_of_test_case = 0;
    FILE* test_case_file_ptr = fopen(test_case_file, "r");

    if (!test_case_file_ptr) {
        printf("Can not open file.");
        exit(1);
    }

    while (1) {
        int args_1, args_2, expected_value;
        fscanf(test_case_file_ptr, "%d%d%d", &args_1, &args_2, &expected_value);

        if (args_1 == 0 && args_2 == 0 && expected_value == 0) {
            fclose(test_case_file_ptr);
            break;
        }

        number_of_test_case++;
        if (func(args_1, args_2) == expected_value)
            pass++;
    }

    printSummary(pass, number_of_test_case);
};

void printSummary(int pass, int number_of_test_case) {
    printf("Result: %d/%d.\n", pass, number_of_test_case);
    if (pass == number_of_test_case)
        printf("You've pass all testcase. Good job!\n");
    else
        printf("Something wrong. Don't worry. Try again and again. You can do "
               "it!\n");
};