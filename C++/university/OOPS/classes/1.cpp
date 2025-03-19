#include <iostream>
using std::cout, std::cin;

class MyClass {
private:
  int a, b;
  int read() {
    cin >> a >> b;
    return a + b;
  }

public:
  void add();
};

MyClass::add() { cout << read(); }

int main() {
  MyClass A;
  A.add();
}
