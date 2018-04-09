/*
 * pimpl_main.cpp
 *
 *  Created on: 09-Apr-2018
 *      Author: maran
 */

#include "Pimpl_Account.h"
int main() {
  Pimpl_Account a1 {10, nullptr};
  a1.deposit(100);
  return a1.withdraw(20);
}



