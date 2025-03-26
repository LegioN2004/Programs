#include <iostream>
using namespace std;
class CompareNumbers {
private:
  double num1, num2;

public:
  void SetValues(double a, double b) {
    num1 = a;
    num2 = b;
  }
  double getgreater() { return (num1 > num2) ? num1 : num2; }
};
int main() {
  CompareNumbers obj;
  double a, b;
  cout << "Enter the numbers: ";
  cin >> a >> b;
  obj.SetValues(a, b);
  cout << "The greater number is: " << obj.getGreater() << endl;
  return 0;
}
