/*
 * 3.1.cpp
 *
 *  Created on: 10-Dec-2017
 *      Author: maran
 */

// illustration of usage of std::function
// and its advantage over plain function signature
#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <deque>



template <typename ContT>
void print(ContT const & cont) {
  for (auto e : cont) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

// const parameter is non-const as container will be captured by
// reference and updated by the consumer(lambda)
template <typename ContT>
auto create_consumer(ContT & cont) {
  return [&cont](auto const &e) {
    cont.push_back(e);
  };
}

int main() {
  std::vector<int> v;
  std::list<int> l;
  std::deque<int> d;

  // if the element type of the vector is void(*)(int)
  // lambdas that capture different containers cant be accommodated in the
  // vector as the lambdas are inherently of different types
  // std::function is the tool to break this limitation
  std::vector<std::function<void(int)>> consumers {
    create_consumer(v),
    create_consumer(l),
    create_consumer(d)
  };
  for (auto i = 0; i < 5; i++) {
    for (auto consume_fn : consumers) {
      consume_fn(i);
    }
  }
  print(v);
  print(l);
  print(d);
}



