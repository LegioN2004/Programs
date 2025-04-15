#include <iostream>
using namespace std;

class complex {
  int a = 0, b = 0;

public:
  void setValue(int v1, int v2) {
    a = v1;
    b = v2;
  }

  friend complex sumFunction(complex c1, complex c2);

  void output() { cout << a << "+" << b << "i" << endl; }
};

complex sumFunction(complex c1, complex c2) {
  complex o3;
  o3.setValue((c1.a + c2.a), (c1.b + c2.b));
  return o3;
}

int main() {
  complex c1, c2, c3;
  c1.setValue(1, 4);
  c1.output();

  c2.setValue(5, 8);
  c2.output();

  c3 = sumFunction(c1, c2);
  c3.output();
  return 0;
}