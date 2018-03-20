#pragma once

#include <iostream>

class Resource {
private:
  std::string name;
public:
  Resource(std::string _name) : name { _name } {
    std::cout << "constructing " << name << std::endl;
  }
  virtual ~Resource() {
    std::cout << "destructing " << name << std::endl;
  }
  virtual std::string GetName() const {
    return name;
  }
};
