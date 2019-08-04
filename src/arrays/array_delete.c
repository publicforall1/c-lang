/* *
 * Program Name: Array - Delete element base on value
 * Author: Võ Văn Khánh Quốc
 * Clean code: taiprogramer
 * - Without any WARRANTY -
 */
#include <stdio.h>

void get_input(int arr[], int size);
void show_array(int arr[], int size);
void delete_element_value(int arr[], int* size, int value);
void delete_element_position(int arr[], int* size, int position);

int main() {
    int size, value;
    printf("Nhap so phan tu mang: ");
    scanf("%d", &size);

    int arr[size];
    get_input(arr, size);
    show_array(arr, size);

    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &value);
    delete_element_value(arr, &size, value);
    show_array(arr, size);
}

void get_input(int arr[], int size) {
    int i = 0;
    while(i < size){
        printf("Nhap phan tu thu %d : ", i + 1);
        scanf("%d", &arr[i]);
        ++i;
    }
}

void show_array(int arr[], int size) {
    printf("Gia tri hien tai cua mang la:\n");
    int i = 0;
    while(i < size){
        printf("%d ", arr[i]);
        ++i;
    }
    printf("\n");
}

void delete_element_value(int arr[], int* size, int value) {
    int i = 0;
    while(i < *size){
        if (arr[i] == value) {
            delete_element_position(arr, size, i);
            --i; // Back to check
        }
        ++i;
    }
}

void delete_element_position(int arr[], int* size, int position) {
    int i = position;
    while(i < *size){
        arr[i] = arr[i + 1];
        ++i;
    }
    // resize array after delete 1 element
    *size = *size - 1;
}
