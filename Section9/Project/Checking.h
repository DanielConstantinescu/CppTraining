#pragma once
#include "Account.h"

class Checking : public Account {
public:
    using Account::Account;    // this will cause all the constructors of the base class to be inherited in the child class
    float m_MinimumBalance;

    Checking(const std::string &name, float balance, float minbalance);
    ~Checking();
    void Withdraw(float amount);
    float GetMinimumBalance()const;
};