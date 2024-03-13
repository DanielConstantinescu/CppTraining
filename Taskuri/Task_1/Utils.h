// Task 1
#include <iostream>
#include "Electric.h"
#include "Petroleum.h"
#include "Vehicle.h"

class Utils {
public:
static std::string printFuel(Fuel f);
static std::string printBody(Body b);
static std::string printTraction(Traction t);
static std::string printEquipment(Equipment e);

static void Print(Electric car);
static void Print(Petroleum car);
static float DistanceToCover(float fuel, int power);
};
