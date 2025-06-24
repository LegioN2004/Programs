#include <iostream>
using namespace std;

class Rectangle {
public:
  int length, breadth;
  int calcArea() { return length * breadth; }

  void printArea(Rectangle *r) { cout << r->calcArea(); }
};

int main() {
  Rectangle r1, r2;
  r2.breadth = 2;
  r2.length = 2;
  r1.printArea(&r2);

  return 0;
}