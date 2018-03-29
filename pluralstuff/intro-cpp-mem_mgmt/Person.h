#pragma once

#include <string>
#include <memory>
#include "Resource.h"

class Person {
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;
  // shared_ptr is copyable. so this class need not manage copy const, assign
  std::shared_ptr<Resource> pResource;

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
    pResource = std::make_shared<Resource>(resource_name);
  }
  std::string GetResourceName() const {
    //return pResource ? pResource->GetName() : "";
    return pResource->GetName();
  }
};
