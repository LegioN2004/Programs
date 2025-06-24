#include <iostream>
using namespace std;

class Rectangle {
public:
  int length, breadth;
  Rectangle(int length, int breadth) {
    this->length = length;
    (*this).breadth = breadth;
  }

  int area() { return length * breadth; }
};

int main() {

  int l, b;
  cin >> l >> b;

  Rectangle r(l, b);
  cout << "Area is: " << r.area();

  return 0;
}