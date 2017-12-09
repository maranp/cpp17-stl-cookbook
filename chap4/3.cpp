/*
 * 3.cpp
 *
 *  Created on: 27-Nov-2017
 *      Author: maran
 */

#include <vector>
#include <deque>
#include <list>

#include <functional>
#include <iostream>

template <typename ContainerT>
void print(ContainerT const & c) {
  for (auto e : c) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

template <typename ContainerT>
auto get_container_updater(ContainerT &c) {
  return [&c](auto e) {
    c.push_back(e);
  };
}

int main() {
  std::vector<int> v;
  std::deque<int> d;
  std::list<int> l; // = {1, 2, 3};

  auto v_updater = get_container_updater(v);
  auto d_updater = get_container_updater(d);
  auto l_updater = get_container_updater(l);
  for (auto i = 1; i < 10; i++) {
    v_updater(i);
    d_updater(i);
    l_updater(i);
  }

  std::vector<std::function<void (int)>> container_updaters {
    v_updater, d_updater, l_updater
  };

  for(auto updater : container_updaters) {
    updater(88);
  }

  print(v);
  print(d);
  print(l);
}
