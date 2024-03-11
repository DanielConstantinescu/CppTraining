#include <iostream>

// Return R-value (returns by value, an int)
int Add(int x, int y) {
    return x + y;
}

// Return L-value (returns by reference)
int & Transform(int &x) {
    x *= x;
    return x;
}

void Print (int &x) {
    std::cout << "Print(int&)" << std::endl;
}

void Print(const int &x) {
    std::cout << "Print(const int&)" << std::endl;
}

void Print (int &&x) {
    std::cout << "Print (int &&)" << std::endl;
}

int main() {
    // x, y, z are L-values ; 5, 10, 8 are R-values
    int x = 5;
    int y = 10;
    int z = 8;

    // Expression returns R-value
    int result = (x + y) * z;

    // Expressions returns L-value
    ++x = 6;

    int &&r1 = 10;
    int &&r2 = Add(3, 2);

    //int &&r3 = x;      // Gives an error ; R-value reference cannot bind to an L-value

    const int &ref2 = 3; // An L-value reference can bind to a R-value if it is a constant

    x = 10;
    Print(x);   // Calls Print(int&)

    Print(3);   // Calls Print(int &&). If this was commented, would call Print(const int&)

    return 0;
}