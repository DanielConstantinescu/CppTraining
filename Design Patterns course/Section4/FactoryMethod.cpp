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

/* FACTORY METHOD */

enum class PointType
{
    cartesian,
    polar
};

struct Point
{
private:
    // Constructor that is used internally
    Point(float x, float y) : x(x), y(y) {}

public:
    float x, y;

    // static methods that invoke the constructor
    static Point NewCartesian(float x, float y) {
        return {x, y};
    }

    static Point NewPolar(float r, float theta) {
        return {r*cos(theta), r*sin(theta)};
    }

    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

int main()
{
    auto p = Point::NewPolar(5, M_PI_4);
    cout << p << endl;

    return 0;
}