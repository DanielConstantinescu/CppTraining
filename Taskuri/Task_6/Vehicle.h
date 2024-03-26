#pragma once
# include "Observer.h"

class Vehicle {
protected:
    float m_FuelLevel;
    Fuel m_FuelType;
    Body m_BodyType;
    Equipment m_EquipmentType;
public:
    virtual float GetFuelLevel()const = 0;
    virtual void fuelCar(float fuel) = 0;
    virtual Fuel GetFuelType()const = 0;
    virtual Body GetBodyType()const = 0;
    virtual Equipment GetEquipmentType()const = 0;

};