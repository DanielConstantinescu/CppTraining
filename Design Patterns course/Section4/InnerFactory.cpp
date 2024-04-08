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

/* INNER FACTORY */
// Sometimes

enum class PointType
{
    cartesian,
    polar
};

struct Point
{
private:
    Point(float x, float y) : x(x), y(y) {}

    float x, y;

    class PointFactory 
    {  
        PointFactory();
    public:
        // static methods that invoke the constructor
        static Point NewCartesian(float x, float y) {
            return {x, y};
        }

        static Point NewPolar(float r, float theta) {
            return {r*cos(theta), r*sin(theta)};
        }
    };

public:
    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }

    // Inner factory using singleton
    static PointFactory Factory;
};

int main()
{
    auto p = Point::Factory.NewPolar(5, M_PI_4);
    cout << p << endl;

    return 0;
}