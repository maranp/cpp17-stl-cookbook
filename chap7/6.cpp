/*
 * 6.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <iomanip> // setfill, setw
//#include <locale>

void print_with_format(int x, int width, char fill_char = ' ') {
  std::cout << std::setfill(fill_char);
  std::cout << std::left << std::setw(width) << x << '\n';
  std::cout << std::right << std::setw(width) << x << '\n';
  std::cout << std::internal << std::setw(width) << x << '\n';
}

int main() {
  print_with_format(2355, 6);
  print_with_format(2355, 6, '_');

  std::cout << std::hex << std::uppercase << std::showbase;
  print_with_format(0x2abcd, 6, '_');

  std::cout << std::oct << std::showbase;
  print_with_format(2355, 8, '_');

  std::cout << std::dec;
  print_with_format(2355, 8, '_');

  std::cout << 12.3 << '\n';
  std::cout << 12.0 << '\n';
  std::cout << std::showpoint << 12.0 << 12.3 << '\n';
  std::cout << std::scientific << 120000.123 << '\n';
  std::cout << std::fixed << 120000.123 << '\n';

  std::cout << 0.00000001 << '\n';
  std::cout << std::setprecision(10) << 0.00000001996 << '\n';
  std::cout << std::setprecision(1) << 0.00000001 << '\n';

  std::cout << true << false << '\n';
  std::cout << std::boolalpha << true << false << '\n';
}



