#include "Integer.h"
#include <memory>

void Display (Integer *p) {
    if(!p) {
        return;
    }
    std::cout << p->GetValue() << std::endl;
}

Integer * GetPointer(int value) {
    Integer *p = new Integer{value};
    return p;
}

void Store(std::unique_ptr<Integer> p) {
    std::cout << "Storing data into a file:" << p->GetValue() << std::endl;
}

void Operate(int value) {
    //Integer *p = GetPointer(value);                           // Raw pointer
    std::unique_ptr<Integer> p{GetPointer(value)};          // Unique pointer
    if(p == nullptr) {
        //p = new Integer{value};   //raw
        p.reset(new Integer{value}); //unique
    }
    p->SetValue(100);
    //Display(p);  //raw
    
    Display(p.get()); //unique
    //delete p; //raw. Cannot call delete on unique pointer p because it is an object, not a pointer
    
    //p = new Integer{};  //raw
    p.reset(new Integer{});
    
    *p = __LINE__;           // Macro for getting current line number
    
    //Display(p);  //raw
    Display(p.get()); //unique

    //Store(p);     // If we call it with normal p, we won't be able to create a copy of it. To use it in store, we will have to move it
    Store(std::move(p));


    //delete p; //raw
}

int main() {
    Operate(5);

    return 0;
}