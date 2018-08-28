#include <iostream>

void calculateRunTime(long *array, long arraySize, void func(long *, long, long)) {
    
    typedef long long ll;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    func(array, 0, arraySize-1);

    end = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Time: " << elapsed_time << "ms\n";

}

// TODO: Implement merge sort to sort an array in descending order
void mergeLists(long *array, long startIndex, long midIndex, long endIndex) {
    // Get size of two lists
    long sizeListA = midIndex - startIndex + 1;
    long sizeListB = endIndex - midIndex;
    // Create temporary lists.
    long listA[sizeListA];
    long listB[sizeListB];
    
    for (long i=0; i<sizeListA; i++) {
        listA[i] = array[startIndex + i];
    }
    for (long i=0; i<sizeListB; i++) {
        listB[i] = array[midIndex + 1 + i];
    }

    long arrayCounter = startIndex;
    long counterListA = 0, counterListB = 0;

    while (counterListA < sizeListA && counterListB < sizeListB) {

        // This assigns values in our main array in variance with 
        // which element of these smaller 2 presorted arrays is smaller. 
        // Both listA and listB are guranteed to be presorted.

        if (listA[counterListA] <= listB[counterListB]) {
            array[arrayCounter++] = listA[counterListA++];
        } else {
            array[arrayCounter++] = listB[counterListB++];
        }

    }

    // Only one the two below while loops will work.
    // Note that the while loop above is only over when
    // either of the one counters or both, counterListA or 
    // counterListB has become equal to size of their 
    // respective lists. So we're only copying the remaining 
    // items in either of the lists to our orignal array

    while (counterListA < sizeListA) {
        array[arrayCounter++] = listA[counterListA++];
    }

    while (counterListB < sizeListB) {
        array[arrayCounter++] = listB[counterListB++];
    }

}

void mergeSort(long *array, long begin, long end) {

    // This algorithm will continue unless we're working with one single
    // element in our subarray.
    if (end > begin) {
        long mid = (end+begin)/2;

        // Merge sort take advantage of a statergy known as divide and conquer.
        // The main problem is solved by dividing the main problem in subproblems i.e,
        // sorting a sub list instead of main list and in the end merging their result
        // using the mergeLists function.
        mergeSort(array, begin, mid);
        mergeSort(array, mid+1, end);

        mergeLists(array, begin, mid, end);

    }
}

void printArray(long *array, long arraySize) {
    for (long i=0; i<arraySize; i++) {
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

    // sort array
    calculateRunTime(array, arraySize, mergeSort);

    // Printing array after sorting
    // printArray(array, arraySize);

    return 0;
}