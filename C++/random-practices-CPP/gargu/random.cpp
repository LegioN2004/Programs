#include <iostream>
using namespace std;
class Box {
private:
  float length;
  float breadth;
  float height;

public:
  Box(float l, float b, float h) {
    length = l;
    breadth = b;
    height = h;
  }
  friend void Volume(Box b);
};

void Volume(Box b) {
  float vol = b.length * b.breadth * b.height;
  cout << "The volume is: " << vol << endl;
}
int main() {
  Box b1(12.6, 9.2, 3.4);
  Volume(b1);
  return 0;
}