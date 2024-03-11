#include <iostream>

int main() {
    using namespace std;

    int arr[] = {1,2,3,4,5};          // For loop -> index based ; requires end condition ; error-prone ; better control over iteration
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int x : arr) {                 // Range-Base For -> no index ; end condition provided by range ; no need to increment/decrement ; less errors;
        cout << x << " ";               //                   less control over iteration
    }
    cout << endl;

    
    // Using pointers
    int *start = &arr[0]; // We can use std::begin(arr) to get the first element
    int *end = &arr[5];   // We can get std::end(arr) to get the last element

    while (start != end) {
        cout << *start << ' ';
        ++start;
    }
    cout << endl;

    return 0;
}