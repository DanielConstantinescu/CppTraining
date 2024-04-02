#include "Electric.h"
#include "Vehicle.h"
#include <iostream>

//Parameterized constructor
Electric::Electric(float fuellevel, 
                   Body bodytype,  
                   int power, 
                   Equipment equipmenttype,
                   int ID)

{
    m_FuelLevel = fuellevel;
    m_FuelType = Fuel::ELECTRIC;
    m_BodyType = bodytype;
    m_TractionType = Traction::BRAKE;
    m_Power = 1000;
    m_EquipmentType = equipmenttype;
    m_VIN = new int(ID);
    
    std::cout << "Electric(float, Body, int, Equipment, int)" << std::endl;

}

// Copy constructor
Electric::Electric(const Electric &obj)
{
    m_FuelLevel = obj.m_FuelLevel;
    m_FuelType = Fuel::ELECTRIC;
    m_BodyType = obj.m_BodyType;
    m_TractionType = obj.m_TractionType;
    m_Power = obj.m_Power;
    m_EquipmentType = obj.m_EquipmentType;
    m_VIN = new int(*obj.m_VIN);

    std::cout << "Electric(Electric &)" << std::endl;

}

// Move constructor
Electric::Electric(Electric &&obj)
{
    // Moving from source to destination
    m_FuelLevel = obj.m_FuelLevel;
    m_FuelType = Fuel::ELECTRIC;
    m_BodyType = obj.m_BodyType;
    m_TractionType = obj.m_TractionType;
    m_Power = obj.m_Power;
    m_EquipmentType = obj.m_EquipmentType;
    m_VIN = new int(*obj.m_VIN);

    // Clear resources from source
    obj.m_FuelLevel = 0;
    obj.m_FuelType = Fuel::DEFAULT;
    obj.m_BodyType = Body::DEFAULT;
    obj.m_TractionType = Traction::DEFAULT;
    obj.m_Power = 0;
    obj.m_EquipmentType = Equipment::DEFAULT;
    obj.m_VIN = nullptr;

    std::cout << "Electric(Electric &&)" << std::endl;

}

// Copy assignment
Electric &Electric::operator=(const Electric &obj)
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
    std::cout << "Electric =(Electric &)" << std::endl;

    return *this;
}

// Move assignment
Electric &Electric::operator=(Electric &&obj)
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
    std::cout << "Electric =(Electric &&)" << std::endl;
    return *this;
    
}

float Electric::GetFuelLevel() const
{
    return m_FuelLevel;
}

void Electric::fuelCar(float fuel)
{
    m_FuelLevel += fuel;
}

Fuel Electric::GetFuelType() const
{
    return Fuel::ELECTRIC;
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
    std::cout << "~Electric()" << std::endl;
}
