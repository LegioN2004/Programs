// with argument and with return type

#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

int main() {
  int a = 0, b = 0;
  cin >> a >> b;
  cout << "The value is " << add(a, b);
  return 0;
}