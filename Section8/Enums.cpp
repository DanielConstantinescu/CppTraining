#include <iostream>

//enum Color{RED, GREEN, BLUE};   // has global scope

enum class Color : long{RED = 5, GREEN, BLUE};   // class keyword allows us to create scoped enums. The enumerators are visible only in their scope
// The values in enums are incremented by 1. If RED is 5, then GREEN will be 6 and BLUE will be 7


// We can pass any integer as argument and if that integer was not linked with a color, the programm won't know what to do with it
// To restricts the arguments the function can take, we can use an enum.

//void FillColor(int color) {
void FillColor(Color color) {
    // Fill background with some color

    if (color == Color::RED) {      // To fix the error, we need to refer the scope trough enum name. Color::RED
        // Paint with red
        std::cout << "RED" << std::endl;
    }
    else if (color == Color::GREEN) {
        // Paint with green
        std::cout << "GREEN" << std::endl;

    }
    else if (color == Color::BLUE) {
        // Paint with blue
        std::cout << "BLUE" << std::endl;

    }
}

// By using scoped enums, the name of enumerators will not clash
enum class TrafficLight : char{RED = 'c', GREEN, YELLOW};   // If we compile this code, we will get an error: RED and GREEN are being redefined ; global scope
// Green will be d and Yellow wil be e

int main() {
    Color c = Color::RED;
    FillColor(c);

    FillColor(Color::GREEN);

    //FillColor(5);    // The advantage in using enums is that we cannot pass any integer as argument
    FillColor(static_cast<Color>(2));  // This will match the BLUE
    FillColor(static_cast<Color>(5));  // This work but it will be undefined because it cannot match anything

    //int x = Color::RED; // THis will not work without an explicit static cast
    int x = static_cast<int>(Color::RED);


    return 0;
}