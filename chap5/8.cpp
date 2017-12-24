/*
 * 8.cpp
 *
 *  Created on: 24-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

template <typename Iterator>
auto print_chars(Iterator it, size_t chars) {
  std::copy_n(it, chars, std::ostream_iterator<char>{std::cout});
  std::cout << "\n";
}

int main() {
  std::string lstr = "aslkefh lasgdlkajes kagdklawjk jjsadghfks hagqdha";
  std::string sstr = "klaw";

  auto found_it {std::search(std::begin(lstr), std::end(lstr), std::begin(sstr), std::end(sstr))};

  print_chars(found_it, 4);

//  no support for these searcher objects yet
//  found_it = std::search(std::begin(lstr), std::end(lstr),
//      std::default_searcher(std::begin(sstr), std::end(sstr)));
//
//  found_it = std::search(std::begin(lstr), std::end(lstr),
//      std::boyer_moore_searcher(std::begin(sstr), std::end(sstr)));
//
//  found_it = std::search(std::begin(lstr), std::end(lstr),
//      std::boyer_moore_horspool_searcher(std::begin(sstr), std::end(sstr)));
//
//  print_chars(found_it, 4);

}


