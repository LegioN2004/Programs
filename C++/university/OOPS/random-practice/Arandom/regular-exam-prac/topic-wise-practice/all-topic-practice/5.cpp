#include <iostream>
using namespace std;

class Complex {
  int a, b;

public:
  Complex() {
    a = 0;
    b = 0;
  }

  Complex(int a, int b) {
    this->a = a;
    this->b = b;
  }

  friend istream &operator>>(istream &in, Complex &n) {
    in >> n.a;
    in >> n.b;
    return in;
  }

  friend ostream &operator<<(ostream &out, Complex &n) {
    out << "\nA: " << n.a << endl;
    out << "B: " << n.b << endl;
    return out;
  }

  Complex operator+(const Complex &n) {
    Complex temp;
    temp.a = a + n.a;
    temp.b = b + n.b;
    return temp;
  }

  Complex operator-(const Complex &n) {
    Complex temp;
    temp.a = a - n.a;
    temp.b = b - n.b;
    return temp;
  }

  void display() { cout << "a: " << a << " b: " << b << endl; }
};

int main() {
  Complex c1(1, 2), c2(3, 4), c3;
  c1.display();
  c2.display();
  c3 = c1 + c2;
  c3.display();
  c3 = c2 - c1;
  c3.display();
  cin >> c1;
  cin >> c2;
  c1.display();
  c2.display();
  c3 = c1 + c2;
  c3.display();
  c3 = c1 - c2;
  c3.display();

  return 0;
}