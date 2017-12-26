/*
 * 8.cpp
 *
 *  Created on: 26-Dec-2017
 *      Author: maran
 */
#include <algorithm>
#include <iostream>
#include <string>

// returns the new end iterator
template <typename It>
auto remove_multi_whitespace(It it, It endit) {
  return std::unique(it, endit, [](auto const &a, auto const &b) {
    return std::isspace(a) && std::isspace(b);
  });
}

int main() {
  std::string s = "a    b   \t c";
  s.erase(remove_multi_whitespace(std::begin(s), std::end(s)), std::end(s));
  std::cout << s << '\n';
}



