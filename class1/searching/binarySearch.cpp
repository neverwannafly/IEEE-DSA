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

    int elementToBeSearched;
    std::cin >> elementToBeSearched;

    // This is a flag that will keep track of whether the element we were searching was 
    // actually present in the array or not
    bool isElementPresent = false;

    // Integers containing values of first and last index of array
    int startIndex = 0;
    int endIndex = arraySize-1;

    while (endIndex > startIndex) {

        int midIndex = (startIndex + endIndex)/2;

        if (array[midIndex] == elementToBeSearched) {
            isElementPresent = true;
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

    return 0;
}