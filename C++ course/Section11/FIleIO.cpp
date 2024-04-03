#include <iostream>
#include <fstream>
#include <string>

void Write() {
    std::ofstream out{"data.txt"};
    out << "Hello World" << std::endl;
    out << 10 << std::endl;
    out.close();
}

void Read() {
    std::ifstream input{ "data.txt" };

    if (input.fail()) {
        std::cout << "Could not open the file" <<std::endl;
        return;
    }        
    
    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;

    if (input.eof()) {
        std::cout << "End of file encountered" << std::endl;
    }

    if (input.good()) {
        std::cout << "I/O operations are successful" << std::endl;
    } else {
        std::cout << "Some I/O operations failed" << std::endl;
    }
    input.close();
    std::cout << message << ":" << value << std::endl;
}

int main() {
    Write();
    Read();
    return 0;
}