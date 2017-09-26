/*
 * iterator_adaptor.cpp
 *
 *  Created on: 26-Sep-2017
 *      Author: maran
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <deque>

int main() {
  // input stream from input device
  // cin is istream
  std::istream_iterator<int> it_int_cin {std::cin};
  std::istream_iterator<int> it_int_end;

  std::deque<int> dqi;


  // ctrl+d to mark end of input
  std::copy(it_int_cin, it_int_end, std::back_inserter(dqi));

  // input stream from input string stream
  std::istringstream iss {"234 432 676"};
  auto dq_middle {std::next(std::begin(dqi), dqi.size() / 2)};

  // add to deque at the middle
  std::copy(std::istream_iterator<int> {iss}, {}, std::inserter(dqi, dq_middle));

  std::initializer_list<int> il {-2, 5, 23, -9};
  std::copy(std::begin(il), std::end(il), std::front_inserter(dqi));

  std::copy(std::begin(dqi), std::end(dqi),
      std::ostream_iterator<int>{std::cout, ","});
//  for (auto const & e : dqi) {
//    std::cout << e << std::endl;
//  }
}


