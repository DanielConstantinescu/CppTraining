#include <iostream>

int main() {
    int a = 5, b = 2;
    float f = a;     // Implicit conversion

    std::cout << f << std::endl;

    f = a / b;       // In this case we would expect a 2.5, but the f is 2
                     // The reason is that a is an int and it is divided by another int, so the result is an int. The implicit conversion
                     // is done on the operation result which is an int ( = 2).
    std::cout << f << std::endl;

    f = (float)a / b;   // In this case we cast a to float, so the result between a float and an int will be a float (= 2.5)
    std::cout << f << std::endl;

    f = static_cast<float>(a)/b;   // Static cast, prefered to C-style casting
    std::cout << f << std::endl;

    //char *p = (char*)&a;                // Casting is important especially when workin with pointers. C-style casting works here
    //*p = static_cast<char*>(&a);        // but static cast will not work because it is an invalid casting

    char *p = reinterpret_cast<char*>(&a);   // Reinterpret cast will work;

    const int x = 1;
    //int *p = (int*)x;       // A C-style cast will discard the qualifiers (const)
    //int *p = reinterpret_cast<int*>(&x);   // A reinterpret cast will not be allowed because x is a constant.
    int *p = const_cast<int*>(&x);  // Const cast will work





    return 0;
}