/*
 * 4.cpp
 *
 *  Created on: 25-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
  const size_t sig_len = 100;
  std::vector<double> as (sig_len);
  std::vector<int> ds (sig_len);

  using namespace std;
  auto sine_gen {
    [n {0}]() mutable {
      return 5.0 * std::sin(n++ * 2.0 * M_PI / 100);
    }
  };

  std::generate(std::begin(as), std::end(as), sine_gen);
  std::copy(std::begin(as), std::end(as), std::ostream_iterator<double> {std::cout, " "});
  std::cout << '\n';

  std::copy(std::begin(as), std::end(as), std::begin(ds));
  std::copy(std::begin(ds), std::end(ds), std::ostream_iterator<double> {std::cout, " "});
  std::cout << '\n';

  std::cout << std::inner_product(std::begin(as), std::end(as), std::begin(ds), 0.0, std::plus<double>{},
      [](double a, double b) {
        return std::pow(a - b, 2);
      }) << std::endl;
}



