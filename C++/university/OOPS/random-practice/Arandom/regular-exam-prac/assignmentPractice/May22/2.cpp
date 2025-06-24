#include <iostream>
using namespace std;

class Shape {
public:
  virtual double Area() { return 0; }
};

class Rectangle : public Shape {
  int a, b;

public:
  Rectangle(int a, int b) {
    this->a = a;
    this->b = b;
  }
  double Area() override { return a * b; }
};

class Circle : public Shape {
  int a;

public:
  Circle(int a) { this->a = a; }
  double Area() override { return 3.14 * a * a; }
};

int main() {
  Rectangle r(2, 5);
  cout << r.Area() << endl;

  Circle c(2.0);
  cout << c.Area();

  Shape &shap1 = c;
  Shape &shap2 = r;

  cout << "\nCircle " << shap1.Area();
  cout << "\nRectangle " << shap2.Area();

  return 0;
}