/*
 * num_range.cpp
 *
 *  Created on: 25-Sep-2017
 *      Author: maran
 */

#include <iostream>
#include <algorithm>

class num_iterator {
public:
  // explicit to avoid implicit conversion
  // set default value to allow default constructible iterator
  // stl algos often require default constructible iterator
  explicit num_iterator(int pos = 0) : i {pos} {}

  // following 4 operators
  // *, ++, ==, != are essential iterator operators
  int operator*() const {
    return i;
  }

  // prefix increment operator
  // it does not provide support for postfix increment operator
  auto & operator++() {
    i++;
    return *this;
  }

  bool operator==(num_iterator const & other) const {
    return i == other.i;
  }
  bool operator!=(num_iterator const & other) const {
    return !(*this == other);
  }
private:
  int i;
};

namespace std {
template<>
struct iterator_traits<num_iterator> {
  using iterator_category = std::forward_iterator_tag;
  using value_type = int;
};
}

class num_range {
public:
  num_range(int begin, int end) : begin_ {begin}, end_ {end} {}
  auto begin() const {
    return begin_;
  }

  auto end() const {
    return end_;
  }

private:
  num_iterator begin_;
  num_iterator end_;
};

int main() {
  for (auto i : num_range(3, 8)) {
    std::cout << i << std::endl;
  }

  auto range = num_range(5, 15);
  for (auto i = range.begin(); i != range.end(); ++i) {
    std::cout << *i << std::endl;
  }

  auto [minit, maxit] (std::minmax_element(std::begin(range), std::end(range)));
  std::cout << "min: " << *minit << ", max: " << *maxit << std::endl;

}
