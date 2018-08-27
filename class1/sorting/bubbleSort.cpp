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
        for (int j=i; j<arraySize; j++) {

            int temp;
            // temp is a temporary variable to store a value so as in to perform a swap.
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
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