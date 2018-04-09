#pragma once

class Customer;

class Pimpl_AccountImpl {
private:
  int balance;
public:
  Pimpl_AccountImpl(int bal, Customer *);
  int deposit(int amt);
  int withdraw(int amt);
};
