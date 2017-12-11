/*
 * 5.cpp
 *
 *  Created on: 10-Dec-2017
 *      Author: maran
 */

#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>

static bool a_prefixed(std::string const &s) {
  return s.find("a") == 0;
}

static bool b_suffixed(std::string const &s) {
  return s.rfind("b") == s.length() - 1;
}

// based on foundation described in 4.cpp
// we want a function object that consumes a parameter but
// uses many functions to process and return the value
// this req. is best dealt by a factory function.
// the factory function takes the functions involved (used in the fn. object)
// creates the fn. object with those functions but takes the original
// parameter the user will provide to it
template <typename P1, typename P2, typename BinF>
auto combine(BinF fn, P1 p1, P2 p2) {
  return [=](auto param) {
    return fn(p1(param), p2(param));
  };
}

int main() {
  auto a_and_b(combine(std::logical_and<>{}, a_prefixed, b_suffixed));

  std::copy_if(std::istream_iterator<std::string>{std::cin}, {},
      std::ostream_iterator<std::string>{std::cout, ","}, a_and_b);
  return 0;
}
