/*
 * 2.cpp
 *
 *  Created on: 16-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>

namespace std {
std::ostream& operator<<(std::ostream &o, std::pair<int, std::string> pis) {
  return o << pis.first << " " << pis.second;
}
}

int main() {
  std::vector<std::pair<int, std::string>> vis {
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
  };

  std::map<int, std::string> mis;

  std::copy_n(std::begin(vis), 3, std::inserter(mis, std::begin(mis)));

  auto oit {std::ostream_iterator<std::pair<int, std::string>> {std::cout, ","}};
  // each element of the vector vis is a pair of int and string.
  // copying vis to oit seem to internaly invoke *oit << pair<int, string>
  // so, overloading << with ostream and pair<int, string> is required.
  std::copy(std::begin(vis), std::end(vis), oit);
  std::cout << std::endl;

  // elements of mis is is also a pair<int, string> and see the explanation above
  std::copy(std::begin(mis), std::end(mis), oit);
  std::cout << std::endl;

  mis.clear();

  std::move(std::begin(vis), std::end(vis), std::inserter(mis, std::begin(mis)));
  // once moved, we are not supposed to access the moved elements.
  // But, just for illustration. Here, int is copied to the destination(mis),
  // but string is efficiently moved to the destination.
  std::copy(std::begin(vis), std::end(vis), oit);
  std::cout << std::endl;
  //std::cout << pis << std::endl;
}



