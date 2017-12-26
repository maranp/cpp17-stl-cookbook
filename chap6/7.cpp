/*
 * 7.cpp
 *
 *  Created on: 26-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <algorithm>
#include <functional> // not_fn

template <typename It, typename P>
void gather(It it, It endit, It pivot, P pred) {
  // std::not_fn(pred) not present with the compiler
  std::stable_partition(it, pivot, [=](auto c) {
    return !pred(c);
  });
  std::stable_partition(pivot, endit, pred);
}

template <typename It, typename CompFn>
void gather_sort(It it, It endit, It pivot, CompFn fn) {
  // std::not_fn(pred) not present with the compiler
  auto not_fn {
    [&](auto && ... ps) {
      return !fn(ps...);
    }
  };
  std::stable_sort(it, pivot, not_fn);
  std::stable_sort(pivot, endit, fn);
}

int main() {
  std::string a = "_a_a_a_a_a_a_a_a_a_";

  auto is_a { [](auto c) {
    return c == 'a';
  }};

  auto middle { std::begin(a) + a.size() / 2 };
  gather(std::begin(a), std::end(a), middle, is_a);
  std::cout << a << std::endl;
  gather(std::begin(a), std::end(a), std::begin(a), is_a);
  std::cout << a << std::endl;
  gather(std::begin(a), std::end(a), std::end(a), is_a);
  std::cout << a << std::endl;
  gather(std::begin(a), std::end(a), middle, is_a);
  std::cout << a << std::endl;

  std::string b = "_1_6_3_9_2_8_";
  auto mid { std::begin(b) + b.size() / 2 };
  gather_sort(std::begin(b), std::end(b), mid, std::less<>{});
  std::cout << b << std::endl;

}
