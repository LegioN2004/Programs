#include <iostream>
using namespace std;

int main() {

  int num, denom, result;
  cout << "enter numerator and denominator" << endl;
  cin >> num >> denom;

  // we know that the exception will happen here so we'll add the try catch here

  try {
    if (denom == 0) {
      throw denom;
    }
    result = num / denom;
  } catch (int ex) {
    cout << "\nDivide by zero not allowed -> " << ex << endl;
  }
  cout << "division is: " << result << endl;
  return 0;
}