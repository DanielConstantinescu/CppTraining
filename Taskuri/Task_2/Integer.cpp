// Task 2
#include "Integer.h"
#include <iostream>

// Default constructor
Integer::Integer()
{
    std::cout << "Integer()" << std::endl;
    m_pInt = new int(0);
}

// Parameterized constructor
Integer::Integer(int value)
{
    std::cout << "Integer(int)" << std::endl;
    m_pInt = new int(value);
}

// Copy constructor
Integer::Integer(const Integer &obj)
{
    std::cout << "Integer(int&)" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

// Move constructor
Integer::Integer(Integer &&obj)             
{       
    std::cout << "Integer(int&&)" << std::endl;
    m_pInt = obj.m_pInt;                                // Implements a shallow copy
    obj.m_pInt = nullptr;
}

int Integer::GetValue() const
{
    return *m_pInt;
}

void Integer::SetValue(int value)
{
    *m_pInt = value;
}

Integer::~Integer()
{
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
}

Integer & Integer::operator=(const Integer & a)
{
    if (this != &a) {
        delete m_pInt;
        m_pInt = new int (*a.m_pInt);
    }
        
    return *this;
}

Integer &Integer::operator=(Integer &&a)
{
    if (this != &a) {
        delete m_pInt;
        m_pInt = new int (*a.m_pInt);
        a.m_pInt = nullptr;
    }
        
    return *this;
}
