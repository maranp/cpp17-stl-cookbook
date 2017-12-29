/*
 * 11.cpp
 *
 *  Created on: 29-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <algorithm>

static constexpr char tolow(char const c) {
  switch(c) {
  case 'A'...'Z':
    return c - 'A' + 'a';
  default:
    return c;
  }
}

// char_traits for lower case string
class lc_char_traits : public std::char_traits<char> {
public:
  static constexpr void assign(char &r, char const c) {
    r = tolow(c);
  }
  static void copy(char *dst, const char *src, size_t count) {
    std::transform(src, src + count, dst, tolow);
  }
};

// char_traits for case insensitive comparable strings
class ci_char_traits : public std::char_traits<char> {
public:
  constexpr bool eq(char const a, char const b) {
    return tolow(a) == tolow(b);
  }
  constexpr bool lt(char const a, char const b) {
    return tolow(a) < tolow(b);
  }
  static constexpr int compare(const char *s1, const char *s2, size_t count) {
    for(; count; s1++, s2++, count--) {
      if (tolow(*s1) != tolow(*s2))
        break;
    }
    if (count == 0) return 0;
    if (tolow(*s1) < tolow(*s2)) return -1;
    return 1;
  }
};

using lc_string = std::basic_string<char, lc_char_traits>;
using ci_string = std::basic_string<char, ci_char_traits>;

auto & operator<<(std::ostream &os, lc_string const &s) {
  os.write(s.data(), s.length());
  return os;
}

auto & operator<<(std::ostream &os, ci_string const &s) {
  os.write(s.data(), s.length());
  return os;
}

int main() {
  lc_string s1 {"Abc Def Ghi"};
  std::cout << s1 << '\n';
  ci_string s2 {"AbC DeF GhI"};
  std::cout << s2 << '\n';
  ci_string s3 {"ABC DeF GHI"};
  std::cout << s3 << '\n';
  if (s2 == s3) {
    std::cout << "case insensitive match" << '\n';
  }
}



