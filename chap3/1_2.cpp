/*
 * 1.cpp
 *
 *  Created on: 27-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <iterator>
#include <algorithm>

class num_iterator {
  int i;
public:
  explicit num_iterator(int pos = 0) : i {pos} {}
  auto & operator++() {
    i++;
    return *this;
  }
  auto operator*() const {
    return i;
  }
  auto operator==(num_iterator const &other) const {
    return i == other.i;
  }
  auto operator!=(num_iterator const &other) const {
    return i != other.i;
  }
};

namespace std {
template <>
struct iterator_traits<num_iterator> {
  using iterator_category = std::forward_iterator_tag;
  using value_type = int;
};
}

class num_range {
  int a;
  int b;
public:
  num_range(int from, int to) : a {from}, b {to} {}
  num_iterator begin() const {
    return num_iterator {a};
  }
  num_iterator end() const {
    return num_iterator {b};
  }
};

int main() {
  auto const num {num_range(2, 5)};
  for (auto const e : num) {
    std::cout << e << std::endl;
  }
  // requires types iteratory_category and value_type be defined for iterator_traits<num_iterator>
  std::copy(std::begin(num), std::end(num), std::ostream_iterator<int> {std::cout, ","});
  std::cout << '\n';
  auto [minit, maxit] { std::minmax_element(std::begin(num), std::end(num)) };
  std::cout << *minit << ", " << *maxit << '\n';
}


