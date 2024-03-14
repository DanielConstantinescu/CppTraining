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

struct Address
{
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite) : street(street), city(city), suite(suite) {}

    // Copy constructor
    Address(const Address& address) : street{address.street}, city{address.city}, suite{address.suite} {}

    friend ostream &operator << (ostream &os, const Address address) {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
};

struct Contact
{
    string name;
    Address* address;

    Contact(const string &name, Address *address) : name(name), address(address) {}

    // We can perform a deep copy by using a Copy constructor
    Contact(const Contact& other) : name{other.name}, address{new Address{*other.address}}
    {}

    ~Contact() {delete address; }

    friend ostream &operator << (ostream &os, const Contact &contact) {
        os << "name :" << contact.name << " address: " << *contact.address;
        return os;
    }
};

// Global variable solution
// A global variable with the main office address. But this is not explicit enough.
//Contact main_office{"", new Address{"123 East Dr", "London", 0}};

// Prototype factory solution ! DO NOT FORGET TO MAKE CONSTRUCTORS PRIVATE FOR THE OTHER CLASSES

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_empoyee (const string& name, const int suite) {
        static Contact p{"", new Address {"123 East Dr", "London", 0}};
        return new_employee(name, suite, p);
    }

private:
    static unique_ptr<Contact> new_employee(const string& name, const int suite, Contact& prototype)
    {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

int main()
{
    auto john = EmployeeFactory::new_main_office_empoyee("John", 123);

    cout << *john << endl;

    return 0;
}