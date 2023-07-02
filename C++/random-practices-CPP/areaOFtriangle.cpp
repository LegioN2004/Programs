#include <iostream>
using namespace std;

int main() {
  float a, c;
  float b;
  cout << "Enter the base and height: ";
  cin >> a >> c;
  b = (1.0 / 2) * (a * c);
  cout << "the area of the triangle is" << b;
  return 0;
}
