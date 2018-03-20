/*
 * memory.cpp
 *
 *  Created on: 19-Mar-2018
 *      Author: maran
 */

#include <iostream>
using std::cout;
using std::endl;

#include "Person.h"
#include "Tweeter.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

auto dummy(Person const & p) {
  return p.GetNumber();
}

int main() {
//  Person p {"Maran", "P", 20};
  Tweeter t {"Maran", "P", 20, "@pmaran"};
  Person* p = &t;
  Tweeter* pt = static_cast<Tweeter *>(p); // compiler reasons (At compile time) whether the casting is legal
  cout << pt->GetName() << endl;

//  int i;
//  Tweeter* pti = static_cast<Tweeter *>(&i);

  Resource r {"Resource"};
  std::string ans;
  std::cin >> ans;
  Tweeter* pt2;
  if (ans == "r") {
    pt2 = dynamic_cast<Tweeter *>(&r); // runtime checking of whether the casting is legal
  } else {
    pt2 = dynamic_cast<Tweeter *>(p);
  }
  if (pt2) {
    cout << pt2->GetName() << endl;
  } else {
    cout << "cant cast to tweeter" << endl;
  }

  return 0;
}


