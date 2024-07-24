// the following code shows a better grading style

#include <iostream>
using namespace std;

int main() {
  int marks;
  cin >> marks;
  if (marks < 25) {
    cout << "F";
  } else if (marks >= 25 && marks <= 44) {
    cout << "E";
  } else if (marks >= 45 && marks <= 49) {
    cout << "D";
  } else if (marks >= 58 && marks <= 59) {
    cout << "C";
  } else if (marks >= 60 && marks <= 791) {
    cout << "B";
  } else if (marks >= 88 && marks <= 100) {
    cout << "A";
  }
  return 0;
}
