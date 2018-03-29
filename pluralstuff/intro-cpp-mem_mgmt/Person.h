#pragma once

#include <string>
#include <memory>
#include "Resource.h"

class Person {
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;
  // if Person object can be copied keeping the resource common for all the copied Persons
  // use shared_ptr
  // std::shared_ptr<Resource> pResource;
  Resource pResource;

public:
  Person(std::string first, std::string last, int arbitrary);
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
    Resource newres {resource_name};
    pResource = newres;
  }
  std::string GetResourceName() const {
    //return pResource ? pResource->GetName() : "";
    return pResource.GetName();
  }
};
