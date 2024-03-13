// Task 1
#pragma once
#include "Vehicle.h"

class Electric : public Vehicle {
public:
    // Parameterized constructor
    Electric(float fuellevel, Body bodytype, int power, Equipment equipmenttype, int ID);

    // Copy constructor
    Electric (const Electric &obj);

    // Move constructor
    Electric(Electric &&obj);

    // Copy assignment
    Electric & operator=(const Electric &obj);

    // Move assignment
    Electric & operator=(Electric &&obj);

    // Destructor
    ~Electric();

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
