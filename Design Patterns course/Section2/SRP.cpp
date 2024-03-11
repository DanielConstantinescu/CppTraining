#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string &title) : title(title) {}

    void add_entry(const string& entry)
    {
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + ": " + entry);
    }

    /* It would be bad practice to implement a save method for all our classes. */
    void save(const string& filename) {
        ofstream ofs(filename);
        for(auto& e : entries)
            ofs << e << endl;
    }
};

/* It is more viable to have a separate class that takes care of operations like save and load.
   This also respects the Single Responsibility Principle. */
struct PersistenceManager
{
    void save(const Journal& j, const string& filename) {
        ofstream ofs(filename);
        for(auto& e : j.entries)
            ofs << e << endl;
    } 
};

int main() {
    Journal journal{"Dear Diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");

    //journl.save("diary.txt");

    PersistenceManager pm;
    pm.save(journal, "diary.txt");

    getchar();
    return 0;
}