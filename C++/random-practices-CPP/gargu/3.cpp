// area of the circle

#include <iostream>
using namespace std;
float findArea(float r) {
  return 3.14 * r * r;
}
int main() {
  float r;
  cout << "Enter radius of circle: ";
  cin >> r;
  if (r <= 0) {
    cout << "Radius must be a positive number." << endl;
    return 1;
  }
  cout << "Area of the circle: " << findArea(r);
  return 0;
}