#include <iostream>
#include "Utils.h"

// Observer abstract class
class Observer {
public:
    virtual void update(float fuelLevel, Fuel fuelType, Body bodyType, Equipment equipmentType) = 0;
};

// Class that implements the update function for the observer
class ModifyVehicle : public Observer {
public:
    void update(float fuelLevel, Fuel fuelType, Body bodyType, Equipment equipmentType) {
        Display(fuelLevel, fuelType, equipmentType, bodyType);
    }

    void Display(float fuelLevel, Fuel fuelType, Equipment equipmentType, Body bodyType) {
        std::cout << "Observer detected the next attributes:" << std::endl;
        std::cout << "Fuel level: " << fuelLevel << std::endl;
        std::cout << "Fuel type: " << Utils::printFuel(fuelType) << std::endl;
        std::cout << "Equipment type: " << Utils::printEquipment(equipmentType) << std::endl;
        std::cout << "Body type: " << Utils::printBody(bodyType) << std::endl << std::endl;
    }
};