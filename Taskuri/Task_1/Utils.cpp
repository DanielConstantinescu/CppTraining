#include "Utils.h"
#include <iostream>
#include "Electric.h"

std::string Utils::printFuel(Fuel f)
{
    switch (f)
    {
        case Fuel::PETROL: return "Petrol";
        case Fuel::DIESEL: return "Diesel";
        case Fuel::ELECTRIC: return "Electric";
        case Fuel::LPG: return "Liquefied Petroleum Gas";
        default: return "Default";
    }
}

std::string Utils::printBody(Body b)
{
        switch (b)
    {
        case Body::SEDAN: return "Sedan";
        case Body::SPORT: return "Sport";
        case Body::HATCHBACK: return "Hatchback";
        case Body::CONVERTIBLE: return "Convertible";
        case Body::MINIVAN: return "Minivan";
        default: return "Default";
    }
}

std::string Utils::printTraction(Traction t)
{
    switch (t)
    {
        case Traction::BRAKE: return "Brake";
        case Traction::TYRE: return "Tyre";
        case Traction::ANTILOCK: return "Antilock";
        default: return "Default";
    }
}

std::string Utils::printEquipment(Equipment e)
{
    switch (e)
    {
        case Equipment::FULL: return "Full";
        case Equipment::BASIC: return "Basic";
        case Equipment::CUSTOM: return "Custom";
        default: return "Default";
    }
}

void Utils::Print(Electric car)
{
    std::cout << std::endl;
    std::cout << "The vehicle is an electric car" << std::endl;
    std::cout << "Battery level is: " << car.GetFuelLevel() << std::endl;
    std::cout << "Enough battery for " << DistanceToCover(car.GetFuelLevel(), car.GetHP()) << " km" << std::endl;
    std::cout << "The fuel type is: " << printFuel(car.GetFuelType()) << std::endl;
    std::cout << "The body type is: " << printBody(car.GetBodyType()) << std::endl;
    std::cout << "The traction type is: " << printTraction(car.GetTractionType()) << std::endl;
    std::cout << "The engine power is: " << car.GetHP() << std::endl;
    std::cout << "The equipment package is: " << printEquipment(car.GetEquipmentType()) << std::endl;
    std::cout << "The identification code is: " << car.Identify() << std::endl;
}

void Utils::Print(Petroleum car)
{
    std::cout << std::endl;
    std::cout << "The vehicle is a petroleum car" << std::endl;
    std::cout << "Fuel level is: " << car.GetFuelLevel() << std::endl;
    std::cout << "Enough fuel for " << DistanceToCover(car.GetFuelLevel(), car.GetHP()) << " km" << std::endl;
    std::cout << "The fuel type is: " << printFuel(car.GetFuelType()) << std::endl;
    std::cout << "The body type is: " << printBody(car.GetBodyType()) << std::endl;
    std::cout << "The traction type is: " << printTraction(car.GetTractionType()) << std::endl;
    std::cout << "The engine power is: " << car.GetHP() << std::endl;
    std::cout << "The equipment package is: " << printEquipment(car.GetEquipmentType()) << std::endl;
    std::cout << "The identification code is: " << car.Identify() << std::endl;
}

float Utils::DistanceToCover(float fuel, int power)
{
    float distance = 0.0;

    while (fuel > 10) {
        distance = distance + power / 10;
        fuel -= 10;
    }

    if (fuel > 0) {
        distance = distance + power / fuel;
    }

    return distance;
}

