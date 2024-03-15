#include "MakeCarFactory.h"
#include "CarFactory.h"
#include <iostream>


int main() {
    MakeCarFactory cf;
    auto car1 = cf.make_car("electric");
    auto car2 = cf.make_car("petroleum");

    return 0;
}