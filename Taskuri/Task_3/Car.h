#pragma once
#include <iostream>
#include <string>
#include <memory>

// Abstract class
struct Car {
    virtual ~Car() = default;

    virtual void fuel(int fuel) = 0;
};

// Class 1
struct ElectricCar : Car{
    void fuel(int fuel) override {
        std::cout << "The electric vehicle was charged at " << fuel << "% baterry." << std::endl;
    }
};

// Class 2
struct PetroleumCar : Car {
    void fuel(int fuel) override {
        std::cout << "The vehicle was fuel with " << fuel << " liters of fuel." << std::endl;
    } 
};