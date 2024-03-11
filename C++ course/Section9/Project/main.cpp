#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>

int main() {
/* Check Saving
    Savings acc("Bob", 1000, 0.5f);
    std::cout << "Initial balance: " << acc.GetBalance() << std::endl;

    acc.Deposit(200);
    acc.AccumulateInterest();
    acc.Withdraw(380);
    std::cout << "Balance: " << acc.GetBalance() << std::endl;
*/

/* Check Checking
    Checking acc("Bob", 1000);
    std::cout << "Initial balance:" << acc.GetBalance() << std::endl;
    acc.Withdraw(980);
    std::cout << "Balance:" << acc.GetBalance() << std::endl;
*/

/* Checking Transaction
    Checking acc("Bob", 100);
    Transact(&acc);

    Savings acc2("Jon", 100, 0.5f);
    Transact(&acc2);
*/

/* Object Slicing
    Checking ch("Bob", 100, 50);
    Account *pAccount = &ch;     // This is known as upcasting. We cast a child object as a base class object
                                 // We can call child class methods trough the base class object.
                                 // For this to work, the base class object must be a pointer or a reference. Will not work for a full object

    // Account pAccount = ch     // If we use it like this, the compiler will use Object Slicing to slice the child class object so it can fit in
                                 // base class object

    Checking *pChecking = static_cast<Checking*>(pAccount); // Compiler will not allow this without a cast. This cast is known as Downcast
                                                            // Downcast -> when we assign a base class pointer to a child class pointer

*/
/* Testing minimum balance */
    //Checking ch("Bob", 100, 50);
    //Transact(&ch);

    // Now, instead of create instance of Checkings, we will use an instance of Savings
    Checking ch("Bob", 100, 50);
    Transact(&ch);

    /* Test typeid
    int i{};
    float f{};
    const std::type_info &ti = typeid(ch);
    std::cout << ti.name() << std::endl;    // we use name to print the name of the type
    */




    return 0;
}