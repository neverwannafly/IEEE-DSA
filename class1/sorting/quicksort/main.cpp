#include <iostream>
#include "quicksort.hpp"

void printArray(int *arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {


    initSeed();
    
    int size = 10;
    int arr[size];

    for (int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, size-1);

    printArray(arr, size);

    return 0;
}