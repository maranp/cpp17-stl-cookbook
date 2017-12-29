/*
 * 10.cpp
 *
 *  Created on: 29-Dec-2017
 *      Author: maran
 */
#include <iostream>
#include <fstream>

class cout_to_file_redirector {
  using buftype = decltype(std::cout.rdbuf());
  // order of declaration of ofs and buf_backup is important
  // as buf_backup is initialisation depends on instantiation of ofs
  std::ofstream ofs;
  buftype buf_backup;
public:
  explicit cout_to_file_redirector(std::string const &filename)
    : ofs {filename},
      // save cout's internal buffer in buf_backup and set its buffer to ofs's internal buffer
      buf_backup { std::cout.rdbuf(ofs.rdbuf())} {}
  explicit cout_to_file_redirector()
    : ofs {}, buf_backup {std::cout.rdbuf(ofs.rdbuf())} {}

  ~cout_to_file_redirector() {
    std::cout.rdbuf(buf_backup);
  }

};

void print_heavy_fn() {
  std::cout << "asjdfkj hgaskdsdh" << std::endl;
  std::cout << "ashga gaehf adasd asd,mfhg" << std::endl;
  std::cout << "2q65343von v4 nv2n6; bv1lb553 2b55y" << std::endl;
}

int main() {
  std::cout << "on screen\n";
  {
    cout_to_file_redirector _ {"out.txt"};
    print_heavy_fn();
  }
  std::cout << "back on screen\n";
  {
    // equivalent to redirecting to /dev/null
    cout_to_file_redirector _ {};
    print_heavy_fn();
  }
  std::cout << "back on screen\n";
}



