#include <iostream>

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

    // Proceed to sort array in ascending order
    // TODO: Try sorting the array in descending order
    for (int i=0; i<arraySize; i++) {
        for (int j=0; j<arraySize-i-1; j++) {

            int temp;
            // temp is a temporary variable to store a value so as in to perform a swap.
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }

        }
    }

    // Printing array after sorting
    for (int i=0; i<arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}