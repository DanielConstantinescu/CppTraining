#include "Car.h"
#include <iostream>


int Car::totalCount = 0;         // Initialization of the static variable ; Will increment in constructors and decrement in destructor

Car::Car():Car(0)                       // Default constructor ; Delegated the call to the constructor with 1 argument
{
    std::cout << "Car() executed" << std::endl;
}

Car::Car(float amount):Car(amount, 0)          // Parameterized constructor ; Delegated the call to the constructor with 2 arguments
{
    std::cout << "Car(float) executed" << std::endl;
}

Car::Car(float amount, int passengers)
{
    std::cout << "Car(float, int) executed" << std::endl;
    ++totalCount;
    fuel = amount;
    speed = 0;
    this->passengers = passengers;
}

Car::~Car()                        // Destructor
{
    --totalCount;
    std::cout << "~Car() destructor invoked" << std::endl;
}

void Car::FillFuel(float amount)
{
    fuel = amount;
}

void Car::Accelerate()
{
    this->speed++;
    this->fuel -= 0.5f;
}

void Car::Brake()
{
    speed = 0;
}

void Car::AddPassengers(int passengers)         // In this case, "this" pointer help the compiler understand which passengers variable is the
{                                               // class attribute and which is the function attribute
    this->passengers = passengers;
}

void Car::Dashboard() const
{
    std::cout << "Fuel: " << fuel << std::endl;
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Passengers: " << passengers << std::endl;
}

void Car::ShowCount()
{
    std::cout << "Total cars: " << totalCount << std::endl;
}
