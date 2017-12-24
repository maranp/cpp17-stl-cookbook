/*
 * 10.cpp
 *
 *  Created on: 24-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
  std::vector<std::string> vs {std::istream_iterator<std::string> {std::cin}, {}};
  // if not sorted, if the input sequence is last in permutation,
  // only one permutation will be printed
  std::sort(std::begin(vs), std::end(vs));
  std::copy(std::begin(vs), std::end(vs), std::ostream_iterator<std::string> {std::cout, ", "});
  std::cout << "\n";

  while (std::next_permutation(std::begin(vs), std::end(vs))) {
    std::copy(std::begin(vs), std::end(vs), std::ostream_iterator<std::string> {std::cout, ", "});
    std::cout << "\n";
  }
}



