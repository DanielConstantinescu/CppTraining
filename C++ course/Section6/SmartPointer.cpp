#include "Integer.h"
#include <iostream>
#include <memory>      // needed for smart pointers

class IntPtr {
    Integer *m_p;
public:
    IntPtr(Integer *p) :m_p(p) {

    }

    ~IntPtr() {
        delete m_p;
    }

    // To make sure the objects of this class will behave as pointers, we will overload the -> and * operators
    Integer *operator ->() {
        return m_p;
    }

    Integer & operator *() {
        return *m_p;
    }
};

void Process(std::unique_ptr<Integer> ptr) {
    std::cout << ptr->GetValue() << std::endl;
}

void Process(std::shared_ptr<Integer> ptr) {
    std::cout << ptr->GetValue() << std::endl;
}

void CreateInteger() {
    //  std::unique_ptr<Integer> p (new Integer);    // Unique Pointer
    std::shared_ptr<Integer> p (new Integer);        // Shared Pointer
    (*p).SetValue(3);
    
    //IntPtr p = new Integer;     // Smart Pointer using a class -> behaves like a pointer but automatically free memory
    
    // auto p2(p);                // Will not work! Unique pointers cannot be copied

    // Process(p);                // This will not work because we pass the unique pointer by value and this action creates a copy

    /*
        Process(std::move(p));        // This works because std::move will move the p in the ptr, the argument of Process.
                                  // p will be deleted after this, so make sure not to use it anymore
    */

   Process(p);

    std::cout << p->GetValue() << std::endl;


    // To force the destructor call for the simple pointer, we free the memory with delete.
    //delete p;

}

int main() {
    // On a first run, we notice the constructor is called, but not the destructor
    CreateInteger();

    return 0;
}