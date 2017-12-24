/*
 * 7.cpp
 *
 *  Created on: 24-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

auto norm_builder(int min, int max, int new_max) {
  double diff = max - min;
  return [=](int i) {
    return int((i - min) / diff * new_max);
  };
}

// clamps is from c++17 but the compiler doesn ot support it yet
//auto clamp_builder(int min, int max) {
//  return [=](int i) -> int {
//    return std::clamp(i, min, max);
//  };
//}

int main() {
  std::vector<int> vi {0, 1000, 5, 250, 300, 800, 900, 321};
  std::copy(std::begin(vi), std::end(vi), std::ostream_iterator<int>{std::cout, ", "});
  std::cout << std::endl;

  std::vector<int> normed_vi;
  normed_vi.reserve(vi.size());

  auto const min_max_it_p = std::minmax_element(std::begin(vi), std::end(vi));
  std::transform(std::begin(vi), std::end(vi), std::back_inserter(normed_vi),
      norm_builder(*min_max_it_p.first, *min_max_it_p.second, 255));

  std::copy(std::begin(normed_vi), std::end(normed_vi), std::ostream_iterator<int>{std::cout, ", "});
  std::cout << std::endl;

// clamps is from c++17 but the compiler doesn ot support it yet
//  std::transform(std::begin(vi), std::end(vi), std::begin(normed_vi),
//      clamp_builder(0, 255));
//
//  std::copy(std::begin(normed_vi), std::end(normed_vi), std::ostream_iterator<int>{std::cout, ", "});
//  std::cout << std::endl;

}



