#include <iostream>
using namespace std;

class Rectangle {
  int length, width;

public:
  Rectangle() {}

  Rectangle(int l, int w) {
    this->length = l;
    this->width = w;
  }

  ~Rectangle() {
    cout << "Rectangle's length: " << length << " and width: " << width << endl;
  }

  void Area() { cout << "Area of rectangle: " << length * width << endl; }

  void Perimeter() {
    cout << "Perimeter of rectangle: " << 2 * (length + width) << endl;
  }
};

int main() {
  Rectangle r1(10, 5); // Parameterized constructor
  r1.Area();
  r1.Perimeter();

  return 0;
}