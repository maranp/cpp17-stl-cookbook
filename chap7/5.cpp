/*
 * 5.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

auto word_count(std::istream &is) {
  return std::distance(std::istream_iterator<std::string>{is}, {});
}
int main() {
  std::fstream fs {"5.txt"};
//  std::copy(std::istream_iterator<std::string>{fs}, {}, std::ostream_iterator<std::string>{std::cout, ", "});
//  std::cout << '\n';

  std::copy(std::istream_iterator<std::string>{fs}, {}, std::ostream_iterator<std::string>{std::cout, "-"});
  std::cout << '\n';

  // my recipe to count words in a file
  std::fstream fs1 {"5.txt"};
  std::cout <<
  std::accumulate(std::istream_iterator<std::string>{fs1}, {}, 0,
      [](auto accum, auto) {
        return accum + 1;
  })
  << '\n';

  // book recipe
  fs1 = std::fstream{"5.txt"};
  std::cout << word_count(fs1) << std::endl;
  std::cout << word_count(std::cin) << std::endl;
}



