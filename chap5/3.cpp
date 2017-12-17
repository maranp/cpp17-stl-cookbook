/*
 * 3.cpp
 *
 *  Created on: 17-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

static void print(std::vector<int> const &v) {
  std::copy(std::begin(v), std::end(v), std::ostream_iterator<int> {std::cout, ", "});
  std::cout << std::endl;
}

struct mystruct {
  int a;
  int b;
};

namespace std {
std::ostream & operator<<(std::ostream & o, mystruct ms) {
  return o << "(" << ms.a << " " << ms.b << ")";
}
}

int main() {
  std::vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(vi);

  std::random_device rd;
  std::mt19937 g (rd());

  std::cout << std::boolalpha;
  std::cout << std::is_sorted(std::begin(vi), std::end(vi)) << std::endl;

  std::shuffle(std::begin(vi), std::end(vi), g);
  print(vi);
  std::cout << std::is_sorted(std::begin(vi), std::end(vi)) << std::endl;

  std::sort(std::begin(vi), std::end(vi));
  print(vi);
  std::cout << std::is_sorted(std::begin(vi), std::end(vi)) << std::endl;

  std::shuffle(std::begin(vi), std::end(vi), g);
  print(vi);

  std::partition(std::begin(vi), std::end(vi), [](int e) {
    return e < 5;
  });
  // the output is not expected
  print(vi);

  std::shuffle(std::begin(vi), std::end(vi), g);
  print(vi);
  std::partial_sort(std::begin(vi), std::next(std::begin(vi), vi.size() / 2), std::end(vi));
  print(vi);

  std::vector<mystruct> vms { {5, 10}, {-4, -19}, {3, 33}, {6, 2} };

  std::sort(std::begin(vms), std::end(vms), [](auto const &lhs, auto const &rhs) {
    return lhs.b < rhs.b;
  });

  std::copy(std::begin(vms), std::end(vms), std::ostream_iterator<mystruct>{std::cout, ", "});
  std::cout << "\n";

  // Alternative printing
//  for (auto const & [a, b] : vms) {
//    std::cout << "(" << a << ", " << b << "), ";
//  }
//  std::cout << "\n";

}
