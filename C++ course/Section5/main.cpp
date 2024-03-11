#include "Integer.h"
#include <iostream>

Integer Add(const Integer &a, const Integer &b) {
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

Integer Add(int a, int b) {
    // Integer temp(a+b);
    // return temp;

    return Integer(a+b);   // This is called Return value optimization. This is how we can use copy elision to improvise the code.
}

int main() {
    Integer a(1), b(3);
    a.SetValue(Add(a,b).GetValue());

    Integer c = 3; // It is called Copy Elision, the act of ommiting a larger syntax. For example, the full syntax here would be Integer c = Integer(3)
                   // It will work because Integer class has a parameterized constructor. The compiler allows this kind of elisions;

    return 0;
}