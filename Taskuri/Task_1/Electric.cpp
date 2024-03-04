#include "Electric.h"
#include "Vehicle.h"
#include <iostream>

Electric::Electric(float fuellevel, 
                   Body bodytype,  
                   int power, 
                   Equipment equipmenttype,
                   int ID)

{
    this->m_FuelLevel = fuellevel;
    this->m_FuelType = Fuel::ELECTRIC;
    this->m_BodyType = bodytype;
    this->m_TractionType = Traction::BRAKE;
    this->m_Power = 1000;
    this->m_EquipmentType = equipmenttype;
    this->m_VIN = &ID;
}


float Electric::GetFuelLevel() const
{
    return m_FuelLevel;
}

void Electric::fuelCar(float fuel)
{
    std::cout << "Charging!" << std::endl;
    m_FuelLevel += fuel;
}

Fuel Electric::GetFuelType() const
{
    return m_FuelType;
}

Body Electric::GetBodyType() const
{
    return m_BodyType;
}

Traction Electric::GetTractionType() const
{
    return m_TractionType;
}

int Electric::GetHP() const
{
    return m_Power;
}

Equipment Electric::GetEquipmentType() const
{
    return m_EquipmentType;
}

int *Electric::Identify() const
{
    return m_VIN;
}

Electric::~Electric()
{
    free(m_VIN);
}
