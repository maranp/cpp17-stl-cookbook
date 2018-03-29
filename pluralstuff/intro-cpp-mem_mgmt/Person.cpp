/*
 * Person.cpp
 *
 *  Created on: 19-Mar-2018
 *      Author: maran
 */

#include "Person.h"

Person::Person(std::string first, std::string last, int arbitrary)
  : firstname {first}, lastname {last}, arbitrarynumber {arbitrary} {}

//Person::Person(Person const &p)
//: firstname {p.firstname}, lastname {p.lastname}, arbitrarynumber {p.arbitrarynumber} {
//  pResource.reset(new Resource{p.GetResourceName()});
//}
//
//Person & Person::operator=(Person const &p) {
//  firstname = p.firstname;
//  lastname  = p.lastname;
//  arbitrarynumber = p.arbitrarynumber;
//  pResource.reset(new Resource{p.GetResourceName()});
//  return *this;
//}

std::string Person::GetName() const {
  return firstname + " " + lastname;
}

int Person::GetNumber() const {
  return arbitrarynumber;
}

void Person::AddResource() {
  //pResource.reset();
  //pResource = std::make_shared<Resource>("Resource for " + GetName());
}
