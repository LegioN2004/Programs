#include <iostream>
using namespace std;

class Car {
  float x, y;

public:
  Car() {
    x = 0.01f, y = 0.03f;
    std::cout << "Created constructor" << std::endl;
  }

  Car(float X, float Y) { x = X, y = Y; }

  // object destroy huar pasot compiler e destructorok call kore.
  ~Car() { std::cout << "Destroyed constructor" << std::endl; }

  void print() {
    std::cout << "Value of X is " << x << " and Y is " << y << std::endl;
  }
};

int main() {
  Car e1;
  e1.print();
  return 0;
}