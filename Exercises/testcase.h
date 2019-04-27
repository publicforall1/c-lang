#ifndef TEST_CASE_H
#define TEST_CASE_H

void testIntToInt(int (*func)(int), char* test_case_file);
void test2IntToInt(int (*func)(int, int), char* test_case_file);
void printSummary(int pass, int number_of_test_case);

#endif