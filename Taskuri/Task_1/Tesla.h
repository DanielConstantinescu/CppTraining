#pragma once
#include "Electric.h"

class Tesla : public Electric {
public:
    // Parameterized constructor
    Tesla(float fuellevel, Body bodytype, int power, Equipment equipmenttype, int ID);

    // Copy constructor
    Tesla (const Tesla &obj);

    // Move constructor
    Tesla(Tesla &&obj);

    // Copy assignment
    Tesla & operator=(const Tesla &obj);

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

    // Destructor
    ~Tesla();

};