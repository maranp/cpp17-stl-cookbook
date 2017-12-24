/*
 * 5.cpp
 *
 *  Created on: 18-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8};
  std::transform(std::begin(vi), std::end(vi),
      std::ostream_iterator<int> {std::cout, ", "},
      [](auto i) {
        return i * i;
      });
  std::cout << std::endl;

  std::vector<std::string> vs;
  std::transform(std::begin(vi), std::end(vi),
      std::back_inserter(vs),
      [](auto i) {
        std::stringstream ss;
        ss << i << " ^ 2 = " << i * i;
        return ss.str();
      });
  std::copy(std::begin(vs), std::end(vs),
        std::ostream_iterator<std::string> {std::cout, "\n"});

  return 0;
}



