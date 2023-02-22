#include <iostream>
using namespace std;

int main() {
  int a = 1, b = 2, c = 3, d = 4, e = 5;
  cout << ((a > b) && (b > a)) << "\n";
  cout << ((b > c) || (b > a)) << "\n";
  cout << (!(c > b));
}
