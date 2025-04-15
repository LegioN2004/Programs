#include <iostream>
using namespace std;

class Point {
  int x, y;

public:
  Point(int a, int b) { // constructor
    x = a;
    y = b;
  }

  void printData() {
    cout << "The point is: (" << x << ", " << y << ")" << endl;
  }
};

int main() {
  Point p(1,1);
  p.printData();
  Point q(4,6);
  q.printData();
  return 0; }