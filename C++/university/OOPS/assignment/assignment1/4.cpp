// with argument and without return type

#include <iostream>
using namespace std;

void add(int a, int b) {
  cout << "The sum value is " << a + b;
}

int main() {
  add(1,5);
  return 0;
}