#pragma once
#include "HotDrink.h"

struct HotDrinkFactory
{
    virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};

struct CofeeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    }
};