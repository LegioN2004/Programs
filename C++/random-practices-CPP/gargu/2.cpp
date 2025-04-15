// area of a triangle
#include <iostream>
using namespace std;

float findArea(float h, float b) { return 0.5 * b * h; }
int main() {
  float h, b;
  cout << "Enter height of triangle: ";
  cin >> h;
  cout << "Enter base of triangle: ";
  cin >> b;
  cout << "The area of the traingle is" << findArea(h, b) << endl;
  if (h == b) {
    cout << "This is an equilateral triangle." << endl;
  } else if (h > b) {
    cout << "This is a right triangle." << endl;
  } else {
    cout << "This is an isosceles triangle." << endl;
  }
  return 0;
}
