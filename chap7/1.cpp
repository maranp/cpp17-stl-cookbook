/*
 * 1.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: maran
 */
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>

int main() {
  std::string s1 {"string"};
  auto s2 {"str"};
  std::cout << s1 << s2 << '\n';

  std::ostringstream oss;
  oss << s1 << s2;
  std::cout << oss.str() << '\n';

  std::transform(std::begin(s1), std::end(s1), std::ostream_iterator<char> {std::cout, ""}, ::toupper);
  // std::cout << s1 << s2 << '\n';
}


