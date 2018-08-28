#include <iostream>

void mergeLists(int *array, int startIndex, int midIndex, int endIndex) {
    // Get size of two lists
    int sizeListA = midIndex - startIndex + 1;
    int sizeListB = endIndex - midIndex;
    // Create temporary lists.
    int listA[sizeListA];
    int listB[sizeListB];
    
    for (int i=0; i<sizeListA; i++) {
        listA[i] = array[startIndex + i];
    }
    for (int i=0; i<sizeListB; i++) {
        listB[i] = array[midIndex + 1 + i];
    }

    int arrayCounter = startIndex;
    int counterListA = 0, counterListB = 0;

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

void mergeSort(int *array, int begin, int end) {

    // This algorithm will continue unless we're working with one single
    // element in our subarray.
    if (end > begin) {
        int mid = (end+begin)/2;

        // Merge sort take advantage of a statergy known as divide and conquer.
        // The main problem is solved by dividing the main problem in subproblems i.e,
        // sorting a sub list instead of main list and in the end merging their result
        // using the mergeLists function.
        mergeSort(array, begin, mid);
        mergeSort(array, mid+1, end);

        mergeLists(array, begin, mid, end);

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
    mergeSort(array, 0, arraySize-1);

    // Printing array after sorting
    for (int i=0; i<arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}