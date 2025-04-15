// area of a rectangle
#include <iostream>
using namespace std;

float findArea(float length, float width) {
  return length * width;
}
int main() {
  float length, width;
  cout << "Enter length of rectangle: ";
  cin >> length;
  cout << "Enter width of rectangle: ";
  cin >> width;
  if (length <= 0 || width <= 0) {
    cout << "Length and width must be positive numbers." << endl;
    return 1;
  }
  if (length == width) {
    cout << "This is a square." << endl;
  } else {
    cout << "This is a rectangle." << endl;
  }
  cout << "Area of the rectangle: " << findArea(length, width);
  return 0;
}