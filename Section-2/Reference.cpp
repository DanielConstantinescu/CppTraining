#include <iostream>

int main() {
    using namespace std;

    //Referent
    int x = 10;

    //Reference
    int &ref = x;

    cout << "x: " << x << endl;
    cout << "ref: " << ref << endl;

    // If x modifies, the value in ref will also change
    cout << "x becomes 20" << endl;
    x = 20;

    cout << "x: " << x << endl;
    cout << "ref: " << ref << endl;

    return 0;
}