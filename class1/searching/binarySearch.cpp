#include <iostream>
#include <chrono>

// Donot pay any heed to this code here. Jump directly to binsearch function
void calculateRunTime(long *array, long arraySize, long elementToBeSearched, void func(long *, long, long)) {
    
    typedef long long ll;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    func(array, elementToBeSearched, arraySize);

    end = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Time: " << elapsed_time << "ms\n";

}

void binSearch(long *array, long elementToBeSearched, long arraySize) {
    // This is a flag that will keep track of whether the element we were searching was 
    // actually present in the array or not
    bool isElementPresent = false;

    // Integers containing values of first and last index of array
    long startIndex = 0;
    long endIndex = arraySize-1;

    while (endIndex >= startIndex) {

        long midIndex = (startIndex + endIndex)/2;

        if (array[midIndex] == elementToBeSearched) {
            isElementPresent = true;
            break;
        } else if (array[midIndex] < elementToBeSearched) {
            startIndex = midIndex + 1;
        } else {
            endIndex = midIndex - 1;
        }

    }

    // we check to see if our flag, i.e (type: bool)isElementPresent, is true 
    // (would only be possible if we changed it's value inside the loop that's again
    // only possible when the search was successful) or false (initial value) using 
    // ternary operator -> condition ? if true : if false;
    isElementPresent ? std::cout << "Search successful\n" : std::cout << "Search unsuccessful\n";
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

    long elementToBeSearched;
    std::cin >> elementToBeSearched;

    // Just assume there is binSearch function here instead of this calculate
    // RunTime function. This is only here to give an idea about the time
    // complexity of binSearch algorithm
    calculateRunTime(array, arraySize, elementToBeSearched, binSearch);

    return 0;
}