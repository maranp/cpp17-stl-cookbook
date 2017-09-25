/*
 * pimpl.cpp
 *
 *  Created on: 25-Sep-2017
 *      Author: maran
 *  https://www.fluentcpp.com/2017/09/22/make-pimpl-using-unique_ptr/
 */

#include "fridge.h"
#include <memory>

// if engine whihc is used by fridge changes
// thism user of fridge will also be recompiled
// though engine is never used directly by this user.
// to avoid recompilation of such users,
// use pimpl idiom so that the compilation dependency kis avoided.
int main() {
  Fridge f;
  f.cool_down();

  return 0;
}

