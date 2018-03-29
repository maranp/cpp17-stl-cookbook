#pragma once

#include <string>
#include <memory>
#include "Resource.h"

class Person {
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;
  // unique_ptr is non copiable.
  // the copy constructor of this class becomes implicitly deleted with any non copyable member
  // and hence becomes non-copyable
  // so to make the class copyiable, write explicit copy contructor and copy-assign memebers
  // handling the non-copyable member correctly
  std::unique_ptr<Resource> pResource;

public:
  Person(std::string first, std::string last, int arbitrary);
  Person(Person const &);
  Person & operator=(Person const &);

  std::string GetName() const;
  int GetNumber() const;
  void SetNumber(int number) {
    arbitrarynumber = number;
  }
  void SetFirstName(std::string first) {
    firstname = first;
  }
  void AddResource();
  void SetResourceName(std::string resource_name) {
    pResource.reset(new Resource{resource_name});
  }
  std::string GetResourceName() const {
    //return pResource ? pResource->GetName() : "";
    return pResource->GetName();
  }
};
