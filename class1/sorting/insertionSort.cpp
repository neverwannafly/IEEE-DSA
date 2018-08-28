#include <iostrean>
 
// TODO: Sort the array in descending order
void selectionSort(int *array, int size) {
    
    // We'll store the index of the smallest element and will swap 
    // the element at that index with the first element after every
    // iteration.
    int minElementIndex;
 
    for (int i = 0; i < size-1; i++) {

        minElementIndex= i;

        for (int j = i+1; j < size; j++) {
            if (array[j] < array[minElementIndex]) {
                minElementIndex = j;
            }
        }
 
        // Swap smallest element and the first element of array (first element
        // with respect to iteration. eg-> in 1st iteration, the first element would
        // be at index 0, in 2nd iteration, the first element would be at index 1 etc.)
        int temp;
        temp = array[i];
        array[i] = array[minElementIndex];
        array[minElementIndex] = temp;

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
    selectionSort(array, arraySize);

    // Printing array after sorting
    for (int i=0; i<arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}