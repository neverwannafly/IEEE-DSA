#include <iostream>

// Donot pay any heed to this code here. Jump directly to linearSearch function
void calculateRunTime(long *array, long arraySize, long elementToBeSearched, void func(long *, long, long)) {
    
    typedef long long ll;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    func(array, elementToBeSearched, arraySize);

    end = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Elapsed Time: " << elapsed_time << "ms\n";

}

void linearSearch(long *array, long elementToBeSearched, long arraySize) {
    // This is a flag that will keep track of whether the element we were searching was 
    // actually present in the array or not
    bool isElementPresent = false;

    for (long index=0; index<arraySize; index++) {

        // Here we'll try to loop through the array comparing each of it's element with the 
        // element that needs to be searched. If we find the element, we set the value of
        // our flag, i.e (type: bool)isElementPresent, to true indicating that the search
        // was successful.

        if (array[index] == elementToBeSearched) {
            isElementPresent = true;
            break;
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
    // complexity of linearSearch algorithm
    calculateRunTime(array, arraySize, elementToBeSearched, linearSearch);

    return 0;
}