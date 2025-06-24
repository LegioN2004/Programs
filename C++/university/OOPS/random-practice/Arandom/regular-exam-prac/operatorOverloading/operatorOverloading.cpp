#include <iostream>
using namespace std;

class Complex {
private:
  int real, img;

public:
  Complex(int real = 0, int img = 0) {
    this->real = real;
    this->img = img;
  }

  Complex operator+(Complex c) {
    Complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
  }

  void print() { cout << real << " + " << img << "i" << endl; }
};

int main() {
  Complex c1(2, 3), c2(3, 4), c3(1, 2), c4;
  c1.print();
  c2.print();
  c3.print();

  c4 = c1 + c2 + c3;
  c4.print();
  return 0;
}