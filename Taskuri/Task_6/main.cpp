#include "Renault.h"
#include <iostream>

int main() {
    Renault car{0, Fuel::DIESEL, Body::HATCHBACK, Equipment::BASIC};

    ModifyVehicle obs_1;
    ModifyVehicle obs_2;

    // Add two observers to the object
    car.registerObserver(&obs_1);
    car.registerObserver(&obs_2);

    std::cout << "First customization:" << std::endl;
    car.customize(25.0, Fuel::LPG, Body::MINIVAN, Equipment::FULL);

    std::cout << "Second customization:" << std::endl;
    car.customize(80.0, Fuel::PETROL, Body::SEDAN, Equipment::CUSTOM);

    return 0;
}