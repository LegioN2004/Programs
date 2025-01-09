#include <iostream>

using namespace std;

int main() {
  int a = 10;
  float b = 10.5;
  double c = 299.99;  // gives 299.99
  // double c = 299.9998989898;  // gives 300, compiler's it's almost 300 so be
  // it
  char d = 'A';
  // char d = 'AB'; // gives B
  // char d = 'ABC'; // gives C
  bool e = true;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << e << endl;

  return 0;
}