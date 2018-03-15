/*
 * 13.cpp
 *
 *  Created on: 10-Jan-2018
 *      Author: maran
 */

#include <iostream>
#include <iomanip>

struct save_format {
  decltype (std::cout.flags()) f {std::cout.flags()};
  ~save_format() {
    std::cout.flags(f);
  }
};

template <typename T>
struct scientific_type {
  T val;
  explicit scientific_type(T val_) : val {val_} {}
};

template <typename T>
std::ostream& operator<<(std::ostream &os, scientific_type<T> const &w) {
  save_format _;
  os << std::scientific << std::uppercase << std::showpos;
  return os << w.val;
}

int main() {
  {
    // cout's default format is saved.
    // when this entity os out of scope, default format will be active again
    save_format _;
    std::cout << std::hex << std::scientific << std::showbase << std::uppercase;
    std::cout << 0x123abc << '\n';
    std::cout << 0.12334567 << '\n';
  }

  std::cout << 0x123abc << '\n';
  std::cout << 0.12334567 << '\n';

  std::cout << "mixed format: " << 123.0 << " " << scientific_type{123.0} << " " << 123.456 << '\n';
}



