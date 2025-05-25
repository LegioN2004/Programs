#include <iostream>
using namespace std;

int main() {
  int num, denom, result;
  cout << "Enter the numerator and denominator: \n";
  cin >> num >> denom;

  try {
    if (denom == 0) {
      cout << "Denom can't be 0 \n";
      throw denom;
    }
    result = num / denom;
    cout << "\nThe value of the division is: " << result;
  } catch (int e) {
    cout << "exception error: " << e << '\n';
  }

  return 0;
}