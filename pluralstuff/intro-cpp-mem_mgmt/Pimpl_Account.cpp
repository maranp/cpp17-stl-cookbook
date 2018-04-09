/*
 * Pimpl_Account.cpp
 *
 *  Created on: 09-Apr-2018
 *      Author: maran
 */

#include "Pimpl_Account.h"
#include "Pimpl_AccountImpl.h"
#include <memory>

Pimpl_Account::Pimpl_Account(int bal, Customer *cust) : pimpl(new Pimpl_AccountImpl{bal, cust}) {}
// see the explanation in class definition
Pimpl_Account::~Pimpl_Account() {}
Pimpl_Account::Pimpl_Account(Pimpl_Account && other) : pimpl {std::move(other.pimpl)} {}
Pimpl_Account& Pimpl_Account::operator=(Pimpl_Account && other) {
  pimpl = std::move(other.pimpl);
  return *this;
}
int Pimpl_Account::deposit(int amt) {
  return pimpl->deposit(amt);
}
int Pimpl_Account::withdraw(int amt) {
  return pimpl->withdraw(amt);
}



