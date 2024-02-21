#include <iostream>

/*int Square(int x){  // Simple function. No real reason to write it like this
    return x * x;
}*/

//#define Square(x) x*x    Macros have bugs. For example a Square(val+1) would have a wrong answer.

inline int Square(int x){  // Using inline, we avoid the overhead of the function call. It improves performance
    return x * x;          // These kind of functions are usually declared in a header file.
}

int main() {
    using namespace std;
    int val = 5;
    int result = Square(val+2);
    cout << result << endl;
    return 0;
}