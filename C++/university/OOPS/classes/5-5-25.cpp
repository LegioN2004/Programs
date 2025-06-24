#include <iostream>
using namespace std;

class addAndSub {
  int a, b;

public:
  // using operator overloading printout the square of two numbers that are
  // negative
  addAndSub() { a = 0, b = 0; }

  addAndSub(int a, int b) { this->a = a, this->b = b; }

  void operator-() {
    this->a = -a;
    this->b = -b;
  }

  void operator*() {
    this->a *= a;
    this->b *= b;
  }

  void print() { cout << "\nThe square of a and b is " << a << " & " << b; }
};

int main() {
  addAndSub a1(-5, -4);
  a1.print();
  -a1;
  a1.print();
  *a1;
  a1.print();

  return 0;
}