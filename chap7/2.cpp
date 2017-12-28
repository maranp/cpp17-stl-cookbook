/*
 * 2.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

std::string string_trim_space(std::string const str) {
  std::string whitespace = " \t\n";
  auto first {
    str.find_first_not_of(whitespace)
  };
  if (first == std::string::npos) {
    return {};
  }
  auto last {
    str.find_last_not_of(whitespace)
  };
  return str.substr(first, last - first + 1);
}

int main() {
  std::string s1 {"  abcd  "};
  std::string s2 {"  1234  "};

  std::cout << s1 << s2 << '\n';
  // my recipe
  std::copy_if(std::begin(s1), std::end(s1),
      std::ostream_iterator<char>{std::cout, ""},
      [](char c) {
        return !std::isspace(c);
      });
  std::cout << s2 << '\n';
  std::cout << s1 << s2 << '\n';
  std::string res;
  std::copy_if(std::begin(s1), std::end(s1),
      std::back_inserter(res),
      [](char c) {
        return !std::isspace(c);
      });
  std::cout << res << s2 << '\n';

  // book recipe
  std::string s {" \n\t str with"
    " whitespace \n\t"};
  std::cout << "{" << s << "}\n" << "{" << string_trim_space(s) << "}\n";
}



