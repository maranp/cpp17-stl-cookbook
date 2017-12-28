/*
 * 4.cpp
 *
 *  Created on: 27-Dec-2017
 *      Author: maran
 */
#include <iostream>

class fibit {
  int idx {0};
  int a {0};
  int b {1};
  explicit fibit(int i = 0) : idx {i}, a {0}, b {1} {}
public:
  friend class fib_range;
  fibit() = default;
  auto operator*() const {
    return a;
  }
  auto & operator++() {
    const auto old_b {b};
    b = a + old_b;
    a = old_b;
    idx++;
    return *this;
  }
  auto operator!=(fibit const &other) const {
    return idx != other.idx;
  }
  auto operator==(fibit const &other) const {
    return ! (*this != other);
  }
};

class fib_range {
  int a;
  int b;
public:
  fib_range(int a_, int b_) : a {a_}, b {b_} {}
  fibit begin() const {
    return fibit {a};
    // fibit {0} is a better approach.
    // any initial value other than 0 does not make much sense as a and b of fibit will
    // not have sensible value for the initialization.
    // also constructing fib_range withsingle parameter is more sensible as the initial value is
    // anyway 0, with the mentioned logic. for exact implementation refer to the book.
  }
  fibit end() const {
    return fibit {b};
  }
};

int main() {
  for (auto e : fib_range {0, 10}) {
    std::cout << e << '\n';
  }
}
