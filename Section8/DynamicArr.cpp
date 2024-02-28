#include <iostream>
#include <vector>

int main() {
    int arr[10];   // It cannot store more than 10 elements

    // To make sure we can store more than 10 elements, it is better to use a dynamic array and manage the memory ourselves

    int *ptr = new int[10]; // this will create an array that can initially hold 10 numbers
    for(int i = 0; i < 10; ++i) {
        ptr[i] = i * 10;
    }

    // Even the classic pointer method has flaws because if we want to make it larger, we will have to allocate new memory to a new array,
    // to copy the elements from the old array and then to free the memory from the old array

    // A better solution is to use the vector class provided by the standard library

    std::vector<int> data {1,2,3};

    data.push_back(4);   // It will automatically make space and we won't have to worry about memory allocation

    for(int i = 0; i < 5; ++i) {
        data.push_back(i*10);
    }

    //Access
    data[0] = 100;
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    for (auto x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    auto it = data.begin();
    std::cout << *it <<std::endl;
    ++it;
    --it;
    it = it + 5; // jump positions

    //Delete
    it = data.begin();
    data.erase(it);

    for (auto x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    //Insert
    it = data.begin() + 5;   // Insert to fifth location
    data.insert(it, 500);

    for (auto x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}