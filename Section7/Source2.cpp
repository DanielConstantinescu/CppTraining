#include <iostream>
#include <memory>

class Printer {
    //int *m_pValue{};
    //std::shared_ptr<int> m_pValue{};
    std::weak_ptr<int> m_pValue{};
public:
    void SetValue(std::weak_ptr<int> p) {
        m_pValue = p;
    }

    void Print() {

        if(m_pValue.expired()) {
            std::cout << "Resource is no longer available" << std::endl;
            return;
        }
        auto sp = m_pValue.lock();
        std::cout << "Value is: " << *sp << std::endl;
        std::cout << "Ref count: " << m_pValue.use_count() << std::endl;      // print reference count for the smart pointer
    }
};

// If the value is greater than 10, the pointer is deleted so the value in Printer object will also point to a deleted pointer
// To fix it we would need to check in Print function if the pointer p declared in main still exists
// How should we do that?
//
// Case 1:  instead of using raw pointer we will use smart pointer and since we are sharing p with the Printer class
//           we weill use a shared pointer
// For the first case, event if the value is >10 and p gets initialised to nullptr, the Print() function will return the full value.
// This happens because when p is sent as parameter to SetValue, a copy of p is created, so the counter is incremented by one.
// The problem is that when p is initialized to nullptr, the counter decrease only by 1, but the underline memory is not released. It will
//   be release only at the end, when counter becomes 0. If the Printer object is released much much later, the memory for p will still be occupied.
//
// How to ensure that the memory is freed when p is initialized to nullptr.
//
// Case 2: use a weak pointer over the shared pointer. This way we make sure we can get the good value and also free the memory.

int main () {
    Printer prn;
    int num{};
    std::cin >> num;
    
    //int *p = new int{num} ;
    std::shared_ptr<int> p{new int{num}};

    prn.SetValue(p);

    if(*p > 10) {
        //delete p;
        p = nullptr;
    }

    prn.Print();
    //delete p;
}