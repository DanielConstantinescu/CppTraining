#include "Integer.h"
#include <iostream>
Integer operator +(const Integer &a, const Integer &b) {   // Global operator overload. If we want to use this, we need to comment the one
    Integer temp;                                          // in the class Integer
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

int main() {
    Integer a(1), b(3);
    Integer sum = a + b;     // It uses the operator overloading for +

    std::cout << (sum++).GetValue() << std::endl;
    
    if (a == b) {
        std::cout << "Same" << std::endl;
    } else {
        std::cout << "Not same" << std::endl;
    }

    Integer c;
    c = a;       // Without overloading the = operator, the compiler will synthezise a Shallow Copy
    std::cout << c.GetValue() << std::endl;

    a = a;       
    std::cout << a.GetValue() << std::endl;

    return 0;
}