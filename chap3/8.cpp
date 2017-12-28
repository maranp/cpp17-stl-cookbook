/*
 * 8.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class zip_iterator {
  using itr_ty = std::vector<int>::iterator;
  itr_ty itr1;
  itr_ty itr2;
public:
  zip_iterator(itr_ty it1, itr_ty it2) : itr1 {it1}, itr2 {it2} {}
  auto operator*() const {
    return std::make_pair(*itr1, *itr2);
  }
  auto & operator++() {
    itr1++;
    itr2++;
    return *this;
  }
  auto operator!=(zip_iterator const & o) const {
    // if one of itr1 or itr2 is equal, return false. (!= is not true)
    return itr1 != o.itr1 && itr2 != o.itr2;
  }
  auto operator==(zip_iterator const & o) const {
    return !(*this != o);
  }
};

namespace std {
template<>
struct iterator_traits<zip_iterator> {
  using iterator_category = std::forward_iterator_tag;
};
}
class zip_range {
  using cont_ty = std::vector<int>;
  cont_ty & vec1;
  cont_ty & vec2;
public:
  zip_range(cont_ty &vec1_, cont_ty &vec2_) : vec1{vec1_}, vec2{vec2_} {}
  zip_iterator begin() const {
    return zip_iterator {std::begin(vec1), std::begin(vec2)};
  }
  zip_iterator end() const {
    return zip_iterator {std::end(vec1), std::end(vec2)};
  }
};

int main() {
  std::vector<int> vi1 {1, 2, 3};
  std::vector<int> vi2 {1, 2, 3};
  auto result {
    std::inner_product(vi1.begin(), vi1.end(), vi2.begin(), 0,
      [](auto const sum, auto const val) {
        return sum + val;
      },
      [](auto const e1, auto const e2) {
        return e1 * e2;
      })
  };
  std::cout << result << '\n';

  for (auto p : zip_range {vi1, vi2}) {
    std::cout << p.first << ", " << p.second << '\n';
  }

  auto zipped {zip_range (vi1, vi2)};
  std::cout
  <<
  std::accumulate(std::begin(zipped), std::end(zipped), 0, [](auto accum, std::pair<int, int> p) {
    return accum + p.first * p.second;
  })
  << std::endl;
}



