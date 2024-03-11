#include <iostream>

int main() {
    int i = 20;
    using namespace std;
    cout << i << endl;
    
    char ch = 'a';
    bool flag = true; //true or false
    cout << ch << " si " << flag << endl;

    float f = 1.345f;
    double d = 521.342;
    cout << f << " e float si " << d << " e double" << endl;

    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Numerele impare sunt " << arr[0] << ", " << arr[2] << " si " << arr[4] << endl;
    return 0;
    
}