#include <iostream>

void calculateRunTime(long *array, long arraySize, void func(long *, long)) {
    
    typedef long long ll;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    func(array, arraySize);

    end = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Time: " << elapsed_time << "ms\n";

}

void bubbleSort(long *array, long arraySize) {
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
}

void printArray(int *array, int arraySize) {
    for (int i=0; i<arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {

    freopen("input.txt", "r", stdin);

    long arraySize;
    // take array size input
    std::cin >> arraySize;

    long array[arraySize];

    // take array input
    for (long index=0; index<arraySize; index++) {
        std::cin >> array[index];
    }

    // Printing array before sorting
    // printArray(array, arraySize);

    calculateRunTime(array, arraySize, bubbleSort);

    // Printing array after sorting
    // printArray(array, arraySize);

    return 0;
}