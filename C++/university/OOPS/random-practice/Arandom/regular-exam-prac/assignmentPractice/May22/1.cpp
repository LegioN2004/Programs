#include <iostream>
using namespace std;

class Calculator {
public:
  int intCalc(int a, int b) { return a + b; }

  float floatCalc(float a, float b) { return a + b; }

  double doubleCalc(double a, double b) { return a + b; }
};

int main() {

  Calculator a;
  cout << a.intCalc(1, 2) << endl;
  cout << a.floatCalc(1.2, 2.1) << endl;
  cout << a.doubleCalc(1.22222222, 2.1111111111) << endl;
  return 0;
}
