#include <iostream>
using namespace std;

// wap a program to print four numbers
int main() {
  int a = 0, b = 0;
  for (int i = 0; i < 4; i++) {
    cin >> b;
    a = a + b;
  }
  cout << "The sum is " << a;
  return 0;
}