#include "Transaction.h"
#include <iostream>
#include "Checking.h"
#include <typeinfo>

// We choose to send as parameter an Account because a base class represents all its child classes. As long as we send it as pointer
// We can use this function on all child types like Checking or Saving
void Transact(Account *pAccount)
{
    std::cout << "Transaction started" <<std::endl;
    std::cout << "Initial balance: " << pAccount->GetBalance() << std::endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();

    // If we blind asting a checking to an account, we might encounter a lot of problems because the account pointer might be pointing to another child class
    // That's why we should check before casting

    //Checking *pChecking = static_cast<Checking*>(pAccount);
    //std::cout << "Minimum balance: " << pChecking->GetMinimumBalance() << std::endl;

    /* Using typeinfo
    if (typeid(*pAccount) == typeid(Checking)) {
        Checking *pChecking = static_cast<Checking*>(pAccount);
        std::cout << "Minimum balance: " << pChecking->GetMinimumBalance() << std::endl;
    }
    */

    // Instead of performing this, we can use dynamic cast.
    // Dynamic cast checks if the cast can be performed. If it can, will return the pointer. If not, will return null.
    Checking *pChecking = dynamic_cast<Checking*>(pAccount);
    if (pChecking != nullptr) {
        std::cout << "Minimum balance: " << pChecking->GetMinimumBalance() << std::endl;
    }

    pAccount->Withdraw(170);
    std::cout << "Interest rate: " << pAccount->GetInterestRate() << std::endl;
    std::cout << "Final balance: " << pAccount->GetBalance() <<std::endl;
}