#include <stdio.h>

void get_input(int arr[], int size);
void show_array(int arr[], int size);
int intersect(int A[], int B[], int result[], int size);
int merge(int A[], int B[], int result[], int size);

int main(void) {

    int size, new_size;

    printf("Enter number of element: ");
    scanf("%d", &size);

    int A[size], B[size];
    int intersected_arr[size], merged_arr[size * 2];

    printf("\n---- Array A ----\n");
    get_input(A, size);
    printf("\n---- Array B ----\n");
    get_input(B, size);

    show_array(A, size);
    show_array(B, size);

    // demo
    new_size = intersect(A, B, intersected_arr, size);

    printf("\n---- Array after intersect ----\n");
    show_array(intersected_arr, new_size);

    new_size = merge(A, B, merged_arr, size);

    printf("\n---- Array after merge ----\n");
    show_array(merged_arr, new_size);

    return 0;
}

void get_input(int arr[], int size) {
    /**
     * :Rules
     * after element must greater than previous element
     * :End_Rules
     */
    int i = 0;
    printf("Enter element #%d: ", i + 1);
    scanf("%d", &arr[i]);
    ++i;
    while (i < size) {
        printf("Enter element #%d: ", i + 1);
        int temp;
        scanf("%d", &temp);
        // if temp greater than previous value, add it to array
        if (temp > arr[i - 1]) {
            arr[i] = temp;
            ++i;
        }
    }
}

void show_array(int arr[], int size) {
    if (!size)
        return;
    int i = 0;
    while (i < size) {
        printf("%d ", arr[i]);
        ++i;
    }
    printf("\n");
}

int intersect(int A[], int B[], int result[], int size) {
    /**
     * :Meta
     * This function use to produce intersection of 2 arrays.
     * :End_Meta
     */
    int index = -1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (A[i] == B[j]) {
                ++index;
                result[index] = A[i];
            }
        }
    }
    return ++index;
}

int merge(int A[], int B[], int result[], int size) {
    int index = -1, i = 0, flag, j;
    // add all element in A to result
    while (i < size) {
        ++index;
        result[index] = A[i];
        ++i;
    }
    // check all element in B, if element different from A
    // add it to result
    for (i = 0; i < size; i++) {
        flag = 0;
        for (j = 0; j < size; j++) {
            if (B[i] == A[j])
                flag = 1;
        }
        if (flag == 0) {
            ++index;
            result[index] = B[i];
        }
    }
    return ++index;
}
