#include <iostream>
#include <vector>
#include <cstring>
#include <string>

// Add one more function called FindAll, that returns the starting indeces of all the
// found substrings in a target string. Return the indices in a vector. Support case sensitive/insensitive search

enum class Case{SENSITIVE, INSENSITIVE};

// Function to convert a string to lower case. WIll be used in insensitive case search
std::string ToLower(const std::string &str) {
    std::string result = str;

    for (int i=0; i <str.size(); i++) {
        result[i] = tolower(str[i]);
    }

    return result;
}

std::vector<int> FindAll (
                const std::string &target,                   // Target tring to be searched
                const std::string &search_string,            // The string to search for
                Case searchCase = Case::INSENSITIVE,         // Choose case sensitive/insensitive search
                size_t offset = 0)                           // Start search from this
{
    size_t index = offset;
    std::vector<int> results;
    size_t current_pos = offset;

    if (searchCase == Case::SENSITIVE) {
        while (current_pos < search_string.size() && index != std::string::npos) {
            index = search_string.find(target, current_pos);
            results.push_back(index);
            current_pos = current_pos + target.size();
        }
    } else {
        std::string lowerTarget = ToLower(target);
        std::string lowerSearchStr = ToLower(search_string);

        while (current_pos < lowerSearchStr.size() && index != std::string::npos) {
            index = lowerSearchStr.find(lowerTarget, current_pos);
            results.push_back(index);
            current_pos = current_pos + target.size();
        }

    }

    return results;

}

int main() {
    std::string search_string{"abcABCabcABC"};
    std::string target{"abc"};

    std::vector<int> result;

    result = FindAll(target, search_string, Case::SENSITIVE, 0);

    if (result.size() == 0) {
        std::cout << "No result returned" << std::endl;
    }else {
        for(int x : result) {
            std::cout << x << " ";
        }

    }
    std::cout << std::endl;

    result.clear();

    result = FindAll(target, search_string, Case::INSENSITIVE, 0);

    if (result.size() == 0) {
        std::cout << "No result returned" << std::endl;
    }else {
        for(int x : result) {
            std::cout << x << " ";
        }

    }
    std::cout << std::endl;

    return 0;
}