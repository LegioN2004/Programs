// without argument and with return type

#include <iostream>
using namespace std;

int add() {
  int a = 0, b = 0;
  cin >> a >> b;
  cout << "the value is ";
  return a + b;
}

int main() {
  cout << "Enter two numbers: ";
  cout << add();
  return 0;
}