/*
 * fridge_impl.cpp
 *
 *  Created on: 25-Sep-2017
 *      Author: maran
 */

#include "fridge.h"
#include "engine.h"
#include <iostream>
#include <memory>

class Fridge_impl {
public:
  void cool_down() {
    std::cout << "cool down" << std::endl;
  }
private:
  Engine engine_;
};

Fridge::Fridge() : fimpl (new Fridge_impl) {}
Fridge::~Fridge() = delete;

void Fridge::cool_down() {
  fimpl->cool_down();
}


