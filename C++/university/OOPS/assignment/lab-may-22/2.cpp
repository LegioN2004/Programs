#include <iostream>
using namespace std;

class Shape {
public:
  virtual double area() { return 0; }
};

class Circle : public Shape {
  double radius;

public:
  Circle(double r) : radius(r) {}
  double area() override { return 3.14 * radius * radius; }
};

class Rectangle : public Shape {
  double width, height;

public:
  Rectangle(double w, double h) : width(w), height(h) {}
  double area() override { return width * height; }
};

int main() {
  Circle c(5.0);
  Rectangle r(4.0, 6.0);

  Shape &shape1 = c;
  Shape &shape2 = r;

  cout << "Area of Circle: " << shape1.area() << endl;
  cout << "Area of Rectangle: " << shape2.area() << endl;

  return 0;
}