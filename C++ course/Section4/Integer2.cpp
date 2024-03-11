#include <iostream>

class Integer2 {
    int m_Value{ 0 };
public:
    Integer2() = default;    // By using default, we tell compiler that we expect him to create a default implementation for the function
    /*                   
    Integer2() {
        m_Value = 0;
    }
    */

    Integer2(int value) {
        m_Value = value;
    }

    // Integer2(const Integer2 &) = default; // copy constructor

    Integer2(const Integer2 &) = delete;     // By using delete, we tell the compiler to not allow the creation of the copy constructor, so we make sure
                                             // objects cannot be copied

    void SetValue(int value) {
        m_Value = value;
    }

    void SetValue(float) = delete;           // By using this, we make sure we stop users from using float arguments for this function
};

int main() {
    Integer2 i1;              // In case we replace the default constructor with a default initialization, this call will result in an error
                              // Solved by adding Integer2() = default;
    Integer2 i2(3);

    Integer2 i3(i1);          // If we used delete for the copy constructor, this will result in an error

    i1.SetValue(5);
    i1.SetValue(67.1f);       //  Even if we pass a float, we will receive a warning but it will work. To stop users from passing a float, we use delete

    return 0;
}