#pragma once
#include "Vehicle.h"

class Electric : public Vehicle {
public:
    Electric(float fuellevel, Body bodytype, int power, Equipment equipmenttype, int ID);

    virtual float GetFuelLevel()const;
    virtual void fuelCar(float fuel);
    virtual Fuel GetFuelType()const;
    virtual Body GetBodyType()const;
    virtual Traction GetTractionType()const;
    virtual int GetHP()const;
    virtual Equipment GetEquipmentType()const;
    virtual int* Identify()const;

    ~Electric();

};