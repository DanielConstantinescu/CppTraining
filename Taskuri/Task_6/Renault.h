#pragma once
#include <vector>
#include "Petroleum.h"

class Renault : public Petroleum {
public:
     std::vector<Observer*> observers;
public:
    // Parameterized constructor
    Renault(float fuellevel, Fuel fueltype, Body bodytype, Equipment equipmenttype);

    // Observer methods
    // Function that adds new observers to the vector of observers
    void registerObserver(Observer* observer) { observers.push_back(observer); }

    void notifyObservers();

    void customize(float fuellevel, Fuel fueltype, Body bodytype, Equipment equipmenttype);
};