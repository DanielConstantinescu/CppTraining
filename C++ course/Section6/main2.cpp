#include "Integer.h"
#include <iostream>

Integer operator +(int x, const Integer &y) {
    Integer temp;
    temp.SetValue(x + y.GetValue());
    return temp;
}

Integer operator +(const Integer &x, int y) {
    Integer temp;
    temp.SetValue(x.GetValue() + y);
    return temp;
}

std::ostream & operator <<(std::ostream & out, const Integer &a) {  // We overload the << operator to avoid using GetValue() each time
    out << a.GetValue();
    return out;
}

std::istream & operator >>(std::istream &input, Integer &a) {
    int x;
    input >> x;

    // a.SetValue(x);

    *a.m_pInt = x;       // We would like to use this syntax in case SetValue is not defined. But we first have to declare this function a friend of
                         // class integer
    return input;
}

int main() {
    Integer a(1), b(3);

    // These two will not work due to the fact that operator + was not overload for the case of an int + Integer or Integer + x
    Integer sum1 = a + 5;   
    Integer sum2 = 5 + a;

    // Works witout GetValue() because << operator was overloaded
    std::cout << sum1 << std::endl;
    std::cout << sum2 << std::endl;

    // Overload the >> operator
    std::cout << "Enter a value for a: " << std::endl;
    std::cin >> a;
    std :: cout << a << std::endl;

    return 0;
}