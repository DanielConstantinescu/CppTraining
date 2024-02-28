/*
The find function in std::string uses a case-sensitive search.
Write a function that also performs a case insensitive search.
Use an enum to decide between case-sensitive and case-insensitive search
*/

#include <cstring>
#include <string>
#include <iostream>

enum class Case{SENSITIVE, INSENSITIVE};

// Function to convert a string to lower case. WIll be used in insensitive case search
std::string ToLower(const std::string &str) {
    std::string result = str;

    for (int i=0; i <str.size(); i++) {
        result[i] = tolower(str[i]);
    }

    return result;
}

size_t Find(
        const std::string &source,            // Source string to be searched
        const std::string &search_string,     // The string to search for
        Case searchCase = Case::INSENSITIVE,  // Choose case sensitive/insensitive search
        size_t offset = 0) 
{
    size_t index;
    if (searchCase == Case::SENSITIVE) {
        index = source.find(search_string, offset);
    } else {
        std::string new_source = ToLower(source);
        std::string new_search = ToLower(search_string);

        index = new_source.find(new_search, offset);

    }

    return index;
}

int main() {

    std::string source {"ABCabcDEFdef"};
    std::string search_string{"abc"};
    size_t index;

    index = Find(source, search_string, Case::SENSITIVE, 0);

    std::cout << "For case sensitive search, the position is: " << index << std::endl;

    index = Find(source, search_string, Case::INSENSITIVE, 0);

    std::cout << "For case insensitive search, the position is: " << index << std::endl;

    return 0;

}