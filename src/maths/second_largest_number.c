#include <stdio.h>
#include <assert.h>

int second_largest_number(int arr[], int size){
    if (size < 1)
	return -1;

    int i, max = 0, nearest_max = 0;
    for(i = 0; i < size; ++i){
	if (arr[i] > max){
	    nearest_max = max;
	    max = arr[i];
	}
    }
    return nearest_max;
}

int main(void){
    

    int a[] = {1, 3, 5, 7};

    assert(second_largest_number(a, sizeof(a) / sizeof(int)) == 5);

    return 0;
}

