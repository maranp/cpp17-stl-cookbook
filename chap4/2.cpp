/*
 * 2.cpp
 *
 *  Created on: 25-Nov-2017
 *      Author: maran
 */

#include <iostream>
#include <string>

int main() {
  auto one = []() constexpr {return 1;};
  // () is optional but not when constexpr
  // or similar attrs are added
  auto two = []() constexpr {return 2;};

  std::cout << one() + two() << std::endl;

  auto plus = [](auto l, auto r) {
    return l + r;
  };

  std::cout << plus(4, 5) << std::endl;

  std::cout << plus(one(), two()) << std::endl;

  std::cout << plus(std::string("one"), "two") << std::endl;

  // if capture a variable by value
  // and write to it (writing includes calling nonconst members of
  // captured variable), add mutable to lambda.
  // mutable not required if variable is captured by reference.
  auto counter = [count = 0]() mutable {
    return count++;
  };

  for (auto i = 0; i < 5; i++) {
    std::cout << counter() << std::endl;
  }

  auto a = 0;
  auto incrementer = [&a]() {
    a++;
  };

  incrementer();
  incrementer();
  incrementer();
  std::cout << a << std::endl;

  // currying
  // defining a lamba with fewer parameters
  // that inturn "contain" (stores) another lambda
  // which takes more parameters is currying
  auto plus_ten = [=](auto l) {
    return plus(l, 10);
  };

  std::cout << plus_ten(two()) << std::endl;

}
