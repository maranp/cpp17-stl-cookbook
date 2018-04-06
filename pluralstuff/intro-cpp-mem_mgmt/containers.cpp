/*
 * containers.cpp
 *
 *  Created on: 04-Apr-2018
 *      Author: maran
 */


#include "Resource.h"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main() {
  try {
    Resource r("local");
    cout << "----------------------------------------" << endl;
    vector<Resource> v;
    // reserve avoids moving (relocating) the vector for
    // each push_back until the reserved number of entries are pushed back
    //v.reserve(3);
    v.push_back(Resource("first"));
    // a construction, copy construction, a destruction
    // are reduced to one construction (in the vector directly)
    //v.emplace_back("first");
    cout << "----------------------------------------" << endl;
    // this could be happening behind the scenes
    // push_back could be taking forwarding reference (universal reference) as its parameter
    // when it wants to construct the pushed back object in place in the vector,
    // it could be calling the constructor of the object with parameter inside std::forward
    // now the constructor call can be resolved between copy and move constructor
    // based on the parameter being lvalue or rvalue respectively
    v.push_back(Resource("second"));
    throw (std::bad_exception());
    cout << "----------------------------------------" << endl;
    v.push_back(Resource("third"));
    cout << "----------------------------------------" << endl;
  } catch (std::exception& e) {
    cout << "exception caught" << endl;
  }
  return 0;
}

