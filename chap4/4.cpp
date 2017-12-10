/*
 * 4.cpp
 *
 *  Created on: 10-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <functional>

// a function that returns function object aka lambda
template <typename T, typename... Ts>
auto concat(T t, Ts... ts) {
  if constexpr (sizeof...(ts) > 0) {
    // many function objects passed to concat.
    // return the function object that will apply t
    // that takes parameters as the result of
    // applying function objects concat(ts...) on the params
    return [=](auto... params) {
      return t(concat(ts...)(params...));
    };
  } else {
    return t;
  }
}

int main() {
  auto twi = [](auto i) { return 2 * i; };
  auto thri = [](auto i) { return 3 * i; };
  auto expr = concat(twi, thri, std::plus<int>{});

  std::cout << expr(4, 3) << std::endl;
}

