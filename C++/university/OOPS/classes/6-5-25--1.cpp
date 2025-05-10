#include <iostream>
using namespace std;

class Number {
  int value;

public:
  Number() { value = 0; }
  Number(int v) { value = v; }

  friend bool operator==(Number n1, Number n2) { return n1.value == n2.value; }
};

int main() {
  Number a(5), b(1), c(5);
  if (a == b) {
    cout << "a is equal to b";
  } else if (a == c) {
    cout << "a is equal to c";
  }
  return 0;
}