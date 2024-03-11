#include <iostream>
#include <cstring>
#include <string>

// We get a warning for returning the address of fullname. Fullname is visible only in the function and there is no guarantee it is available
// after the function has returned.
//
// To avoid using fixed arrays for string definition, we will use dynamic memory allocation.

const char * Combine(const char *pFirst, const char *pLast) {
    //char fullname[20];  // Fixed array are not a solution
    char *fullname = new char[strlen(pFirst) + strlen(pLast) + 1];  // dynamic memory allocation ; +1 for the string end character

    strcpy(fullname, pFirst);
    strcat(fullname, pLast);
    return fullname;

}

void StringExample() {
    char first[10];   // We are using fixed size arrays and this is not a good idea
    char last[10];
    std::cin.getline(first, 10);
    std::cin.getline(last, 10);

    const char *pFullName = Combine(first, last);

    std::cout << pFullName <<std::endl;

    delete[] pFullName;   // we use delete for arrays because we do not know if pFullName is alocated as a char or a string

    // Initialize & assign

    std::string s = "Hello";  // string class provides constructors and operator overloading
    s = "Hello";

    // Acces characters inside the string

    s[0] = 'W';
    char ch = s[0];

    std::cout << s << std::endl;   // to print
    std::cin >> s;                 // to read

    std::getline(std::cin, s);     // to read an entire line

    // Size
    s.length();       // How many characters are in the string. Faster than classic method because String class cache the length

    // Insert & concatenate
    std::string s1{"Hello"}, s2{"World"};
    s = s1 + s2;              // Concatenate strings

    s += s1;     // Add s1 to s

    s.insert(6, "abc");

    // Comparison
    if (s1 == s2) {

    }

    // Removal
    s.erase();   // clear the string
    s.clear();   // clear the string

    s.erase(0, 5);

    // Search

    auto pos = s.find("World", 0);
    
    if (pos != std::string::npos ) {
        //FOund
    }

}

void UsingStdString() {

}

int main() {

    std::string first;
    std::string last;

    std::getline(std::cin, first);
    std::getline(std::cin, last);

    std::string fullname = first + last;
    std::cout << fullname << std::endl;


    return 0;
}