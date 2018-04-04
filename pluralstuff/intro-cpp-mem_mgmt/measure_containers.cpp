/*
 * containers.cpp
 *
 *  Created on: 04-Apr-2018
 *      Author: maran
 */

// git clone https://github.com/google/benchmark.git
//
// export BENCH=$HOME/github/benchmark-google/install
// clang++ -Og -I$BENCH/include -L$BENCH/lib -Wall -pedantic -Werror -std=c++17 -pthreads -lbenchmark
// -fuse-ld=lld measure_containers.cpp -o measure_containers && ./measure_containers

#include <benchmark/benchmark.h>

#include "Resource.h"

#include <algorithm>

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

template <typename C>
void cprint(C const & c) {
  std::for_each(begin(c), end(c), [](auto const & e) {
    cout << e << " ";
  });
  cout << '\n';
}

template <typename C>
static void sorted_insert(C & v) {
  v.push_back(0);
  auto size = 100;
  for (auto i = 0; i < size; i++) {
    auto r = (int) rand();
    auto inserted = false;
    for (auto it = begin(v); it != end(v); it++) {
      if (*it > r) {
        v.insert(it, r);
        inserted = true;
        break;
      }
    }
    if (!inserted) {
      v.push_back(r);
    }
  }
}

template <typename C>
static void sorted_insert_algo(C & v) {
  //v.push_back(0);
  auto size = 100;
  for (auto i = 0; i < size; i++) {
    auto r = (int) rand();
    v.insert(std::upper_bound(begin(v), end(v), r), r);
  }
}

static void bench_sorted_insert_vector(benchmark::State &state) {
  vector<int> v;
  //v.reserve(100);
  for (auto _ : state) {
    sorted_insert(v);
  }
}

static void bench_sorted_insert_list(benchmark::State &state) {
  list<int> v;
  for (auto _ : state) {
    sorted_insert(v);
  }
}

static void bench_sorted_insert_algo_vector(benchmark::State &state) {
  vector<int> v;
  //v.reserve(100);
  for (auto _ : state) {
    sorted_insert_algo(v);
  }
}

static void bench_sorted_insert_algo_list(benchmark::State &state) {
  list<int> v;
  for (auto _ : state) {
    sorted_insert_algo(v);
  }
}

BENCHMARK(bench_sorted_insert_vector);
BENCHMARK(bench_sorted_insert_list);
BENCHMARK(bench_sorted_insert_algo_vector);
BENCHMARK(bench_sorted_insert_algo_list);
BENCHMARK_MAIN();

//int main() {
//  vector<int> v;
//  sorted_insert_algo(v);
//  cprint(v);
//
//  list<int> l;
//  sorted_insert_algo(l);
//  cprint(l);
//}
