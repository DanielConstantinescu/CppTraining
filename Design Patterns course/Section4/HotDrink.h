#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct HotDrink
{
    virtual ~HotDrink() = default;

    virtual void prepare(int voume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override {
        cout << "Take tea bag, boild water, pour " << volume 
             << "ml, add some lemon" << endl;
    }
};

struct Coffee : HotDrink
{
    void prepare(int volume) override {
        cout << "Grind some beans, boild water, pour " << volume 
             << "ml, add some cream, enjoy!" << endl;
    }
};