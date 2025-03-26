#include <iostream>
using namespace std;

class Rectangle {
private:
  int length = 0, width = 0;

public:
  int returnArea();
  void getValue();
};

void Rectangle::getValue() {
  int a, b;
  cout << "Enter the length and width in order";
  cin >> a >> b;
  length = a, width = b;
}

int Rectangle::returnArea() { return length * width; }

int main() {
  Rectangle first;
  first.getValue();
  cout << "The area is " << first.returnArea();
  return 0;
}
