#include <cmath>
#include <iostream>
using namespace std;

class Shape {
public:
  virtual double area() = 0;
  virtual double perimeter() = 0;
  virtual ~Shape() {}
};

class Circle : public Shape {
  double radius;

public:
  Circle(double r) : radius(r) {}
  double area() override { return 3.1416 * radius * radius; }
  double perimeter() override { return 2 * 3.1416 * radius; }
};

class Rectangle : public Shape {
  double length, width;

public:
  Rectangle(double l, double w) : length(l), width(w) {}
  double area() override { return length * width; }
  double perimeter() override { return 2 * (length + width); }
};

int main() {
  Shape *s1 = new Circle(5);
  Shape *s2 = new Rectangle(4, 6);

  cout << "Circle Area: " << s1->area() << ", Perimeter: " << s1->perimeter()
       << endl;
  cout << "Rectangle Area: " << s2->area() << ", Perimeter: " << s2->perimeter()
       << endl;

  delete s1;
  delete s2;
  return 0;
}
