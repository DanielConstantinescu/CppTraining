#pragma once
#include "Vehicle.h"

class Petroleum : public Vehicle {
public:
    // Parameterized constructor
    Petroleum(float fuellevel, Fuel fueltype, Body bodytype, int power, Equipment equipmenttype, int ID);

    // Copy constructor
    Petroleum (const Petroleum &obj);

    // Move constructor
    Petroleum(Petroleum &&obj);

    // Copy assignment
    Petroleum & operator=(const Petroleum &obj);

    // Move assignment
    Petroleum & operator=(Petroleum &&obj);

    // Destructor
    ~Petroleum();

public:
    virtual float GetFuelLevel()const;
    virtual void fuelCar(float fuel);
    virtual Fuel GetFuelType()const;
    virtual Body GetBodyType()const;
    virtual Traction GetTractionType()const;
    virtual int GetHP()const;
    virtual Equipment GetEquipmentType()const;
    virtual int* Identify()const;
};