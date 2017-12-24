/*
 * 6.cpp
 *
 *  Created on: 18-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <vector>
#include <algorithm>

struct city {
  std::string name;
  unsigned population;
};

bool operator==(city const & lhs, city const & rhs) {
  return lhs.name == rhs.name && lhs.population == rhs.population;
}

std::ostream& operator<<(std::ostream &o, city const & c) {
  return o << "{" << c.name << ", " << c.population << "}";
}

template <typename ContainerT>
auto get_iterator_printer(ContainerT const & c) {
  return [endit {std::end(c)}](auto const & it) {
    if (it == endit)
      std::cout << "end" << std::endl;
    else
      std::cout << *it << std::endl;
  };
}

int main() {
  std::vector<city> vc { {"aa", 1}, {"bb", 2}, {"cc", 3} };

  auto print_city {get_iterator_printer(vc)};
  // find uses the operator== for its search operation
  auto search_it { std::find(std::begin(vc), std::end(vc), city {"aa", 1}) };
  //auto search_it { std::find(std::begin(vc), std::end(vc), vc[0]) };
  print_city(search_it);

  // find_if uses the predicate passed instead of the operator==
  // of the element type of the container
  search_it = std::find_if(std::begin(vc), std::end(vc), [](city const &c) {
    return c.name == "bb";
  });
  print_city(search_it);

  search_it = std::find_if(std::begin(vc), std::end(vc), [](city const &c) {
    return c.population > 2;
  });
  print_city(search_it);

  // a sleek approach to send the predicate to the find_if or any other
  // predicate taking algorithm
  auto population_more_than { [](unsigned i) {
    return [i](city const & c) {
      return c.population > i;
    };
  } };

  search_it = std::find_if(std::begin(vc), std::end(vc), population_more_than(1));
  print_city(search_it);

  // binary search
  const std::vector<int> vi {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto print_vi_iterator { get_iterator_printer(vi) };
  // note that binary search only returns a bool indicating if the item is found
  // to get the iterator to the first item found, use lower_bound algoritm
  // and handle the cases that lower_bound leave us with.
  auto contains_7 {std::binary_search(std::begin(vi), std::end(vi), 7)};
  std::cout << std::boolalpha << contains_7 << std::endl;
  print_vi_iterator(std::begin(vi));

  auto const pair (std::equal_range(std::begin(vi), std::end(vi), 7));
  print_vi_iterator(pair.first);
  print_vi_iterator(pair.second);

  print_vi_iterator(std::lower_bound(std::begin(vi), std::end(vi), 7));
  print_vi_iterator(std::upper_bound(std::begin(vi), std::end(vi), 7));

}


