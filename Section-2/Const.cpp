#include <iostream>

int main() {
    using namespace std;
    float radius = 0;

    cout << "Enter radius:" << endl;
    cin >> radius;

    const float PI = 3.14159f; // Using const avoids magic numbers and we also make sure nobody can modify the value of the variable
                               // It is a good practice to declare constants in capital letters!!!!

    float area = PI * radius * radius;
    float circumference = PI * 2 * radius;
    cout << "Area is " << area << endl;
    cout << "Circumference is: " << circumference << endl;

    //Const and pointers
    const int CHUNK_SIZE = 521;
    const int *ptr = &CHUNK_SIZE; // A pointer to a const must also be a constant
    return 0;
}