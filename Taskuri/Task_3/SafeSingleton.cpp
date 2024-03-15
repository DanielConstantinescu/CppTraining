#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

/* A safe sinleton respects the next steps:
      - hide or delete the type's constructor, copy constructor and copy assignment operators;
      - create a static method that returns a reference to a static member. */

class SingletonDatabase
{
    // The constructor is private to ensure the user cannot call it directly
    SingletonDatabase()
    {
        ifstream input_file("powers.txt");

        string brand, power;

        while (getline(input_file, brand))
        {
            getline(input_file, power);
            int pow = lexical_cast<int>(power);
            powers[brand] = pow;
        }
    }

    map<string, int> powers;
public:

    // Set copy constructor and copy assignment as deleted to ensure a default version will not be generated
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    // get function that returns the reference of the static member
    static SingletonDatabase& get() {
        static SingletonDatabase db;
        return db;
    }

    int get_horse_power(const string& brand)
    {
        return powers[brand];
    }

};

int main()
{
    string brand = "Lotul Evija";
    cout << brand << " has a horse power of " << SingletonDatabase::get().get_horse_power(brand) << endl;

    return 0;
}
