/*
 * 9.cpp
 *
 *  Created on: 29-Dec-2017
 *      Author: maran
 */

#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <iostream>

std::string word_from_num(int i) {
  static std::unordered_map<int, std::string> const umis {
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
  };
  auto foundit {umis.find(i)};
  if (foundit == std::end(umis)) {
    return "unknown";
  }
  return (*foundit).second;
}

struct bork {
  int n;
  /* explicit wont work */ bork(int n_) : n {n_} {}
  void print(std::ostream &os) const {
    for (auto i = 0; i < n; i++) {
      os << "bork ";
    }
    os << '\n';
  }
};

auto & operator<<(std::ostream &os, struct bork const &b) {
  b.print(os);
  return os;
}

int main() {
  std::cout << word_from_num(4) << '\n';

  std::vector<int> vi {1, 2, 3, 4, 5, 6};
  std::ostream_iterator<int> oit {std::cout};

  for (auto e : vi) {
    *oit = e;
    // note that oit++ is not required. probably its taken care internally
  }
  std::cout << '\n';

  oit = std::ostream_iterator<int> {std::cout, ", "};
  for (auto e : vi) {
    *oit = e;
  }
  std::cout << '\n';

  std::copy(std::begin(vi), std::end(vi), std::ostream_iterator<int>{std::cout});
  std::cout << '\n';

  std::copy(std::begin(vi), std::end(vi), std::ostream_iterator<int>{std::cout, ", "});
  std::cout << '\n';

  std::transform(std::begin(vi), std::end(vi),
      std::ostream_iterator<std::string>{std::cout, " "},
      word_from_num);

  std::copy(std::begin(vi), std::end(vi), std::ostream_iterator<bork>{std::cout});
//  {
//    for (e in vi) {
//      *cout_itr<bork> = e
//      =>
//      bork b = e; // operator=(bork b) is called with e as parameter.
                    // so, bork constructor should be non-explicit for this to work
//      operator<<(cout, b);
//    }
//  }

}



