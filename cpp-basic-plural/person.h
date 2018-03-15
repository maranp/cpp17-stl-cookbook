/*
 * person.h
 *
 *  Created on: 15-Mar-2018
 *      Author: maran
 */

#ifndef CPP_BASIC_PLURAL_PERSON_H_
#define CPP_BASIC_PLURAL_PERSON_H_

#include <string>

class Person {
private:
  std::string firstname;
  std::string lastname;
  int age;
public:
  Person(std::string _first, std::string _last, int _age);
  int get_age() const;
};



#endif /* CPP_BASIC_PLURAL_PERSON_H_ */
