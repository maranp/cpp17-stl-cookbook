#include <utility>
#include <string>
#include <iostream>

struct S {
  int i = 0;
  std::string s = "world";
  ~S() {
    std::cout << s << std::endl;
  }
};

int main() {
  auto [i, s] = S{}; // auto __tmp = S{};
  // auto & i = __tmp i; auto &s = __tmp.s
  s = "structured binding"; // ==> __tmp.s = "st..";
  std::cout << "hello ";
  // __tmp is about to get destructed
  // destructor prints S::s which isNOT "world"
  // as structed binding is actually reference to the
  // returned object's corresponding member
}
