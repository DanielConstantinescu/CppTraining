#include <iostream>
#include <cstring>
#include <string>

// Implement conversion to lower case and upper case for std::string

std::string ToUpper(const std::string &str) {
    std::string result = str;

    for (int i=0; i <str.size(); i++) {
        result[i] = toupper(str[i]);
    }

    return result;
}

std::string ToLower(const std::string &str) {
    std::string result = str;

    for (int i=0; i <str.size(); i++) {
        result[i] = tolower(str[i]);
    }

    return result;
}

int main() {
    std::string s;
    
    std::cout << "Enter string: " << std::endl;
    std::cin >> s;

    std::cout << ToUpper(s) << std::endl;
    std::cout << ToLower(s) << std::endl;


    return 0;
}