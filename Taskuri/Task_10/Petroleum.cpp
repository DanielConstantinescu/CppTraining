#include "Petroleum.h"
#include <iostream>

// Parameterized constructor
Petroleum::Petroleum(float fuellevel, Fuel fueltype, Body bodytype, int power, Equipment equipmenttype, int ID)
{
    m_FuelLevel = fuellevel;
    m_FuelType = fueltype;
    m_BodyType = bodytype;
    m_TractionType = Traction::BRAKE;
    m_Power = 1000;
    m_EquipmentType = equipmenttype;
    m_VIN = new int(ID);

    std::cout << "Petroleum(float, Fuel, Body, int, Equipment, int)" << std::endl;
}

// Copy constructor
Petroleum::Petroleum(const Petroleum &obj)
{
    m_FuelLevel = obj.m_FuelLevel;
    m_FuelType = obj.m_FuelType;
    m_BodyType = obj.m_BodyType;
    m_TractionType = obj.m_TractionType;
    m_Power = obj.m_Power;
    m_EquipmentType = obj.m_EquipmentType;
    m_VIN = new int(*obj.m_VIN);

    std::cout << "Petroleum(Petroleum &)" << std::endl;
}

// Move constructor
Petroleum::Petroleum(Petroleum &&obj)
{
    // Moving from source to destination
    m_FuelLevel = obj.m_FuelLevel;
    m_FuelType = obj.m_FuelType;
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

    std::cout << "Petroleum(Petroleum &&)" << std::endl;
}

// Copy assignment
Petroleum &Petroleum::operator=(const Petroleum &obj)
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

    std::cout << "Petroleum =(Petroleum &)" << std::endl;

    return *this;
}

// Move assignment
Petroleum &Petroleum::operator=(Petroleum &&obj)
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
    std::cout << "Petroleum =(Petroleum &&)" << std::endl;

    return *this;
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

Traction Petroleum::GetTractionType() const
{
    return m_TractionType;
}

int Petroleum::GetHP() const
{
    return m_Power;
}

Equipment Petroleum::GetEquipmentType() const
{
    return m_EquipmentType;
}

int *Petroleum::Identify() const
{
    return m_VIN;
}

Petroleum::~Petroleum()
{
    std::cout << "~Petroleum()" << std::endl;
    free(m_VIN);
}
