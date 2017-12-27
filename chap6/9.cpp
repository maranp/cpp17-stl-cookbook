/*
 * 9.cpp
 *
 *  Created on: 26-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <tuple>

template <typename It>
std::tuple<It, char, size_t>
occurences(It it, It endit) {
  if (it == endit) {
    std::make_tuple(it, '?', 0);
  }
  char const c {*it};
  auto upto {std::find_if(it, endit, [c](auto a) {
    return a != c;
  })
  };
  return std::make_tuple(upto, *it, std::distance(it, upto));
  // not working with c++17 or c++1z
  //return {upto, *it, std::distance(it, upto)};
}

std::string compress(std::string const &s) {
  auto it = std::begin(s);
  auto const endit = std::end(s);
  std::stringstream ss;
  while (it != endit) {
//    auto const tup = occurences(it, endit);
//    ss << std::get<1>(tup) <<std::get<2>(tup);
    //it = std::get<0>(tup);

    // didnt work with -std=c++17, then changer compiler flag to -std=c++1z. It compiled.
    // but, switching config to -std=c++17, doesn't complain anymore ??!!!
    auto [itr, cc , llen] ( occurences(it, endit) );
    ss << cc << llen;
    it = itr;

  }
  return ss.str();
}

std::string decompress(std::string const &s) {
  //std::string res;
  std::stringstream rs;
  std::stringstream ss {s};
  size_t n;
  char c;
  while (ss >> c >> n) {
    rs << std::string(n, c);
    //res += std::string(n, c);
  }
  //return res;
  return rs.str();
}

int main() {
  std::string s = "aaaaddddddff";
  std::cout << compress(s) << '\n';
  std::cout << decompress(compress(s)) << '\n';
}

