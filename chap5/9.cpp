/*
 * 9.cpp
 *
 *  Created on: 24-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <iomanip>

int main() {
  std::vector<int> data;
  std::vector<int> samples;
  auto const ndata = 100;
  auto const nsamples = 100;

  data.reserve(ndata);
  samples.reserve(nsamples);

  const int mean {10};
  const size_t dev {3};
  std::random_device rd;
  std::mt19937 gen {rd()};
  std::normal_distribution<> dis {mean, dev};
  // send a generator, but let it me normally distributed generator
  std::generate_n(std::back_inserter(data), ndata, [&] { return dis(gen); });

  // std::sample not available yet with the compiler :(
  // std::sample(std::begin(data), std::end(data), std::back_inserter(samples),
  //    nsamples, std::mt19937{std::random_device{}()});

  // create a histogram of data (Actually samples but
  // since std::sample is not available, we live with the data vector)
  std::map<int, size_t> histogram;

  for (auto i : data) {
    histogram[i]++;
  }

  for (auto p : histogram) {
    std::cout << std::setw(2) << p.first << " " << std::string(p.second, '*');
    std::cout << "\n";
  }
}



