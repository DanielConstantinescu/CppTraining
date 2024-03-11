#include "Integer.h"
#include <iostream>

class Number{
    Integer m_Value{};
public:
    Number()=default;
    Number(int value):m_Value{value}{
    }

    /*Number(const Number &n):m_Value{n.m_Value}{           // If we provide an implementation for a copy constructor or a destructor, it will no longer
    }                                                       // use the move operation from the Integer class
    ~Number(){
    }*/
    Number (Number &&n) = default;                          // default move constructor
    Number (Number &n) = default;                           // default copy constructor, both synthezised from Integer class

    /*Number(Number &&n):m_Value{std::move(n.m_Value)}{       // When we provide an implementation for move, the copy operation becomes deleted and we will have
    } */                                                      // errors on previous copy operations

    Number & operator=(Number&&)=default;                   // default implementation for move, will make the compiler synthesize the move from Integer
    Number & operator=(Number&)=default;                    // default implementation for copy assignment
};

Number CreateNumber(int num) {
    Number n{num};
    return n;
}

int main() {
    Number n1{1};
    auto n2{n1};
    n2 = n1;

    auto n3{CreateNumber(3)};
    n3 = CreateNumber(3);

    return 0;
}