#include "Renault.h"
#include "Petroleum.h"
#include <iostream>

// Parameterized constructor
Renault::Renault(float fuellevel, Fuel fueltype, Body bodytype, int power, Equipment equipmenttype, int ID) :
        Petroleum(fuellevel, fueltype, bodytype, power, equipmenttype, ID) {}

Renault::Renault(const Renault &obj) : Renault(obj.m_FuelLevel,
                                                obj.m_FuelType,
                                                obj.m_BodyType,
                                                obj.m_Power,
                                                obj.m_EquipmentType,
                                                *obj.m_VIN)
{
    std::cout << "Renault(float, Fuel, Body, int, Equipment, int)" << std::endl;
}

// Move constructor
Renault::Renault(Renault &&obj) : Renault(obj.m_FuelLevel,
                                            obj.m_FuelType,
                                            obj.m_BodyType,
                                            obj.m_Power,
                                            obj.m_EquipmentType,
                                            *obj.m_VIN)
{
    // Clear resources from source
    obj.m_FuelLevel = 0;
    obj.m_FuelType = Fuel::DEFAULT;
    obj.m_BodyType = Body::DEFAULT;
    obj.m_TractionType = Traction::DEFAULT;
    obj.m_Power = 0;
    obj.m_EquipmentType = Equipment::DEFAULT;
    obj.m_VIN = nullptr;
    std::cout << "Renault(Renault &&)" << std::endl;
}

// Copy constructor
Renault::Renault(const Renault &obj) : Renault(obj.m_FuelLevel,
                                                obj.m_FuelType,
                                                obj.m_BodyType,
                                                obj.m_Power,
                                                obj.m_EquipmentType,
                                                *obj.m_VIN)
{
    std::cout << "Renault(Renault &)" << std::endl;
}

// Copy assignment
Renault &Renault::operator=(const Renault &obj)
{
    if (this != &obj) {
        m_FuelLevel = obj.m_FuelLevel;
        m_FuelType = obj.m_FuelType;
        m_BodyType = obj.m_BodyType;
        m_TractionType = obj.m_TractionType;
        m_Power = obj.m_Power;
        m_EquipmentType = obj.m_EquipmentType;

        delete m_VIN;
        m_VIN = new int(*obj.m_VIN);
    }
    std::cout << "Renault =(Renault &)" << std::endl;

    return *this;
}

// Move assignment
Renault &Renault::operator=(Renault &&obj)
{
    if (this != &obj) {
        // Move object
        m_FuelLevel = obj.m_FuelLevel;
        m_FuelType = obj.m_FuelType;
        m_BodyType = obj.m_BodyType;
        m_TractionType = obj.m_TractionType;
        m_Power = obj.m_Power;
        m_EquipmentType = obj.m_EquipmentType;

        delete m_VIN;
        m_VIN = new int(*obj.m_VIN);

        // Clear source
        obj.m_FuelLevel = 0;
        obj.m_FuelType = Fuel::DEFAULT;
        obj.m_BodyType = Body::DEFAULT;
        obj.m_TractionType = Traction::DEFAULT;
        obj.m_Power = 0;
        obj.m_EquipmentType = Equipment::DEFAULT;
        obj.m_VIN = nullptr;
    }
    std::cout << "Renault =(Renault &&)" << std::endl;

    return *this;
}

float Renault::GetFuelLevel() const
{
    return m_FuelLevel;
}

void Renault::fuelCar(float fuel)
{
    std::cout << "Renault Fueling!" << std::endl;
    m_FuelLevel += fuel;
}

Fuel Renault::GetFuelType() const
{
    return m_FuelType;
}

Body Renault::GetBodyType() const
{
    return m_BodyType;
}

Traction Renault::GetTractionType() const
{
    return m_TractionType;
}

int Renault::GetHP() const
{
    return m_Power;
}

Equipment Renault::GetEquipmentType() const
{
    return m_EquipmentType;
}

int *Renault::Identify() const
{
    return m_VIN;
}

// Destructor
Renault::~Renault()
{
    std::cout << "~Renault()" << std::endl;
    free(m_VIN);
}
