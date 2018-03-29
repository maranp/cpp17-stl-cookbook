#pragma once

#include <iostream>

class Resource {
private:
  std::string name;
public:
  Resource(std::string _name) : name { _name } {
    std::cout << "constructing " << name << std::endl;
  }
  Resource(Resource const & res) : name {res.name} {
    std::cout << "copy constructing " << name << std::endl;
  }
  Resource & operator=(Resource const & res) {
    // clean up "this" object's resources before assinment
    // before cleaning up make sure that this object and
    // to be assigned object (self assignment)  are not the same
    std::cout << "copy assigning " << name << std::endl;
    name = res.name;
    return *this;
  }
  void SetResourceName(std::string res_name) {
    name = res_name;
  }
  ~Resource() {
    std::cout << "destructing " << name << std::endl;
  }
  std::string GetName() const {
    return name;
  }
};
