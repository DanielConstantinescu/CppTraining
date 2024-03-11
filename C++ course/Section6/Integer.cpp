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

// Pre-increment operator
Integer &Integer::operator++()
{
    ++(*m_pInt);
    return *this;
}

// Post-increment operator. We create a temp, increment the object "this" and then return the temp.
Integer Integer::operator++(int)
{
    Integer temp(*this);
    ++(*m_pInt);
    return temp;
}

bool Integer::operator==(const Integer &obj) const
{
    return *m_pInt == *obj.m_pInt;
}

Integer & Integer::operator=(const Integer & a)
{
    /*
    delete m_pInt;                      // Delete the memory for what we have to avoid a memory leak
    m_pInt = new int(*a.m_pInt);        // And allocate new memory.
    return *this;                       // THis implementations will result in a garbage value if the object assign itself (a = a)
    */

    // To avoid this we must check if the addresses are the same. If they are the same, we do the assignment. Otherwise, we just return the current object.
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

Integer::operator int()
{
    return *m_pInt;
}
