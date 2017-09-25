/*
 * fridge.h
 *
 *  Created on: 25-Sep-2017
 *      Author: maran
 */

#ifndef FRIDGE_H_
#define FRIDGE_H_

#include <memory>

class Fridge {
public:
  Fridge();
  ~Fridge();
  void cool_down();
private:
  class Fridge_impl;
  std::unique_ptr<Fridge_impl> fimpl;
};


#endif /* FRIDGE_H_ */
