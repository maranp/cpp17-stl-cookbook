/*
 * ctocpp.cpp
 *
 *  Created on: 10-Apr-2018
 *      Author: maran
 */
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>

int main() {
  vector<string> v {"1", "2", "3", "4", "5"};
  auto allofv = std::accumulate(std::next(begin(v)), end(v), v[0], [](auto const &accum, auto const &e) {
    return accum + " " + e;
  });
  cout << allofv << endl;
}



