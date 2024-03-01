#pragma once
#include "Account.h"

class Checking : public Account {
public:
    using Account::Account;    // this will cause all the constructors of the base class to be inherited in the child class

    Checking(const std::string &name, float balance);
    ~Checking();
    void Withdraw(float amount);
};