// Task 1
#include "Tesla.h"
#include "Electric.h"
#include <iostream>

Tesla* Tesla::instancePtr = NULL;

// Move constructor
Tesla::Tesla(Tesla &&obj) : Tesla(obj.m_FuelLevel,
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
    std::cout << "Tesla(Tesla &&)" << std::endl;
}

// Move assignment
Tesla &Tesla::operator=(Tesla &&obj)
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
    std::cout << "Tesla (Tesla &&)" << std::endl;


    return *this;
}

float Tesla::GetFuelLevel() const
{
    return m_FuelLevel;
}

void Tesla::fuelCar(float fuel)
{
    std::cout << "Tesla Charging!" << std::endl;
    m_FuelLevel += fuel;
}

Fuel Tesla::GetFuelType() const
{
    return Fuel::ELECTRIC;
}

Body Tesla::GetBodyType() const
{
    return m_BodyType;
}

Traction Tesla::GetTractionType() const
{
    return m_TractionType;
}

int Tesla::GetHP() const
{
    return m_Power;
}

Equipment Tesla::GetEquipmentType() const
{
    return m_EquipmentType;
}

int *Tesla::Identify() const
{
    return m_VIN;
}

// Destructor
Tesla::~Tesla()
{
    std::cout << "~Tesla()" << std::endl;
}
