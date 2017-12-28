/*
 * 4.cpp
 *
 *  Created on: 28-Dec-2017
 *      Author: maran
 */

#include <iostream>
#include <limits>

using namespace std;
int main() {
  int a; double b;
  if (cin >> a >> b) {
    cout << a << b << '\n';
  } else {
    cout << "failed\n";
  }

  if (cin >> a >> b) {
    cout << a << b << '\n';
  } else {
    cout << "failed\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  if (cin >> a >> b) {
    cout << a << b << '\n';
  } else {
    cout << "failed\n";
    // bring cin back to good state
    cin.clear();
    // now clear the buffer as the internal cursor still points to the bad input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  // getline reads all chars to s until it finds ',' and get into the loop body
  // whatever remains in the inputstream after ',' will be taken by getline in the next iteration
  // consecutive commas with optional whitespace in between will cause the loop to break
  for (string s; getline(cin >> ws, s, ',');) {
    if (s.empty()) {
      break;
    }
    cout << "name: " << s << '\n';
  }

}
