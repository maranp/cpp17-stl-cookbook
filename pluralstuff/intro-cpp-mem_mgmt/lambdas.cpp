/*
 * lambdas.cpp
 *
 *  Created on: 30-Mar-2018
 *      Author: maran
 */

#include <vector>
#include <algorithm>
#include <iostream>


int main() {
  std::vector<int> v {1, 2, 3, 4, 5};
  auto x = 0;
  auto y = 0;

  auto print = [&]() {
    std::cout << x << " " << y << '\n';
  };
  print();

  std::for_each(begin(v), end(v), [&x, &y](auto e) mutable {
    x += e;
    y += e;
  });

  print();

  std::vector<int> doubleV; //(v.size());
  doubleV.reserve(v.size()); // no functional effect. just reserves space but the size of the vector is still zero
                             // still back_inserter needs to be used
  std::transform(begin(v),end(v), std::back_inserter(doubleV), [](auto e) {
    return 2 * e;
  });
  x = doubleV[0];
  y = doubleV[1];
  print();

  std::for_each(begin(doubleV), end(doubleV), [](auto e) {
    e++;
  });
  x = doubleV[0];
  y = doubleV[1];
  print();

  std::for_each(begin(doubleV), end(doubleV), [](auto & e) {
    e++;
  });
  x = doubleV[0];
  y = doubleV[1];
  print();

  return 42;
}
