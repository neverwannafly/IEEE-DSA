#include <iostream>
#include <cmath>
 
// TODO: Sort an array in descending order
void insertionSort(int *array, int n) {

   int key;
   int counter;

    for (int i = 1; i < n; i++) {
        key = array[i];
        counter = i-1;

        while (counter >= 0 && array[counter] > key) {
            array[counter+1] = array[counter];
            counter = counter-1;
        }
        array[counter+1] = key;
    }
} 
 
int main() {

    int arraySize;
    // take array size input
    std::cin >> arraySize;

    int array[arraySize];

    // take array input
    for (int index=0; index<arraySize; index++) {
        std::cin >> array[index];
    }

    // Printing array before sorting
    for (int i=0; i<arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    // sort array
    insertionSort(array, arraySize);

    // Printing array after sorting
    for (int i=0; i<arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}