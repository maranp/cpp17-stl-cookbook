/*
 * fridge.h
 *
 *  Created on: 25-Sep-2017
 *      Author: maran
 */

#ifndef FRIDGE_H_
#define FRIDGE_H_

#include "engine.h"
#include <iostream>

class Fridge {
public:
  void cool_down();
private:
  Engine engine_;
};


#endif /* FRIDGE_H_ */
