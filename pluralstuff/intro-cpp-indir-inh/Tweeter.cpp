/*
 * Tweeter.cpp
 *
 *  Created on: 19-Mar-2018
 *      Author: maran
 */

#include "Tweeter.h"

Tweeter::Tweeter(std::string first,
    std::string last,
    int arbitrary,
    std::string handle)
  : Person {first, last, arbitrary},
    twitterhandle {handle} {}

 Tweeter::~Tweeter() {}

 std::string Tweeter::GetName() const {
   return Person::GetName() + " " + twitterhandle;
 }

 int Tweeter::GetNumber() const {
   return 0;
 }

