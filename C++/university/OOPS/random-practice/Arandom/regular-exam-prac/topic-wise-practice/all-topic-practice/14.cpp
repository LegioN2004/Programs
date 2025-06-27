#include <iostream>
using namespace std;

class Shape {
public:
  virtual void draw() { cout << "Drawing shape\n"; }
};

class Circle : public Shape {
public:
  void draw() override { cout << "Drawing Circle\n"; }
};

class Rectangle : public Shape {
public:
  void draw() override { cout << "Drawing Rectangle\n"; }
};

int main() {
  Shape *shapes[2];
  shapes[0] = new Circle();
  shapes[1] = new Rectangle();

  for (int i = 0; i < 2; i++) {
    shapes[i]->draw(); // Runtime polymorphism
    delete shapes[i];  // Prevent memory leak
  }

  return 0;
}
