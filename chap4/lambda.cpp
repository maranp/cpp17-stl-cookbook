/*
 * lambda.cpp
 *
 *  Created on: 25-Nov-2017
 *      Author: maran
 */

#include <iostream>
#include <functional>

int main() {
  struct name_greeter {
    std::string name;
    name_greeter(std::string str) : name {str} {}
    std::string operator()() {
      return "hello " + name;
    }
  };

  name_greeter greet_maran("maran");
  std::cout << greet_maran() << std::endl;

  auto l_greet_maran = []() {
    std::cout << "hello maran" << std::endl;
  };
  l_greet_maran();

  auto l_greet_person = [](std::string const &str) {
    std::cout << "hello " + str << std::endl;
  };
  l_greet_person("maran");

  std::string person = "captured maran";
  auto l_greet_captured_person = [=]() {
    std::cout << "hello " + person << std::endl;
  };
  l_greet_captured_person();
}



