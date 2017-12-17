/*
 * 4.cpp
 *
 *  Created on: 17-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

static void print(std::vector<int> const &v) {
  std::copy(std::begin(v), std::end(v), std::ostream_iterator<int> {std::cout, ", "});
  std::cout << std::endl;
}

int main() {
  std::vector<int> vi {1, 2, 3, 4, 5, 6};
  // removes the element of given value and brings the remaining
  // elements to fill the gap of removed element(s)
  // the tail end of the container is now garbase.
  {
    auto const &new_end {std::remove(std::begin(vi), std::end(vi), 2)};
    vi.erase(new_end, std::end(vi));
    print(vi);
  }
  {
    auto const &new_end {std::remove_if(std::begin(vi), std::end(vi), [](auto const &e) {
      return e % 2 == 0;
    })};
    vi.erase(new_end, std::end(vi));
    print(vi);
  }

  std::replace(std::begin(vi), std::end(vi), 3, 323);
  print(vi);

  vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(vi);

  std::vector<int> v2;
  std::vector<int> v3;

  // remove odd elements before copying to v2 (retain even elements in v2)
  std::remove_copy_if(std::begin(vi), std::end(vi), std::back_inserter(v2),
      [](auto const &e) {
        return e % 2  == 1;
      });
  print(v2);

  // copy only even elements to v3
  std::copy_if(std::begin(vi), std::end(vi), std::back_inserter(v3),
      [](auto const &e) {
        return e % 2  == 0;
      });
  print(v3);

}


