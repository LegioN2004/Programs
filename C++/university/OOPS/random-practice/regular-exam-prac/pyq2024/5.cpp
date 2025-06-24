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

  Complex operator+(const Complex& c) {
    Complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
  }

  friend ostream &operator<<(ostream &out, const Complex &c);
};

ostream &operator<<(ostream &out, const Complex &c) {
  out << c.real << " + " << c.img << "i";
  return out;
}

int main() {
  Complex c1(1, 2), c2(3, 4), c3(4, 5), c4;

  c4 = c1 + c2 + c3;

  cout << c1 << endl;
  cout << c2 << endl;
  cout << c3 << endl;
  cout << c4 << endl;

  return 0;
}
