#include <iostream>
using namespace std;

class Complex {
private:
  int a, b;

public:
  Complex() {
    a = 0;
    b = 0;
  }

  Complex(int x, int y) {
    a = x;
    b = y;
  }

  // we are trying to make the value of b by default be 0
  Complex(int x) {
    a = x;
    b = 0;
  }

  void printNumber() {
    cout << "Your number is " << a << " + " << b << "i" << endl;
  }
};

int main() {
  Complex c1(4, 6);
  c1.printNumber();

  Complex c2(4);
  c2.printNumber();

  /* if there are no arguments required in the constructor, then don't use the
   parentheses like we do with functions to call them even if they have no
   arguments. */
  Complex c3;
  c3.printNumber();

  /* how are we able to do this: It is called constructor overloading. It is a
   feature of OOPs. It allows us to have multiple constructors with different
   parameters. The compiler is able to differentiate between the two
   constructors based on the number of parameters passed to it. This is called
   constructor overloading. We can make as many constructors as we want with
   different parameters.
   Same as function overloading.
  */

  return 0;
}