#include "Integer.h"
#include <iostream>

int main() {
    Integer a(1);
    auto b{a};     // In this case, the copy constructor will be used

    // In case we want to use move, not copy

    auto c{static_cast<Integer&&>(a)};  // We can use static cast to force the compiler to use the Move construct, but it lefts us with a
                                        // complicated syntax

    auto d{std::move(a)};               // this function has a simpler syntax, but does the same cast as above. Increase readability

    


    return 0;
}