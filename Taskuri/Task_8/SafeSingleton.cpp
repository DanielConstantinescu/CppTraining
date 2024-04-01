#include "SafeSingleton.h"

int main()
{
    string brand = "Lotus Evija";
    cout << brand << " has a horse power of " << SingletonDatabase::get().get_horse_power(brand) << endl;

    return 0;
}
