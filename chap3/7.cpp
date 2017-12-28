/*
 * 7.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vi {1, 2, 3, 4}; // , 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
  std::vector<int> vid;
  const auto i {std::begin(vi)};
  std::move(std::begin(vi), std::end(vi), std::back_inserter(vid));
  std::cout << vi.capacity() << vi.size() << " " << &vi << " " << " " << *i << " " << &(*i) << std::endl;
  vi.shrink_to_fit();
  std::cout << vi.capacity() << vi.size() << " " << &vi << " " << " " << *i << " " << &(*i) << std::endl;
}



