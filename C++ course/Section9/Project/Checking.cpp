#include "Checking.h"

#include <iostream>
Checking::Checking(const std::string &name, float balance, float minbalance):Account(name, balance), m_MinimumBalance(minbalance){
}


Checking::~Checking() {
}

float Checking::GetMinimumBalance() const
{
    return m_MinimumBalance;
}

void Checking::Withdraw(float amount) {
	if ((m_Balance - amount) > m_MinimumBalance) {
		Account::Withdraw(amount);
	} else {
		std::cout << "Invalid amount" << std::endl;
	}
}
