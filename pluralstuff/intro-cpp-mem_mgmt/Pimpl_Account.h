/*
 * Pimpl_Account.h
 *
 *  Created on: 09-Apr-2018
 *      Author: maran
 */

#pragma once
#include <memory>

class Pimpl_AccountImpl;
class Customer;

class Pimpl_Account {
private:
  std::unique_ptr<Pimpl_AccountImpl> pimpl;
public:
  Pimpl_Account(int bal, Customer *);
  // if an explicit destructor is not provided,
  // compiler generates a default destructor
  // which in turn generates default destructor for unique_ptr<Pimpl_accountImpl>
  // the default destructor for unique_ptr in turn generates a default deleter for type
  // passed as parameter to unique_ptr template which is Pimpl_AccountImpl
  // during which the deleter tries to find the size of Pimpl_AccountImpl
  // But, since Pimpl_AccountImpl is an incomplete type, instantiation of the deleter fails and build breaks.
  // so, create an explicit destructor to disallow the compiler from generating the above sequence of problem.
  ~Pimpl_Account();
  Pimpl_Account(Pimpl_Account && other);
  Pimpl_Account& operator=(Pimpl_Account && other);
  int deposit(int amt);
  int withdraw(int amt);
};
