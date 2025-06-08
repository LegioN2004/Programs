#include <iostream>
using namespace std;

class Complex {
private:
  int real, imaginary;

public:
  Complex(int r = 0, int i = 0) {
    real = r;
    imaginary = i;
  }

  void print() { cout << real << " + " << imaginary << "i" << endl; }

  // Overloading the + operator to add two Complex numbers
  Complex operator+(Complex c) {
    Complex temp;              // Temporary object to hold the result
    temp.real = real + c.real; // Adding real parts
    temp.imaginary = imaginary + c.imaginary; // Adding imaginary parts
    return temp;                              // Returning the result
  }
  // not using the above, we get the error no operator+ present
};

int main() {
  Complex c1(10, 5), c2(2, 4), c3(1, 1), c4;

  c4 = c1 + c2 + c3; // Using the overloaded + operator
  c4.print();

  // int x = 5, y = 4, z = x + y;
  // cout << "The value of z is: " << z << endl; // 9
  return 0;
}