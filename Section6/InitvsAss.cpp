#include <iostream>
#include "Integer.h"

class Product {
    Integer m_Id;
public:
    Product(const Integer &id):m_Id(id) {           // Initialization
        std::cout << "Product(const Integer &)" << std::endl;
        //m_Id = id;  // Assignment
    }

    ~Product() {
        std::cout << "~Product()" << std::endl;
    }
};

// Initialization vs Assignment

/*
int main() {
    //Initialization
    Integer a (5);      // In this case the object is created using parameterized constructor and, at the end, the destructor is called

    //Assignment
    Integer a;
    a = 6; // In this call we have a simple constructor, a parameterized constructor for casting 6, the assignment operator and 2 destructors, one for a and
           // one for temporary object Integer(6)

    // !! Assignment needs more functions calls than Initialization !!

    std::cout << a.GetValue() << std::endl;
    return 0;



}*/

// Another example
int main() {
    Product p(5);

    /* Output 1 (with assignment)
        Integer(int) -> construct Integer(5)
        Integer() -> construct the attribute for class Product
        Product(const Integer &) -> constructor for class Product, constructs p
        operator=(const Integer&) -> assignment operator used in Product constructor
        ~Integer() -> destructor
        ~Product() -> destructor
        ~Integer() -> destructor
    */

   /* Output 2 (with initialization)
        Integer(int) -> construct Integer(5)
        Integer(int&) -> initialize m_Id for Product
        Product(const Integer &) -> constructor for Product, constructs p
        ~Integer() -> destructor
        ~Integer() -> destructor
        ~Integer() -> destructor 
    */

   /* Conclusion: Initialization is faster */

    return 0;
}