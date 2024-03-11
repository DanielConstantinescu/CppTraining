// We can use smart pointers with the dynamic arrays.

#include <iostream>
#include <memory>

int main() {
    //std::unique_ptr<int> p{new int[5]{1,2,3,4,5}};   // If we use [], the compiler will choose another type of unique ptrs that provide access

    //p[0] = 10;      // If we use smart pointers , we cannot access elemental arrays like this

    //p.get()[0];      // We can do this, but the default deleter will call delete.
                     // We can use a custom deleter but this mean we will write more code.

    std::unique_ptr<int[]> p{new int[5]{1,2,3,4,5}};   // If we use [], the compiler will choose another type of unique ptrs that provide access
    p[0] = 10;
  
}

