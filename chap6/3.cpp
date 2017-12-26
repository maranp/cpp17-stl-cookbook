/*
 * 3.cpp
 *
 *  Created on: 25-Dec-2017
 *      Author: maran
 */

#include <complex>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

// https://stackoverflow.com/questions/6563810/m-pi-works-with-math-h-but-not-with-cmath-in-visual-studio
#define _USE_MATH_DEFINES
#include <cmath>

using cmplx = std::complex<double>;
using csignal = std::vector<cmplx>; // csignal -> container of signal points || complex signal

class num_iterator {
  size_t i;
public:
  explicit num_iterator(size_t n) : i {n} {}
  auto operator*() const {
    return i;
  }
  auto & operator++() {
    i++;
    return *this;
  }
  auto operator!=(num_iterator const & other) const {
    return i != other.i;
  }
};

static csignal fourier_transform(csignal const &s, bool back = false) {
  using namespace std;
  // note, {} universal initializer does not help here.
  // {} is taken as initializer list and parameter is taken as first element of the vector
  // instead of its size
  csignal t (s.size()); // t is the transformed signal vector from source s

  // fourier transform's formula specific expression
  // i am least bothered
  const double pol { 2.0 * (M_PI) * (back ? -1.0 : 1.0) };
  const double div { back ? 1.0 : double(s.size()) };

  // simplification of fourier transformtion
  // for k = 0 to n
  //  for j = 0 to n
  //   t[k] = f(s[j], j, k) // for each kth signal point of t, all n singal points are processed

  // t[k] = f(s[j], j, k)
  // transform(num_itertar(0), num_iterator(n), begin(t), f)
  // where f is called by transform k times with each k value (the k value is provided by num_iterator
  // f is supposed to take all s[0 .. n] (ie. each of s[j]) to find one t[k]
  // so, f has to apply accumulate on s[] each time it is called by transform

  auto sum_up {
    [=, &s](auto k) {
      return [=, &s](cmplx const &c, size_t j) {
        return c + s[j] * std::polar(1.0, pol * k * j / double(s.size()));
      };
    }
  };

  // (2) to_ft returns a function object which takes k and returns
  // the computed value for t[k]
  auto to_ft {
    [=, &s](auto k) {
      return std::accumulate(num_iterator {0}, num_iterator {s.size()},
             cmplx {}, /* initial value of what's going to be accumulated */
             sum_up(k))
             / div;
    }
  };
  // bottom-up approach
  // (1) transform
  std::transform(num_iterator {0}, num_iterator {s.size()}, std::begin(t), to_ft);

  return t;
}

static auto gen_cosine(size_t period_len) {
  using namespace std;
  return [period_len, n{0}]() mutable {
    return std::cos(double(n++) * 2.0 * M_PI / period_len);
  };
}

static auto gen_square_wave(size_t period_len) {
  using namespace std;
  return [period_len, n{period_len * 7 / 4}]() mutable {
    return ((n++ * 2 / period_len) % 2) * 2 - 1.0;
  };
}

template <typename F>
static csignal signal_from_generator(size_t len, F gen) {
  csignal r (len);
  std::generate(std::begin(r), std::end(r), gen);
  return r;
}

void print_signal(csignal const &s) {

  std::transform(std::begin(s), std::end(s), std::ostream_iterator<double> {std::cout, " "},
      [](cmplx c) {
        return c.real();
      }
    );
  std::cout << "\n";
}

int main() {
  const size_t sig_len {100};
  auto cosine_signal {signal_from_generator(sig_len, gen_cosine(sig_len / 2))};
  auto sq_wv_signal {signal_from_generator(sig_len, gen_square_wave(sig_len / 2))};

  auto transformed_sq_wv_signal {fourier_transform(sq_wv_signal)};

  print_signal(cosine_signal);
  print_signal(fourier_transform(cosine_signal));
  print_signal(transformed_sq_wv_signal);
  print_signal(sq_wv_signal);
  print_signal(fourier_transform(sq_wv_signal));
}



