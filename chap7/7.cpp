/*
 * 7.cpp
 *
 *  Created on: 29-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <fstream>

struct city {
  std::string name;
  size_t population;
  double lat;
  double lng;
};

auto & operator>>(std::istream &is, struct city &c) {
  is >> std::ws;
  std::getline(is, c.name); // default delim of getline is '\n'
  return is >> c.population >> c.lat >> c.lng;
}

int main() {
  std::fstream fs {"cities_7.txt"};
  std::vector<city> vc;
  std::copy(std::istream_iterator<city> {fs}, {}, std::back_inserter(vc));
  for (auto const & c : vc) {
    std::cout << std::setw(15) << std::left << c.name
        << std::setw(10) << std::right << c.population
        // setprecision is total digits bef and aft dec. point
        // setprecision also seem to be sticky but setw is not.
        << std::setw(10) << std::setprecision(8) << c.lat
        << std::setw(10) << c.lng << '\n';
  }

}

