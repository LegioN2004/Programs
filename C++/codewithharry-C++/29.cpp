#include <iostream>
using namespace std;

class A {
  int a, b;

public:
  // creating a constructor
  // Constructor is a special member function of a class with the same name as
  // of the class. It is used to initialize the objects of its class. It is
  // automatically invoked whenever an object of the class is created.

  A(void); // constructor declaration
  void printData() {
    cout << "The value of a is: " << a << " + " << b << "i" << endl;
  }
};

// if we don't use this, we'll get garbage value
// declared here. can be defined in the class as well.
A::A(void) { // --> default constructor
  a = 10;
  b = 20;
};

int main() {
  A c1, c2, c3; // c object
  c1.printData();
  c2.printData();
  c3.printData();

  return 0;
}

// if we change the name of the constructor in the definition and declaration
// we'll get a warning and some garbage value. constructor doesn't have a return
// type.

// NOTE: the constructor which doesn't take any value is termed as "default
// constructor"

/* Characteristics:

1. It should be declared in the public section of the class
2. They are automatically invoked when an object is created, as such it has the
same name as the class.
3. doesn't have return type and can't return values
4. It can have default arguments
5. We cannot refer to their addresses

*/
