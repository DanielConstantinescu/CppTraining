#pragma once
#include <iostream>

class Integer {
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer &obj);
    Integer(Integer &&obj);
    int GetValue()const;
    void SetValue(int value);
    ~Integer();

    Integer & operator ++();   // Overload the pre increment (++i) operator

    Integer operator ++(int);   // Overload the post increment (i++) operator. We send an int as argument to help compiler distinguish between these 2

    bool operator ==(const Integer &obj)const;

    Integer & operator =(const Integer &a);

    Integer & operator =(Integer &&a);

    // By using friend keyword, the function is not seen as part of the class
    friend std::istream & operator >>(std::istream &input, Integer &a);
    
  /*  
    // We can use it like this for classes
    friend class Printer;
  */
};