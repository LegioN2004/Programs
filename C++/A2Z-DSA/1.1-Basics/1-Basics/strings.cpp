#include <iostream>
using namespace std;

/*
strings are just like C in C++ but with more functionalities. It can do all the
following. It also stores the individual characters of the string in an array.
So you can modify the characters of the string as well using the index.
*/

void changeString(string &s) { s[0] = 'J'; }

int main() {
  string s = "Hello";
  cout << s << endl;  // prints Hello
  //   cout << s[0] << endl;            // prints H
  //   cout << s.length() << endl;      // prints 5
  //   cout << s.size() << endl;        // prints 5
  //   cout << s.substr(1, 3) << endl;  // prints ell
  //   cout << s.find("l") << endl;     // prints 2
  //   cout << s.find("l", 3) << endl;  // prints 3
  //   cout << s.find("x");
  changeString(s);
  cout << s << endl;  // prints Hello
  return 0;
}