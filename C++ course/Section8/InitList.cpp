#include <iostream>
#include <initializer_list>
#include <cassert>

class Bag {
    int arr[10];
    int m_Size{};
public:

    Bag(std::initializer_list<int> values) {
        assert(values.size() < 10);
        auto it = values.begin(); //first element

        while (it != values.end()) {
            Add(*it);
            ++it;
        }
    }

    void Add(int value) {
        assert(m_Size < 10);
        arr[m_Size++] = value;
    }

    void Remove() {
        --m_Size;
    }

    int operator [](int index) {
        return arr[index];
    }

    int GetSize()const {
        return m_Size;
    }
};

void Print(std::initializer_list<int> values) {
    auto it = values.begin();

    while(it != values.end()) {
        std::cout << *it++ << " ";
    }
    std::cout << std::endl;

    for(auto x : values) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    int x{0};
    float y{3.1f};
    int arr[5]{3,1,3,8,2};
    std::string s{"Hello C++"};

    std::initializer_list<int> data = {1, 2, 3, 4};
    auto value = {1,2,3,4};

/*
    Bag b;
    b.Add(3);
    b.Add(1);
    b.Add(8);
*/

    // What if we want to initialize bag like a normal array?
    Bag b{3, 1, 8};  // Right now it will not work

    for(int i = 0; i<b.GetSize(); ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl << std::endl;

    Print({8,2,6,7});

    return 0;
}