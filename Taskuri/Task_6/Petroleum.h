#pragma once
#include "Vehicle.h"

class Petroleum : public Vehicle {
public:
    // Parameterized constructor
    Petroleum(float fuellevel, Fuel fueltype, Body bodytype, Equipment equipmenttype);

public:
    virtual float GetFuelLevel()const;
    virtual void fuelCar(float fuel);
    virtual Fuel GetFuelType()const;
    virtual Body GetBodyType()const;
    virtual Equipment GetEquipmentType()const;
};