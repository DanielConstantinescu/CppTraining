#pragma once
#include "Car.h"

// Abstract Factory
// An abstract factory is used to create a hierarchy of factories that can be used to create related objects.
struct CarFactory {
    virtual std::unique_ptr<Car> build_car() const = 0;
};

// Factory 1
struct ElectricFactory : CarFactory {
    std::unique_ptr<Car> build_car() const override {
        return std::make_unique<ElectricCar>();
    }    
};

// Factory 2
struct PetroleumFactory : CarFactory {
    std::unique_ptr<Car> build_car() const override {
        return std::make_unique<PetroleumCar>();
    }    
};