#include "Car.h"
#include "Integer.h"
#include <iostream>

/* Main function for Car class and exercises */
int main() {

// Test constructors order for Delegated Constructors
    Car car;

/*
    Car::ShowCount();          // Call the static member function by calling the class ; 0 cars

    //Car car;                 // Default constructor is called here
    Car car(4);                // Parameterized constructor is called here
    //const Cat car(4)         // If we declare object car as const, it won't be able to use any other methods but Dashboard which does not modify the state

    car.FillFuel(6);
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Dashboard();
    std::cout << std::endl;

    Car c1, c2;

    c1.Dashboard();
    std::cout << std::endl;
    c2.Dashboard();

    Car::ShowCount();           // 3 cars
*/

    return 0;

}

/* Main function for Integer class and exercises
void print(Integer i) {             // In this case a copy of the object is created because we are passing it as a value

}

Integer Add(int x, int y) {         // In this case a copy of the object is created because we are returning that value
    return Integer(x+y);
}

int main() {
    Integer i(5);
    Integer i2(i);                   // Create a copy of the object

   // Shallow copy 
    int *p1 = new int(5);           // In this case we copy the pointer address
    int *p2 = p1;                   // NOT RECOMMANDED
    

   // Deep copy 
    int *p1 = new int(5);           // In this case we allocate memory to the address and then copy the value
    int *p3 = new int(*p1);         // We should do the same in Integer class, so we should have a user-defined copy constructor
   

    std::cout << i.GetValue() << std::endl;

    return 0;
}*/
