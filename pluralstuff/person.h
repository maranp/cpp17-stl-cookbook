#pragma once

#include <string>
#include "Resource.h"

class Person {
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;
  // to keep things that are optional to the object (Person)
  Resource *pResource;
public:
  Person(std::string first, std::string last, int arbitrary);
  Person(Person const &);
  Person & operator=(Person const &);
  ~Person();
  std::string GetName() const;
  int GetNumber() const;
  void SetNumber(int number) {
    arbitrarynumber = number;
  }
  void SetFirstName(std::string first) {
    firstname = first;
  }
  void AddResource();
};
