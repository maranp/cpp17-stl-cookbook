/*
 * 6.cpp
 *
 *  Created on: 26-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

template <typename InIt, typename OutIt, typename T, typename BinFn>
auto split(InIt it, InIt endit, OutIt outit, T const &val, BinFn fn) {
  while (it != endit) {
    auto foundit {std::find(it, endit, val)};
    *outit++ = fn(it, foundit);
    if (foundit == endit) {
      return endit;
    }
    it = std::next(foundit);
  }
  return it;
}

int main() {
  auto charit_to_string {
    [](auto it, auto endit) {
      return std::string(it, endit);
    }
  };

  std::string input = "aabb"; //"aa-b-c-dd-e-f-gg-h";
  std::list<std::string> output;
  split(std::begin(input), std::end(input), std::back_inserter(output), '-', charit_to_string);

  std::copy(std::begin(output), std::end(output), std::ostream_iterator<std::string>{std::cout, "\n"});
}



