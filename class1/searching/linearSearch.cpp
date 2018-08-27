#include <iostream>

int main() {

    int arraySize;
    std::cin >> arraySize;

    int array[arraySize];

    int elementToBeSearched;
    std::cin >> elementToBeSearched;

    // This is a flag that will keep track of whether the element we were searching was 
    // actually present in the array or not
    bool isElementPresent = false;

    for (int index=0; index<arraySize; index++) {

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

    return 0;
}