#include <iostream>
using namespace std;

class Box {
public:
  int length;

  Box(int l = 0) { length = l; }

  void display() { cout << "Length: " << length << endl; }
};

void swapBoxes(Box *a, Box *b) {
  int temp = a->length;
  a->length = b->length;
  b->length = temp;
}

int main() {
  Box b1(10), b2(20);
  cout << "Before Swap:\n";
  b1.display();
  b2.display();

  swapBoxes(&b1, &b2);

  cout << "\nAfter Swap:\n";
  b1.display();
  b2.display();
  return 0;
}
