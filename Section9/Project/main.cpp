#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"

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

/* Checking Transaction */
    Checking acc("Bob", 100);
    Transact(&acc);

    Savings acc2("Jon", 100, 0.5f);
    Transact(&acc2);
    return 0;
}