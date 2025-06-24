#include <iostream>
using namespace std;

// unary operator overloading +/-
class Unary {
  int value;

public:
  Unary(int v) : value(v) {}
  void operator-() { value = -value; }
  void operator+() { value = +value; }
  void print() { cout << "Value: " << value << endl; }
};

// binary operator overloading, binary operations on + or minus
class Minus {
  int a = 0, b = 0;

public:
  Minus(int a = 0, int b = 0) {
    this->a = a;
    this->b = b;
  }

  Minus operator-(Minus c) {
    Minus temp;
    temp.a = a - c.a;
    temp.b = b - c.b;
    return temp;
  }

  void print() { cout << "a: " << a << " b: " << b << endl; }
};

class Add {
  int a = 0, b = 0;

public:
  Add(int a = 0, int b = 0) {
    this->a = a;
    this->b = b;
  }

  Add operator+(Add c) {
    Add temp;
    temp.a = a + c.a;
    temp.b = b + c.b;
    return temp;
  }

  void print() { cout << "a: " << a << " b: " << b << endl; }
};

class operatorOverloading {
  int a, b;

public:
  operatorOverloading(int a = 0, int b = 0) {
    this->a = a;
    this->b = b;
  }
  friend istream &operator>>(istream &in, operatorOverloading &s) {
    cout << "enter the numbers: ";
    in >> s.a;
    in >> s.b;
    return in;
  }

  friend ostream &operator<<(ostream &out, const operatorOverloading &s) {
    out << "\na is: " << s.a << endl;
    out << "b is: " << s.b << endl;
    return out;
  }
};

// >> << operator overloading
void operatorOverloadingFunction() {
  operatorOverloading o1;
  cin >> o1;
  cout << o1;
}

// increment prefix and postfix overloading
class Increment {
  int a;

public:
  Increment(int a = 0) { this->a = a; }

  Increment operator++() {
    ++a;
    return *this;
  }

  Increment operator++(int) {
    Increment temp = *this;
    a++;
    return temp;
  }

  void print() { cout << "Increment: " << a << endl; }
};

// == operator overloading
class DoubEqualOverloading {
  int value;

public:
  DoubEqualOverloading(int v) { value = v; }
  friend bool operator==(DoubEqualOverloading n1, DoubEqualOverloading n2) {
    return n1.value == n2.value;
  }
};


// void unaryOperatorOverloading(){}

int main() {

  // unary operator overloading
  Unary u(2);
  -u;
  u.print();
  +u; // separate likhile he ulai nohole same buli bhbi loi
  u.print();

  // binary operator overloading
  Minus m1(1, 2), m2(2), m3;
  m3 = m1 - m2;
  m1.print();
  m2.print();
  m3.print();

  Add a1(1, 2), a2(2), a3;
  a3 = a1 + a2;
  m1.print();
  m2.print();
  m3.print();

  // >> << operator overloading
  operatorOverloadingFunction();

  // increment prefix and postfix overloading
  Increment i1(2), i2;
  i2 = ++i1;
  i2.print();
  i2 = i1++;
  i2.print();

  // == operator overloading
  DoubEqualOverloading n1(2), n2(3);
  if (n1 == n2) {
    cout << "n1 is equal to n2";
  } else {
    cout << "n1 is not equal to n2";
  }

  return 0;
}