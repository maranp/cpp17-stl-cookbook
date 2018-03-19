/*
 * memory.cpp
 *
 *  Created on: 19-Mar-2018
 *      Author: maran
 */

#include <iostream>
#include "Person.h"
#include "Tweeter.h"

auto dummy(Person p) {

}

int main() {
  Person maran {"Maran", "P", 20};
  Person &rpmaran = maran;
  Person *ppmaran = &maran;

  Tweeter maranp {"Maran", "P", 20, "@pmaran"};

  Person *pptmaran = &maranp;
  Person &rptmaran = maranp;

  Tweeter &rtmaran = maranp;

  using std::cout;
  using std::endl;

  cout << rpmaran.GetName() << endl;
  cout << ppmaran->GetName() << endl;
  cout << maranp.GetName() << endl;
  cout << rptmaran.GetName() << endl;
  cout << rtmaran.GetName() << endl;
  cout << pptmaran->GetName() << endl;

  Person *pptsomeone = new Tweeter {"Someone", "P", 20, "@someone"};;
  cout << pptsomeone->GetName() << endl;
  delete pptsomeone;

  return 0;
}


