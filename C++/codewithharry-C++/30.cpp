#include <iostream>
using namespace std;

class Complex {
  int a, b;

public:
  Complex(int, int); // constructor declaration

  void printData() {
    cout << "The value of a is: " << a << " + " << b << "i" << endl;
  }
};

// Complex::Complex(void) {
Complex::Complex(int x,
                 int y) { // --> This is called parameterized constructor, it
                          // takes values and initializes the data members. It takes 2 params
  a = x;
  b = y;
};

/*
Two ways to send the values to
1. Implicit call
2. Explicit call
*/

int main() {
  // Complex c1; // c object

  // implicit call
  Complex c1(4, 5);
  c1.printData();

  // explicit call
  Complex a = Complex(5, 6);
  a.printData();

  return 0;
}