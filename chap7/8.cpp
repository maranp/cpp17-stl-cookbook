/*
 * 8.cpp
 *
 *  Created on: 29-Dec-2017
 *      Author: maran
 */

#include <iterator>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

struct meme {
  std::string description;
  size_t year;
};

auto & operator>>(std::istream &is, meme &m) {
  // " asdg asdg asd" . quoted takes everything within quotes
  // when quoted is used with cout, puts the string in quotes
  is >> std::quoted(m.description);
  return is >> m.year;
}

auto & operator>>(std::istream &is, std::pair<std::string, meme> &pm) {
  return is >> std::quoted(pm.first) >> pm.second;
}

int main() {
  std::map<std::string, meme> mememap;
  std::copy(std::istream_iterator<std::pair<std::string, meme>> {std::cin}, {},
      // back_inserted uses push_back internally. but map does not have push_back.
      // std::back_inserter(mememap));
      std::inserter(mememap, std::begin(mememap)));
  for (auto const &p : mememap) {
    std::cout << std::setw(10)
    << p.first << ": " << p.second.description << ", "
    << p.second.year << '\n';
  }

  std::cout <<
      std::accumulate(std::begin(mememap), std::end(mememap), 0ul, [] (auto maxlen, auto const &p) {
        return std::max(maxlen, p.first.length());
      })
  << '\n';
}


