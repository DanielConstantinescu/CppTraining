#include <string>

int main() {
    int a;  //Uninitialized
    int b = 0; //Copy initialization
    int c(5); //Direct initialization

    std::string s1;
    std::string s2("C++"); //Direct initialization

    char d[8]; //Uninitialized
    char d1[8] = {'\0'};
    char d3[8] = {'a', 'b', 'c', 'd'}; //Aggregate initialization
    char d4[8] = {"abcd"};

    int e{}; //Value initialization
    int e1{5}; //Direct initialization
    //int e2() ; //Most vexing parse

    char e3[8]{};
    char e4[8]{"Hello"};

    int *p1 = new int{}; //Uninitialized

    char *p2 = new char[8]{};
    //char *p3 = new char[8]{"Hello"};
}

/* Types of initialization
    1. Value initialization => T obj{}
    2. Direction initialization => T obj{v}
    3. Copy initialization => T obj = v; !!Should be avoided
*/

/* Advantages of uniform initialization:
    1. It forces initialization
    2. Can use direct initialization for arrays
    3. Prevents narrowing conversions (when you assign, for example, a floating point type to an integer or vice verse)
*/