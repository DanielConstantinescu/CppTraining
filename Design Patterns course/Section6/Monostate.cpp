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
#include <map>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

class Printer
{
    static int id;
public:
    int get_id() const {return id;}

    void set_id(int value) {id = value;}
};

int main() {
    Printer p;
    int id = p.get_id();

    Printer p2;

}