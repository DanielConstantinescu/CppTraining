#include <iostream>
#include <sstream>

int main() {
    int a{5}, b{6};
    int sum = a + b;

    std::cout << "Sum of " << a << " & " << b << " is : " << sum << std::endl;

    // But maybe we need it to display it somewhere else, not in cout, so we store it in a variable

    //std::string output = "Sum of " + a + " & " + b + " is " + sum;  // Will not work because integer are not automatically transformed in strings

    std::stringstream ss;
    
    //std::istringstream is;
    //std::ostringstream os;

    ss << "Sum of " << a << " & " << b << " is : " << sum << std::endl;
    
    std::string s = ss.str();   // converts the buffer to a string
    // ss.str("")      // Assign a stream to the internal buffer

    std::cout << s << std::endl;

    // Using string stream we can also convert parameter type into string object

    ss.str(""); // to clear the string stream

    ss << sum;
    auto ssum = ss.str();
    std::cout << ssum << std::endl;

    ssum = std::to_string(24);      // C++ function that converts other types to string
    std::cout << ssum << std::endl;

    // To read from a string stream
    std::string data = "12 89 21";
    int c;
    std::stringstream ss_data;
    ss_data.str(data);

    // If we use fail, the last number will be written twice. TO AVOID IT, we can use the read function directly in the condition
    /*
    while (!ss_data.fail()) {
        ss_data >> c;
        std::cout << c << std::endl;
    }
    */

    while (ss_data >> c) {
        std::cout << c << std::endl;
    }

    // C++ also offers functions for converting string into primitive types

    int x = std::stoi("54");   // stoi stands for string to integer

    

    return 0;
}