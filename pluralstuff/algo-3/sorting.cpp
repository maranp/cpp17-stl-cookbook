/*
 * sorting.cpp
 *
 *  Created on: 22-Mar-2018
 *      Author: maran
 */
#include <vector>
#include <algorithm>
#include "Employee.h"

#include <iostream>
using std::cout;
using std::endl;


int main() {
  std::vector<Employee> staff{
    { "Kate", "Gregory", 1000 },
    { "Obvious", "Artificial", 2000 },
    { "Fake", "Name", 1000 },
    { "Alan", "Turing", 2000 },
    { "Grace", "Hopper", 2000 },
    { "Anita", "Borg", 2000 }
  };

  auto s1 = staff;

  std::sort(std::begin(s1), std::end(s1),
      [](Employee const & e1, Employee const & e2) {
    return e1.getSortingName() < e2.getSortingName();
  });

  for (auto const & e : s1) {
    std::cout << e.getSortingName() << " " << e.getSalary() <<  std::endl;
  }

  cout << "====================================" << endl;

  std::stable_sort(std::begin(s1), std::end(s1),
      [](Employee const & e1, Employee const & e2) {
    return e1.getSalary() < e2.getSalary();
  });

  for (auto const & e : s1) {
    std::cout << e.getSortingName() << " " << e.getSalary() <<  std::endl;
  }

//  std::random_device rd;
  std::mt19937 generator {std::random_device{}()};

  std::vector<int> v {1, 2, 3, 4, 5, 0, 0, 10};
  std::shuffle(std::begin(v), std::end(v), generator);

  for (auto const & e : v) {
    std::cout << e <<  std::endl;
  }
}
