/*
 * 12.cpp
 *
 *  Created on: 10-Jan-2018
 *      Author: maran
 */

#include <regex>
#include <algorithm>
#include <iterator>
#include <iostream>

int main() {
  std::string const s {"abc abbccc"};
  std::regex const re {"a(b*)(c*)"};
  std::sregex_token_iterator it { std::begin(s), std::end(s), re, {1, 2} };

  std::cout << *it++ << std::endl;
  std::cout << *it++ << std::endl;
  std::cout << *it++ << std::endl;
  std::cout << *it++ << std::endl;
}
