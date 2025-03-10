#include <iostream>
using namespace std;

enum ShapeType { Triangle, Cube, Circle };

int main() {
  ShapeType myShape = Triangle;
  cout << "Selected shape: " << myShape
       << endl;  // Output: 2 (because Circle is the third element)
  return 0;
}
