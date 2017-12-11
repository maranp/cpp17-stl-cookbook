/*
 * 4.cpp
 *
 *  Created on: 10-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <functional>

// A learning here is,
// a function that returns function object
// 1) helps to create a composite function of many simpler functions
// 2) helps to create a function that does something more than its simpler version
// see 3.cpp
// in general, if we have a base function (object), if we want it to do
// something more, create a function object for it via a function that creates it
// pass the special stuff to the factory function that creates the function object
// and define the function object in the factory function to take the parameters
// taken by the base parameter

// a function that returns function object aka lambda
template <typename T, typename... Ts>
auto concat(T t, Ts... ts) {
  if constexpr (sizeof...(ts) > 0) {
    // many function objects passed to concat.
    // return the function object that will apply t
    // that takes parameters as the result of
    // applying function objects concat(ts...) on the params
    return [=](auto... params) {
      // this fn. obj. is the actual function the user is going
      // to call with the parameters. It needs to return the final return value
      // we have the final function "t" in the composite series.
      // call it with parameter. What is it's parameter?
      // Its parameter is the return value of composite functions called.
      // the composite functions are the functions represented by ts...
      // Use the composite generator concat which will take ts... which
      // will give ts...composite and give this composite function
      // the original user provided parameters
      return t(concat(ts...)(params...));
    };
  } else {
    return t;
  }
}

int main() {
  auto twi = [](auto i) { return 2 * i; };
  auto thri = [](auto i) { return 3 * i; };
  auto expr = concat(twi, thri, std::plus<int>{});

  std::cout << expr(4, 4) << std::endl;
}

