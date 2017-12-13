/*
 * 6.cpp
 *
 *  Created on: 11-Dec-2017
 *      Author: maran
 */
#include <functional>
#include <iostream>

template <typename... Fs>
auto gen_muticaller(Fs... functions) {
  return [=](auto param) {
    (void) std::initializer_list<int> {
      ((void)functions(param), 0)...
    };
  };
}

template <typename F, typename... Args>
void for_each(F f, Args... args) {
  (void) std::initializer_list<int>{
    // f(args)... is the actual expression we require, but see pg 156
    // for its limitations
    // ((void)f(args), 0) is a comma expression
    // last in the comman expression is the result of the expression
    // f, is if returns anything, cast it to void and
    // hence effectively return nothing
    // but the initializer list needs some value as its constructor parameter
    // so, put 0 in its place with the help of comma expression
    ((void)f(args), 0)...
  };
}

auto gen_brace_print(char a, char b) {
  return [=](auto x) {
    std::cout << a << x << b << ",";
  };
}

int main() {
  auto f {gen_brace_print('[', ']')};
  auto g {gen_brace_print('(', ')')};
  auto h {gen_brace_print('{', '}')};
  auto nl {[](auto) { std::cout << std::endl; }};
  auto multi_print {gen_muticaller(f, g, h, nl)};
  multi_print(5);

  for_each(multi_print, 1, 2, 3, 4);
}

