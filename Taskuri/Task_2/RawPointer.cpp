// Task 2
#include "Integer.h"

/***** Small example using both raw pointers and unique pointers *****/
/*****                   CASE 1: RAW POINTER                     *****/

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
void Store(Integer* p) {
    std::cout << "Storing data into a file:" << p->GetValue() << std::endl;
}

void Operate(int value) {
    /* Raw Pointer */
    Integer *p = GetPointer(value);

    if(p == nullptr) {
        p = new Integer{value};
    }
    p->SetValue(100);

    /* First display */
    Display(p);
    
    /* When working with raw pointers, we have to delete them ourselves to avoid memory leaks 
       Calling delete will also call the destructor from Integer class */
    delete p;
    
    p = new Integer{};
    
    /* Macro for getting current line number */
    *p = __LINE__;
    
    /* Second display */
    Display(p);

    Store(p);

    /* This delete frees the memory.
       If we forget to free the memory, we will have memory leaks .*/
    delete p;
}

int main() {
    Operate(5);
    return 0;
}
