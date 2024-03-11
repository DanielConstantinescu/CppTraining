#pragma once
#include "Account.h"

// We choose to send as parameter an Account because a base class represents all its child classes. As long as we send it as pointer
// We can use this function on all child types like Checking or Saving
void Transact(Account *pAccount);