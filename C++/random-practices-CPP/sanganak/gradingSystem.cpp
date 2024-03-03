#include <iostream>
using namespace std;

int main() {
  int a;
  cout << "enter the input ";
  cin >> a;
  if (a < 25) {
    cout << "your grade is F";
  } else if (a >= 25 && a <= 44) {
    cout << "your grade is E";
  } else if (a >= 45 && a <= 49) {
    cout << "your grade is D";
  } else if (a >= 50 && a <= 59) {
    cout << "your grade is C";
  } else if (a >= 60 && a <= 79) {
    cout << "your grade is B";
  } else if (a >= 80 && a <= 100) {
    cout << "your grade is A";
  } else {
    cout << "your input is wrong type again";
  }
  return 0;
}
