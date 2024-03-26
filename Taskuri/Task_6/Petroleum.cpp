#include "Petroleum.h"
#include <iostream>

// Parameterized constructor
Petroleum::Petroleum(float fuellevel, Fuel fueltype, Body bodytype, Equipment equipmenttype)
{
    m_FuelLevel = fuellevel;
    m_FuelType = fueltype;
    m_BodyType = bodytype;
    m_EquipmentType = equipmenttype;
}

float Petroleum::GetFuelLevel() const
{
    return m_FuelLevel;
}

void Petroleum::fuelCar(float fuel)
{
    m_FuelLevel += fuel;
}

Fuel Petroleum::GetFuelType() const
{
    return m_FuelType;
}

Body Petroleum::GetBodyType() const
{
    return m_BodyType;
}


Equipment Petroleum::GetEquipmentType() const
{
    return m_EquipmentType;
}
