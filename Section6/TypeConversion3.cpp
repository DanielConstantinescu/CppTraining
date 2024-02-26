#include <iostream>
#include "Integer.h"

class Product {
    Integer m_Id ;
public: 
    Product(const Integer &id):m_Id{id} {
        std::cout << "Product(const Integer &)" << std::endl;
    }

    ~Product(){
        std::cout << "~Product()" << std::endl;
    }

    const Integer & GetInteger()const{
        return m_Id;
    }

    //type conversion operator
    operator Integer(){
        return m_Id;
    }
};

int main() {
    Product p{5};

    //Integer id = p;               // This will not work because there is no function in Integer that accepts a product.
    //Integer id = p.GetInteger();  // We can try defining a function in Product that returns an Integer and it works, but this is not type conversion

    Integer id = p;       // It works because the operator for type conversion is defined

    // Let's assume we have an existing Integer and we want to compare it with the id in the product

    Product p1{5};
    Integer id1{5};

    // The check without type conversion operator defined
    if (id == p.GetInteger()) {
        std::cout << "Id matches with the product" << std::endl;
    }

    // The check with type conversion operator defined
        if (id == p) {
        std::cout << "Id matches with the product" << std::endl;
    }



    return 0;
}