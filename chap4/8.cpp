/*
 * 8.cpp
 *
 *  Created on: 15-Dec-2017
 *      Author: maran
 */

#include <iostream>

static void print(int x, int y) {
  std::cout << "(" << x << ", " << y << ")" << std::endl;
}



int main() {
  // cart_row is a function object that
  // calls f with x and each of rest (rest is the cartesion set
  // for which we need the product
  constexpr auto cart_row([=](auto f, auto x, auto... rest) constexpr {
    (void) std::initializer_list<int> {
      ((x < rest) // discard (2, 2), (3, 2) type pairs
          ? (void)f(x, rest)
          : (void) 0
       , 0)...
    };
  });

  constexpr auto cartesian([=](auto... xs) constexpr {
    return [=](auto f) constexpr {
      (void) std::initializer_list<int> {
        ((void)cart_row(f, xs, xs...), 0)...
      };
    };
  });

  // cartesian is a function object which returns
  // a function object that captures the set passed to cartesian
  // and calls cart_row with the function passed to it and the set
  constexpr auto print_cart(cartesian(1, 2, 3));
  print_cart(print);

  return 0;
}
