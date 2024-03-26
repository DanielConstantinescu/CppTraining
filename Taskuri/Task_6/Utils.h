#include <iostream>
#include "Vehicle.h"

enum class Fuel {DEFAULT = 0, PETROL, DIESEL, LPG};
enum class Body {DEFAULT = 0, SEDAN, SPORT, HATCHBACK, CONVERTIBLE, MINIVAN};
enum class Equipment {DEFAULT = 0, FULL, BASIC, CUSTOM};

class Utils {
public:
static std::string printFuel(Fuel f)
{
    switch (f)
    {
        case Fuel::PETROL: return "Petrol";
        case Fuel::DIESEL: return "Diesel";
        case Fuel::LPG: return "Liquefied Petroleum Gas";
        default: return "Default";
    }
}

static std::string printBody(Body b)
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

static std::string printEquipment(Equipment e)
{
    switch (e)
    {
        case Equipment::FULL: return "Full";
        case Equipment::BASIC: return "Basic";
        case Equipment::CUSTOM: return "Custom";
        default: return "Default";
    }
}
};