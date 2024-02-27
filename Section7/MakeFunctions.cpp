#include <iostream>
#include <memory>

// Modern C++ recommend to avoid using automatique memory management, so we should avoid using new and deleters in our code.

void DynArray();

class Point {
    Point(int x, int y) {

    }
};

int main() {
    // Unique pointer
    {
        //std::unique_ptr<int> p{new int{5}};  // create unique using new

        auto p = std::make_unique<int>(5);     // create unique pointer using make functions

        auto pt = std::make_unique<Point>(3,5); // crate an object using global function

        auto pArr = std::make_unique<int[]>(5); // create a dynamic array. The argument 5 represents the size of the array
        pArr[0] = 0;                            // We cannot initilize an array with make unique, but we can initialize it manually
    }

    // Shared pointer
    {
        auto p = std::make_shared<int>(5);

        auto pt = std::make_shared<Point>(3,5);

        auto pArr = std::make_shared<int[]>(5);
        pArr[0] = 0; 
    }
}