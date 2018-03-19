/*
 * Accum.h
 *
 *  Created on: 15-Mar-2018
 *      Author: maran
 */

#ifndef CPP_BASIC_PLURAL_ACCUM_H_
#define CPP_BASIC_PLURAL_ACCUM_H_


template <typename T>
class Accum {
private:
  T total;
public:
  Accum(T const & t) : total {t} {}
  T operator+=(T const & t) {
    return total = total + t;
  }
  T get_total() {
    return total;
  }
};

template <>
class Accum<Person> {
private:
  int total;
public:
  Accum(int t) : total {t} {}
  int operator+=(Person const & p) {
    return total = total + p.get_age();
  }
  int get_total() {
    return total;
  }
};


#endif /* CPP_BASIC_PLURAL_ACCUM_H_ */
