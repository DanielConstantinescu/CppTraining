#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>
using namespace std;

#include "HotDrinkFactory.h"
#include "DrinkFactory.h"

/* ABSTRACT FACTORY*/


int main()
{
    DrinkFactory df;
    auto c = df.make_drink("coffee"); 

    return 0;
}