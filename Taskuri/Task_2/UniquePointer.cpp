// Task 2
#include "Integer.h"
#include <memory>     /* To use smart pointers, we need to include this library */

/***** Small example using both raw pointers and unique pointers *****/
/*****                   CASE 2: UNIQUE POINTER                    *****/

/* Display the integer value from a pointer */
void Display (Integer *p) {
    if(!p) {
        return;
    }
    std::cout << p->GetValue() << std::endl;
}

/* Initialize a pointer using the constructor from Integer */
Integer * GetPointer(int value) {
    Integer *p = new Integer{value};
    return p;
}

/* Simple print function */
void Store(std::unique_ptr<Integer> p) {
    std::cout << "Storing data into a file:" << p->GetValue() << std::endl;
}

void Operate(int value) {
    /* Unique pointer */
    std::unique_ptr<Integer> p{GetPointer(value)};

    if(p == nullptr) {
        /* reset() method is used to allocate memory for a smart pointer */
        p.reset(new Integer{value});
    }
    p->SetValue(100);
    
    /* First display */
    /* get() method return the underline pointer. Smart pointers by themselves are objects, not pointers. */
    Display(p.get());
    
    /* We use reset to allocate new memory. Main difference between a smart pointer and a raw pointer is that the smart pointer will free the resource
       by itself. You notice we do not need to use delete. Also we can't use delete because smart pointers are objects */
    p.reset(new Integer{});
    
    /* Macro for getting current line number */
    *p = __LINE__;
    
    /* Second display */
    Display(p.get());

    /* We cannot call Store(p) because unique pointers cannot be copied, they can only be moved */
    Store(std::move(p));

    /* No need to free memory at the end. The smart pointer does it itself. */
}

int main() {
    Operate(5);
    return 0;
}
