#include <stdio.h>
#include <stdlib.h>

/* Unimportant things, you can ignore it. */
#define PROGRAM_NAME
#define CAN_T_DO_ANYTHING "We can't do anything.\n"
#define STILL_EXIT_WITH_SUCCESS_CODE "Program is still exit with 0 code.\n"
#define OUT_OF_MEMORY "Because OUT OF MEMORY\n"
#define CAN_NOT_OPEN_FILE "Because CAN NOT OPEN FILE\n"
/* Unimportant things, you can ignore it. */

typedef struct {
    double weight; // pound
    double value;  // usd
} Item;

int compare_item_by_rate(const void* item1, const void* item2); // qsort
double knapsack(const char* test_file_name);

int main(int argc, char const* argv[]) {
    knapsack("input/Fractional_Knapsack/knapsack01.inp");
    knapsack("input/Fractional_Knapsack/knapsack02.inp");
    knapsack("input/Fractional_Knapsack/knapsack03.inp");
    knapsack("input/Fractional_Knapsack/knapsack04.inp");
    return 0;
}

int compare_item_by_rate(const void* item1, const void* item2) {
    // sort by ratio (value/weight)
    double r1 = ((Item*)item1)->value / ((Item*)item1)->weight;
    double r2 = ((Item*)item2)->value / ((Item*)item2)->weight;
    if (r1 > r2)
        return -1; // < 0, item1 goes before item2
    if (r2 > r1)
        return 1; // > 0, item1 goes after item2
    return 0;     // equal
}

double knapsack(const char* test_file_name) {
    FILE* fp = freopen(test_file_name, "rt", stdin);
    if (fp == NULL) {
        printf(
            CAN_T_DO_ANYTHING CAN_NOT_OPEN_FILE STILL_EXIT_WITH_SUCCESS_CODE);
        exit(0);
    }

    int n_of_item;
    double w;
    scanf("%d%lf", &n_of_item, &w);
    Item items[n_of_item];

    double weight[n_of_item];
    for (size_t i = 0; i < (size_t)n_of_item; ++i)
        scanf("%lf", weight + i);

    for (size_t i = 0; i < (size_t)n_of_item; ++i) {
        items[i].weight = weight[i];
        scanf("%lf", &(items[i].value));
    }
    fclose(fp);

    qsort(items, n_of_item, sizeof(Item), compare_item_by_rate);
    double max_value = 0.0;
    for (size_t i = 0; i < (size_t)n_of_item; ++i) {
        if (w == 0)
            break;
        double item_w = items[i].weight;
        double item_p = items[i].value;
        if (w >= item_w) {
            max_value += item_p;
            w -= item_w;
        } else {
            max_value += (w / item_w) * item_p;
            w = 0;
        }
    }
    return max_value;
}
