/*
 * 6.cpp
 *
 *  Created on: 27-Dec-2017
 *      Author: maran
 */
#include <iostream>

// an emptry class to represent sentinel iterator for cstring range
class cstring_iterator_sentinel {};

class cstring_iterator {
  const char *s {nullptr};
public:
  explicit cstring_iterator(const char *s_) : s {s_} {}
  char operator*() const {
    return *s;
  }
  cstring_iterator& operator++() {
    s++;
    return *this;
  }
  // cstring_range's end will return an emptry cstring_iterator_sentinel
  // the for( e : cstring_range(str)) construct will
  // expand to call != on each iterator (cstring iterator) again end()'s return
  // which is cstring_iterator_sentinel here and hence the below function will suffice
  bool operator!=(cstring_iterator_sentinel) const {
    return s != nullptr && *s != '\0';
  }
  // when cstring_range returns same type as begin()
  // use this != function. but, it has the disadvantage of
  // calculating the string length
//  bool operator!=(cstring_iterator o) const {
//    return s != o.s;
//  }
};

class cstring_range {
  const char *s {nullptr};
public:
  explicit cstring_range(const char *s_) : s {s_} {}
  cstring_iterator begin() const {
    return cstring_iterator {s};
  }
  cstring_iterator_sentinel end() const {
    return cstring_iterator_sentinel {};
  }

  // Aliter: end() returns the same type as begin,
  // but it has to compute the string length
//  cstring_iterator end() const {
//    auto i {0};
//    while (s[i++]);
//    // return iterator that points to '\0' at end of s
//    return cstring_iterator {s + i - 1};
//  }
};

int main(int argc, char *argv[]) {
  for (char c : cstring_range(argv[1])) {
    std::cout << c;
  }
  std::cout << '\n';
}
