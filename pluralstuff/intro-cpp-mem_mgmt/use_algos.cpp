/*
 * use_algos.cpp
 *
 *  Created on: 04-Apr-2018
 *      Author: maran
 */

#include "Resource.h"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>

template <typename C>
void cprint(C const & c) {
  std::for_each(begin(c), end(c), [](auto const & e) {
    cout << e << " ";
  });
  cout << '\n';
}

int main() {
  vector<int> v;
  std::generate_n(std::back_inserter(v), 5, [i = 0]() mutable {
    return i++;
  });
  cprint(v);
}
