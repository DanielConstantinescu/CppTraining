/* CONSTANT EXPRESSION */

// While some simple const might be evaluated at runtime, a constexpr will be evaluated at compile time
//
// A constant expression can be initialized only with a constant, we cannot initialize it with a function like GetNumber.
//
// Should accept and return literal types only
// Literal types: void, scalar types(int, float, char), references etc...
//
// Should contain only single line statement that should be a return statement.

#include <iostream>

constexpr int GetNumber() {
    return 42;
}

constexpr int Add(int x, int y) {
    return x + y;
}

constexpr int Max(int x, int y) {     // It's in a single line so it works. If we would have use IFs, it would have failed.
    return x > y ? x : y;
}

int main() {
    // Behaves as a constant expression
    constexpr int i = 10;
    //constexpr int i = GetNumber();   // We cannot initialize it with something not constant
                                       // If we initialize GetNumber() with constexpr, it will work

    int arr[i];

    const int j = GetNumber();
    int arr1[j];

    // Behaves as a normal function
    int x = GetNumber();

    constexpr int sum = Add(3,5);    // Behaves as a constexpr, computed at compile time

    int sum2 = Add(3,5);             // Behaves as a normal function, computed at runtime

    return 0;
}