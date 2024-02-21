#include <iostream>

int main() {
    using namespace std;
    int x = 10;
    cout << &x << endl;

    int *ptr = &x;
    cout << ptr << endl;

    *ptr = 5;
    cout << x << endl;

    int y = *ptr;
    cout << y << endl;

    int *ptr2 = nullptr;  // A null pointer. For most compilator it will be seen as 0, but some will return an error regarding Access Violation
    cout << ptr2 << endl;


    return 0;
}