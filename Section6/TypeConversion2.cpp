#include <iostream>
#include "Integer.h"

void Print(const Integer &a) {

}

int main() {
    Integer a1{ 5 };
    Integer a2 = 5;   // Initialization -> Compiler will implicitly invoke parameterized constructor

    Print(5);

    a1 = 7;    // Assignment -> This will mtch with the move assignment

    // How to convert a user-defined type into a primitive type //

    int x = static_cast<int>(a1);   // Will not work because compiler does not know how to convert this object in a primitive type
                                    // Will work after we added the operator conversion function in the body of the class
                                    // We have to explicitly call the cast due to explicit keyword in class

    return 0;
}