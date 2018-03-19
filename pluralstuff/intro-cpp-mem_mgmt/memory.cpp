/*
 * memory.cpp
 *
 *  Created on: 19-Mar-2018
 *      Author: maran
 */

#include <iostream>
#include "Person.h"

auto dummy(Person p) {

}

int main() {
  {
    Person maran {"Maran", "P", 20};
    maran.AddResource();
    std::string s1 = maran.GetResourceName();
    maran.AddResource();
    Person m1 = maran;
    dummy(m1);
    std::cout << s1 << std::endl;
  }
  return 0;
}


