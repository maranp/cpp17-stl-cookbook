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
    maran.SetResourceName("Maran resource");
    maran.SetResourceName("Maran second resource");
    Person maran2 = maran;
    //maran2.SetResourceName("Maran2 resource");
    maran = maran2;
  }
  return 0;
}


