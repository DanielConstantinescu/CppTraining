#include <iostream>

int Add(int a, int b) {
    return a + b;
}

int Add( double a, double b) {
    return a + b;
}

void Print(int x) {      // Works. If second Print would have an int argument, even if it is a void function, we would get an error

}

void Print (float x) {

}

int main() {
    using namespace std;
    int result = Add(3, 5);
    cout << result << endl;

    double sum = Add(3.1, 6.2);
    cout << sum << endl;
    return 0;
}

/* OVERLOADING
        - Two or more functions declared with the same name but:
            - Arguments should be different
            - Return type is ignored, so it will not matter
            - For pointers & reference arguments, qualifiers participate in overload
        
        - THe correct implementation is chosed based on the arguments
        - IT is resolved at compile time
*/