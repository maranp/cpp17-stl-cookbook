/*
 * jason_pacific.cpp
 *
 *  Created on: 05-Nov-2017
 *      Author: maran
 */

struct S {
  // user declared default constructor
  // destructor is defaulted
  S() = default;
  // user declared copy constructor (though deleted)
  // copy assignment is defaulted though deprecated
  S(S const &) = delete;
  // user declared move constructor; move assignment is not declared
  S(S&&) = default;

  // user declared move constructor; move assignment is not declared
  // S(S&&) = delete;
};

auto getS() {
  S s;
  return s; // move. To confirm, delete the move constructor and recompile
            // so, local object when returned as value is actually "moved"
            // to the return location
}
int main() {
  S s = getS();
}
