/*
 * 11.cpp
 *
 *  Created on: 24-Dec-2017
 *      Author: maran
 */

#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <deque>

using dict_entry = std::pair<std::string, std::string>;

// enable standard input/output to work with dict_entry type
namespace std {
ostream& operator<<(ostream &os, dict_entry entry) {
  return os << entry.first << ", " << entry.second;
}

istream& operator>>(istream &is, dict_entry &entry) {
  return is >> entry.first >> entry.second;
}
}

template <typename IS>
// in cannot be passed by value, as copy of istream(cin) is prohibited
// &in works. but book recommends &&in as ifstream comes as rvalue reference
// due to construction in the place of call to this function
auto sorted_dq_from_stream(IS &&in) {
  // interpret the data from the stream as stream of dict_entry entries
  std::deque<dict_entry> dq {std::istream_iterator<dict_entry> {in}, {}};
  std::sort(std::begin(dq), std::end(dq));

  // copying dq back to the caller. there must be a better approach
  return dq;
}

int main() {
  auto dict1 {sorted_dq_from_stream(std::cin)};
  // dict.txt must present in the folder from where the application is called
  auto dict2 {sorted_dq_from_stream(std::ifstream{"dict.txt"})};
  std::copy(std::begin(dict1), std::end(dict1), std::ostream_iterator<dict_entry> {std::cout, "\n"});
  std::copy(std::begin(dict2), std::end(dict2), std::ostream_iterator<dict_entry> {std::cout, "\n"});
  std::merge(std::begin(dict1), std::end(dict1), std::begin(dict2), std::end(dict2),
      std::ostream_iterator<dict_entry> {std::cout, "\n"});
}



