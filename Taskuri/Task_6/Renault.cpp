#include "Renault.h"
#include <iostream>

// Parameterized constructor
Renault::Renault(float fuellevel, Fuel fueltype, Body bodytype, Equipment equipmenttype) :
        Petroleum(fuellevel, fueltype, bodytype, equipmenttype) 
{}

// Function that notifies the observer and call the update member
void Renault::notifyObservers()
{
    for (Observer* observer : observers) {
        observer->update(m_FuelLevel, m_FuelType, m_BodyType, m_EquipmentType);
    }
}

// Function that modifies the object and notify the obervers
void Renault::customize(float fuellevel, Fuel fueltype, Body bodytype, Equipment equipmenttype)
{
    m_FuelLevel = fuellevel;
    m_FuelType = fueltype;
    m_BodyType = bodytype;
    m_EquipmentType = equipmenttype;
    notifyObservers();
}
