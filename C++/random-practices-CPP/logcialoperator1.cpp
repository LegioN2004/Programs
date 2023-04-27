#include <iostream>
using namespace std;

int main() {
  int a = 1, b = 2, c = 3, d = 4, e = 5;
  cout << ((a > b) && (b > a)) << "\n";
  cout << ((a > b) && (b > a) && (a > c)) << "\n";
  cout << ((b > a) && (c > a) && (e > c)) << "\n";
  cout << ((b > c) || (b > a)) << "\n";
  cout << (!(c > b));
}
