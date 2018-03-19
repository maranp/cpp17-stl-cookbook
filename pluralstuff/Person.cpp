/*
 * Person.cpp
 *
 *  Created on: 19-Mar-2018
 *      Author: maran
 */

#include "person.h"

Person::Person(std::string first, std::string last, int arbitrary)
  : firstname {first}, lastname {last}, arbitrarynumber {arbitrary},
    pResource {nullptr} {}

Person::Person(Person const &p) {
  pResource = new Resource {p.pResource->GetName()};
}
Person & Person::operator=(Person const & p) {
  // this code will bomb if p is same as this ( p = p; )
  delete pResource;
  pResource = new Resource {p.pResource->GetName()};
  return *this;
}

Person::~Person() {
  delete pResource;
}

std::string Person::GetName() const {
  return firstname + " " + lastname;
}

int Person::GetNumber() const {
  return arbitrarynumber;
}

void Person::AddResource() {
  // pResource might be NULL. But passing nullptr to delete is harmless.
  delete pResource;
  pResource = new Resource {"Resource for " + GetName()};
}
