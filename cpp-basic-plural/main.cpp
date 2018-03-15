/*
 * main.cpp
 *
 *  Created on: 15-Mar-2018
 *      Author: maran
 */
#include <person.h>
#include <Accum.h>
#include <iostream>

int main() {
  Accum int_accum {0};
  int_accum += 20;
  int_accum += 30;
  std::cout << int_accum.get_total() << std::endl;

  Person p1("Maran", "P", 10);
  Person p2("Maran", "P", 20);
  Accum<Person> person_accum {0};

  person_accum += p1;
  person_accum += p2;
  std::cout << person_accum.get_total() << std::endl;
}



