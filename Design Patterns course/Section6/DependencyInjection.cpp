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

class Database
{
public:
    virtual int get_population(const string& name) = 0;
};

class SingletonDatabase : public Database
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

class DummyDatabase : public Database
{
    map<string, int> capitals;
public:
    DummyDatabase() {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gamma"] = 3;
    }

    int get_population(const string &name) override {
        return capitals[name];
    }
};

struct SingletonRecordFinder
{
    int total_population(vector<string> names)
    {
        int result{0};

        for(auto& name : names)
            result += SingletonDatabase::get().get_population(name);

        return result;
    }
};

struct ConfigurableRecordFinder
{
    Database& db;

    ConfigurableRecordFinder(Database *db) : db(db) {}

    int total_population(vector<string> names)
    {
        int result{0};

        for(auto& name : names)
            result += db.get_population(name);

        return result;
    }
};

TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
    SingletonRecordFinder rf;
    vector<string> names{"Seoul", "Mexico City"};
    int tp = rf.total_population(names);
    EXPECT_EQ(17500000+17400000, tp);
}

TEST(RecordFinderTests, DependentTotalPopulationTest)
{
    DummyDatabase db;
    ConfigurableRecordFinder rg{db};
    EXPECT_EQ(4, rf.total_population(vector<string>{"alpha", "gamma"}));
}


int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();

}