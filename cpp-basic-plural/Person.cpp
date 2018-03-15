/*
 * Person.cpp
 *
 *  Created on: 15-Mar-2018
 *      Author: maran
 */

#include <person.h>

Person::Person(std::string _first, std::string _last, int _age)
    : firstname {_first}, lastname {_last}, age {_age} {}

int Person::get_age() const {
  return age;
}


