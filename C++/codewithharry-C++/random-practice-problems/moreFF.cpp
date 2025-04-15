#include <iostream>
using namespace std;

// make formward declaration so that the compiler knows that first function ran was the ce
class Complex;

//
class Calculator {
public:
  int add(int a, int b) { return a + b; }

  // not a definition should be done here, it just needs to know that the class exists
  int sumComplex(Complex, Complex);
};

class Complex {
  int a, b;
  // this is what's known as member friend functions it gives the friend function of calculator, access to the private members of the Complex class using the following syntax structure(define like we did here. thing to note is that we are not using the scope resolution operator here and also the function has to be a friend function
  // the function is defined here.
  friend int Calculator::sumComplex(Complex, Complex);

public:
  void setNumber(int n1, int n2) {
    a = n1;
    b = n2;
  }

  void printNumber() {
    cout << "Your number is " << a << " + " << b << "i" << endl;
  }
};

// define the function after both the classes
int Calculator::sumComplex(Complex o1, Complex o2) { return (o1.a + o2.a); }

int main() {
  Complex o1, o2;
  o1.setNumber(1, 4);
  o2.setNumber(5, 8);
  Calculator calc;
  int res = calc.sumComplex(o1, o2);
  cout << "The sum of the complex numbers is: " << res << endl;
  return 0; }