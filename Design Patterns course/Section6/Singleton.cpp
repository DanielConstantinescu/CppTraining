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
#include <map>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

class SingletonDatabase
{
    SingletonDatabase()
    {
        cout << "Initializing database" << endl;
        ifstream ifs("capitals.txt");

        string s, s2;

        while (getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }

    map<string, int> capitals;
public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get() {
        static SingletonDatabase db;
        return db;
    }

    int get_population(const string& name)
    {
        return capitals[name];
    }

};



int main()
{
    string city = "Tokyo";
    cout << city << " has population " << SingletonDatabase::get().get_population(city) << endl;

    return 0;
}