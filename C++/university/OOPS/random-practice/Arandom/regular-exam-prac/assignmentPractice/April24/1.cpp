#include <iostream>
using namespace std;

class Box {
private:
  int length, breadth, height;

public:
  Box(int length, int breadth, int height) {
    this->length = length;
    this->breadth = breadth;
    this->height = height;
  }

  friend int calcArea(Box b);
};

int calcArea(Box box) { return box.length * box.breadth * box.height; }

int main() {
  Box b(1, 2, 3);
  // friend functions are called like normal functions
  cout << "The area is " << calcArea(b);
  return 0;
}