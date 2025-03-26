#include <iostream>
using namespace std;

class AddNumbers {
private:
  double num1, num2;

public:
  void SetValues(double a, double b) {
    num1 = a;
    num2 = b;
  }
  double getSum() { return num1 + num2; }
};

int main() {
  AddNumbers numb;
  double a, b;
  cout << "Enter two numbers.";
  cin >> a >> b;

  numb.SetValues(a, b);
  cout << "The sum is: " << numb.getSum() << endl;
  return 0;
}
