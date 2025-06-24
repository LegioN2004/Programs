#include <iostream>
using namespace std;

class Base {
public:
  Base() { cout << "Base class default constructor\n"; }
  Base(int x) { cout << "Base class parameterized constructor: " << x << "\n"; }
};

class Derived : public Base {
public:
  // Delegating constructor (calls another constructor in the same class)
  Derived() : Derived(10) { cout << "Derived class default constructor\n"; }

  // Constructor that calls base class constructor
  Derived(int y) : Base(y) {
    cout << "Derived class parameterized constructor: " << y << "\n";
  }
};

int main() {
  Derived obj; // This will call Derived(), which delegates to Derived(int)
  return 0;
}