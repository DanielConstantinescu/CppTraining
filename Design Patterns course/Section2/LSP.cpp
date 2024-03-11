#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int getWidth() const {
        return width;
    }

    virtual void setWidth(int width) {
        Rectangle::width = width;
    }

    int getHeight() const {
        return height;
    }

    virtual void setHeight(int height) {
        Rectangle::height = height;
    }

    int area() const { return width * height; }
};

class Square : public Rectangle
{
public:
    Square(int size): Rectangle(size, size) {}

    void setWidth(int with) override {
        this->width = this->height = width;
    }

    void setHeight(int height) override {
        this->width = this->height = height;
    }
};

void process(Rectangle& r)
{
    /* THis logic makes perfect sense for a rectangle, but not for a square */
    int w = r.getWidth();
    r.setHeight(10);

    cout << "expect area = " << (w*10) << ", got " << r.area() << endl;
}

/* We can use a factory to avoid creating a class Square that inherits Rectangle */
struct RectangleFactory
{
    static Rectangle create_rectanle(int w, int h);
    static Rectangle create_square(int size);
};

int main() {
    Rectangle r{3, 4};
    process(r);

    Square sq{5};
    process(sq);

    return 0;
}