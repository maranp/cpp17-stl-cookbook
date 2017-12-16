/*
 * 1.cpp
 *
 *  Created on: 16-Dec-2017
 *      Author: maran
 */
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  std::vector<int> vi {100, 200, 300};

  auto sum {0};
  for (auto e : vi) {
    sum += e;
  }
  std::cout << sum << std::endl;

  auto reduce_fn(
      [](auto accum, auto input) {
        return accum + 2 * input;
      }
      );
  std::cout << std::accumulate(std::begin(vi), std::end(vi), 0, reduce_fn) << std::endl;

  return 0;
}



