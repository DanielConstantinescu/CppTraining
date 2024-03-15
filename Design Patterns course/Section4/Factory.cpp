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

/* FACTORY */

enum class PointType
{
    cartesian,
    polar
};

struct Point
{
private:
    //friend class PointFactory; // violateds the OCP

public:    // We can make everything public to respect OCP but we expose the constructor
    // Constructor that is used internally
    Point(float x, float y) : x(x), y(y) {}

public:
    float x, y;

    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

struct PointFactory 
{
    // static methods that invoke the constructor
    static Point NewCartesian(float x, float y) {
        return {x, y};
    }

    static Point NewPolar(float r, float theta) {
        return {r*cos(theta), r*sin(theta)};
    }
};

int main()
{
    auto p = PointFactory::NewPolar(5, M_PI_4);
    cout << p << endl;

    return 0;
}