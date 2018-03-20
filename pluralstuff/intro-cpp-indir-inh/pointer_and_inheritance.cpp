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
  Person maran {"Maran", "P", 20};
  Person &rpmaran = maran;
  Person *ppmaran = &maran;

  Tweeter maranp {"Maran", "P", 20, "@pmaran"};

  Person *pptmaran = &maranp;
  Person &rptmaran = maranp;

  Tweeter &rtmaran = maranp;


  cout << rpmaran.GetName() << endl;
  cout << ppmaran->GetName() << endl;
  cout << maranp.GetName() << endl;
  cout << rptmaran.GetName() << endl;
  cout << rtmaran.GetName() << endl;
  cout << pptmaran->GetName() << endl;

//  Person *pptsomeone = new Tweeter {"Someone", "P", 20, "@someone"};;
//  cout << pptsomeone->GetName() << endl;
//  delete pptsomeone;

  shared_ptr<Person> spThirt = make_shared<Tweeter>("Someone", "P", 20, "@someone");
  cout << spThirt->GetName() << endl;

  maran = maranp;
  cout << maran.GetName() << endl; // slicing
  cout << maranp.GetName() << endl;

  cout << dummy(maranp) << endl; // slicing if dummy takes arg by value
  cout << maranp.GetNumber() << endl;

  return 0;
}


