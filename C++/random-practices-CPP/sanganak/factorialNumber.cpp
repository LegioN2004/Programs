#include <iostream>
using namespace std;

int main() {
  int a, c = 1;  // 5
  cout << "Enter the input ";
  cin >> a;
  if (a == 0) {
    cout << "factorial of " << a << " is 1";
    return 0;
  }
  for (int i = 1; i < a; i++) {
    c = c * i;
  }
  cout << c << " is the factorial of the number";
  return 0;
}