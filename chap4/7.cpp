/*
 * 7.cpp
 *
 *  Created on: 12-Dec-2017
 *      Author: maran
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

template <typename P>
auto filter(P predicate) {
  return [=](auto reduce_fn) {
    return [=](auto accum, auto input) {
      if (predicate(input)) {
        return reduce_fn(accum, input);
      } else {
        return accum;
      }
    };
  };
}

template <typename F>
auto map(F fn) {
  return [=](auto reduce_fn) {
    return [=](auto accum, auto input) {
      return reduce_fn(accum, fn(input));
    };
  };
}

int main() {
  auto even {
    [](auto i) {
      return (i % 2) == 0;
    }
  };

  auto twice {
    [](auto i) {
      return 2 * i;
    }
  };

  auto copy_and_advance {
    [](auto it, auto input) {
      *it = input;
      return ++it;
    }
  };

  std::accumulate(std::istream_iterator<int>{std::cin},
      std::istream_iterator<int>{},
      std::ostream_iterator<int>{std::cout, ", "},
      filter(even)
        (map(twice)
             (copy_and_advance)));
}
