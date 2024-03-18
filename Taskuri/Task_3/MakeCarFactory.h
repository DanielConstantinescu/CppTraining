#pragma once
#include "Car.h"
#include "CarFactory.h"
#include <map>

// Factory that builds cars based on their type
class MakeCarFactory
{
    std::map<std::string, std::unique_ptr<CarFactory>> car_factories;

public:
    MakeCarFactory() {
        car_factories["electric"] = std::make_unique<ElectricFactory>();
        car_factories["petroleum"] = std::make_unique<PetroleumFactory>();
    }

    std::unique_ptr<Car> make_car(const std::string& car_type) {
        auto car = car_factories[car_type]->build_car();
        car->fuel(50);
        return car;
    }
};
