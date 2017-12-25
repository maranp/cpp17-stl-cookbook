/*
 * 2.cpp
 *
 *  Created on: 25-Dec-2017
 *      Author: maran
 */

// copy paste from 1.cpp to use Trie datastructure
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
//#include <optional>
#include <fstream>
#include <sstream>

template <typename T>
class Trie {
  std::map<T, Trie> trimap;

public:
  template <typename Iterator>
  void insert(Iterator const &it, Iterator const &endit) {
    if (it == endit) return;
    trimap[*it].insert(std::next(it), endit);
  }

  // a convenience function
  template <typename ContainerT>
  void insert(ContainerT const &c) {
    insert(std::begin(c), std::end(c));
  }

  // allow user to call insert like, mytrie.insert({"a", "b", "c"})
  // Note: T comes from the Trie class' template parameter
  void insert(std::initializer_list<T> const &list) {
    insert(std::begin(list), std::end(list));
  }

  // Note: T comes from the Trie class' template parameter
  void print(std::vector<T> &v) const {
    if (trimap.empty()) {
      // we reached the leaf of one depth first path.
      // so, print the elements in the path
      std::copy(std::begin(v), std::end(v), std::ostream_iterator<T>{std::cout, ", "});
      std::cout << "\n";
      // return; is implicit as the following for loop
      // is ineffective as trimap is empty
    }
    for (auto const & p : trimap) {
      // add the T to the vector to print.
      v.push_back(p.first);
      p.second.print(v);
      // once printed, remove this T element
      // and add the T of the next map pair in this trimap
      v.pop_back();
    }
  }

  // user will not pass on a vector to print the trie. senseless to him.
  // So, a convenient function to call upper version of print
  void print() const {
    std::vector<T> v;
    print(v);
  }

  template <typename Iterator>
  //std::optional<std::reference_wrapper<const Trie>>
  const Trie // could have returned Trie const & but we instantiate an empty
  // Trie when search sequence is not found. Sending a reference to local instantiated Trie causes warning
  subtrie(Iterator it, Iterator endit) {
    if (it == endit) {
      // we have come all the way from root trie, searching for the sequence and
      // "this" is the subtri we were looking for, as we reached the end of the sequence
      // return it
      // return std::ref(*this);
      return *this;
    }
    auto found {trimap.find(*it)};
    if (found == std::end(trimap)) {
      // If we could not find the subtri correspoding to "it"
      // we dont have a subtri for the prefix sequence.
      // return {};
      return Trie{};
    }
    // found is the iterator to the pair of trimap which matches with "it"
    // now hunt for the next(it) in its trimap
    return found->second.subtrie(std::next(it), endit);
  }

  template <typename ContainerT>
  auto subtrie(ContainerT const &c) {
    return subtrie(std::begin(c), std::end(c));
  }
};

int main() {
  Trie<std::string> trie;

  std::fstream infile {"2_db.txt"};

  for (std::string line; std::getline(infile, line);) {
    std::istringstream iss {line};
    trie.insert(std::istream_iterator<std::string>{iss}, {});
  }
  trie.print();

  std::cout << "enter string to get suggestions:";
  for (std::string line; std::getline(std::cin, line);) {
    std::istringstream iss {line};
    trie.subtrie(std::istream_iterator<std::string> {iss}, {}).print();
    std::cout << "enter string to get suggestions:";
  }
}



