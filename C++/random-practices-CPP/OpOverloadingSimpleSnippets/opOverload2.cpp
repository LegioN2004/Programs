// unary operator overloading
#include <iostream>
using namespace std;

class Weight {
private:
  int kg;

public:
  Weight() { kg = 0; }
  Weight(int k) { kg = k; }

  /*
  we didn't pass any arguments to the operator++ function, as it is a pre and
  post increment operator i.e a unary operator so it operates directly on the
  object itself. Doing w1++ means w1.operator++(0) which is the post increment
  operator, same for the pre increment op bts.
  */

  void operator++() { ++kg; }
  // for the post increment operator, you'll need to pass in the int type so
  // that the compiler knows that the post increment operator is being used.
  // This is a convention in C++ to differentiate between the pre-increment and
  // post-increment operators.
  void operator++(int) { kg++; }
  void operator--() { --kg; }
  void operator--(int) { kg--; }
  void print() { cout << kg << " kg" << endl; }
};

int main() {
  Weight w1;
  w1.print();
  ++w1;
  w1.print();
  w1++;
  w1.print();
  --w1;
  w1.print();
  w1--;
  w1.print();

  return 0;
}