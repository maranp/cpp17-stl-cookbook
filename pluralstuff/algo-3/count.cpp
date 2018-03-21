/*
 * count.cpp
 *
 *  Created on: 20-Mar-2018
 *      Author: maran
 */


#include <algorithm>
#include <iostream>
#include <map>

int main() {
  std::vector<int> v { -1, 0, 1, 3, 5, 2, 7, 2, 8, 2};
  int const key = 2;
  std::cout << std::count(std::begin(v), std::end(v), key) << std::endl;
  std::cout << std::count_if(std::begin(v), std::end(v), [](auto const & e) {
    return (e & 1) && 1;
  }) << std::endl;

  std::map<int, int> month_lenghts { {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31},
    {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

  std::cout <<
      std::count_if(std::begin(month_lenghts), std::end(month_lenghts), [](auto const & e) {
    return (e.second == 31);
  })
  << std::endl;

  std::cout << std::boolalpha
      << std::none_of(std::begin(month_lenghts), std::end(month_lenghts), [](auto const & e) {
    return (e.second == 31);
  })
  << std::endl;

}

