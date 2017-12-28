/*
 * 5.cpp
 *
 *  Created on: 27-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <list>
#include <iterator>

int main() {
  std::list<int> li {1, 2, 3, 4, 5, 6};

  std::copy(std::rbegin(li), std::rend(li), std::ostream_iterator<int>{std::cout, ", "});
  std::cout << '\n';
  std::copy(std::begin(li), std::end(li), std::ostream_iterator<int>{std::cout, ", "});
  std::cout << '\n';
  // limitation of the below approach
  // make_reverse_iterator is applicable only
  // if the container provides bidirection iterator (list, set, map
  // and vector, deque (which give random access iterators))
  std::copy(std::make_reverse_iterator(std::end(li)), std::make_reverse_iterator(std::begin(li)),
      std::ostream_iterator<int>{std::cout, ", "});
  std::cout << '\n';
}



