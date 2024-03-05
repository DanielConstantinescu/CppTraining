#pragma once
#include "Petroleum.h"

class Renault : public Petroleum {
public:
    // Parameterized constructor
    Renault(float fuellevel, Fuel fueltype, Body bodytype, int power, Equipment equipmenttype, int ID);

    // Copy constructor
    Renault (const Renault &obj);

    // Move constructor
    Renault(Renault &&obj);

    // Copy assignment
    Renault & operator=(const Renault &obj);

    // Move assignment
    Renault & operator=(Renault &&obj);

    float GetFuelLevel()const override;
    void fuelCar(float fuel) override;
    Fuel GetFuelType()const override;
    Body GetBodyType()const override;
    Traction GetTractionType()const override;
    int GetHP()const override;
    Equipment GetEquipmentType()const override;
    int* Identify()const override;

    // Destructor
    ~Renault();
};