#pragma once
#include "Electric.h"
#include <iostream>

// Implementata folosind Singleton Design Pattern
class Tesla : public Electric {
private:
    static Tesla* instancePtr;

    // Parameterized constructor
    Tesla(float fuellevel, Body bodytype, int power, Equipment equipmenttype, int ID) : 
        Electric(fuellevel, bodytype, power, equipmenttype, ID) 
    {   
        std::cout << "Tesla(float, Body, int, Equipment, int)" << std::endl;
    }

public:
    static Tesla* getInstance() {
        if (instancePtr == nullptr) {
            instancePtr = new Tesla(50.5, Body::CONVERTIBLE, 1000, Equipment::CUSTOM, 10);
            return instancePtr;
        } else {
            return instancePtr;
        }
    }

    // Destructor
    ~Tesla();

public:

    // Copy constructor
    Tesla (const Tesla &obj) = delete;

    // Move constructor
    Tesla(Tesla &&obj);

    // Copy assignment
    Tesla & operator=(const Tesla &obj) = delete;

    // Move assignment
    Tesla & operator=(Tesla &&obj);

    float GetFuelLevel()const override;
    void fuelCar(float fuel) override;
    Fuel GetFuelType()const override;
    Body GetBodyType()const override;
    Traction GetTractionType()const override;
    int GetHP()const override;
    Equipment GetEquipmentType()const override;
    int* Identify()const override;
};