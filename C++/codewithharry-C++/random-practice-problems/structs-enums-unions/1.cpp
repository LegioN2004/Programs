#include <iostream>
using namespace std;

struct Rectangle {
  int length;
  int breadth;
};

// int Area(int a, int b) { return a * b; }
int Area(Rectangle a) { return a.length * a.breadth; }

int main() {
  Rectangle rectangle = {10, 10};
  // or we can do this as well
  //   rectangle.length = 10;
  //   rectangle.breadth = 10;

  //   cout << "Area is: " << Area(rectangle.length, rectangle.breadth) << endl;
  //   // directly value is passed here and in the next example an instance of
  //   the struct is being passed with a name and the input is also taken as an
  //   instance
  cout << "Area is: " << Area(rectangle) << endl;
  return 0;
}
