/*
 * Pimpl_AccountImpl.cpp
 *
 *  Created on: 09-Apr-2018
 *      Author: maran
 */

#include "Pimpl_AccountImpl.h"

Pimpl_AccountImpl::Pimpl_AccountImpl(int bal, Customer *) : balance {bal} {}

int Pimpl_AccountImpl::deposit(int amt) {
  return balance += amt;
}

int Pimpl_AccountImpl::withdraw(int amt) {
  return balance -= amt;
}

