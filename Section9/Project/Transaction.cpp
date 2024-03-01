#include "Transaction.h"
#include <iostream>

// We choose to send as parameter an Account because a base class represents all its child classes. As long as we send it as pointer
// We can use this function on all child types like Checking or Saving
void Transact(Account *pAccount)
{
    std::cout << "Transaction started" <<std::endl;
    std::cout << "Initial balance: " << pAccount->GetBalance() << std::endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();
    pAccount->Withdraw(170);
    std::cout << "Interest rate: " << pAccount->GetInterestRate() << std::endl;
    std::cout << "Final balance: " << pAccount->GetBalance() <<std::endl;
}