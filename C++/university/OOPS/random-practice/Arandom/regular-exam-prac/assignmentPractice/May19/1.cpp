#include <iostream>
using namespace std;

int main() {

  int a = 1, divisor = 0, division = 0;

  try {

    if (divisor == 0) {
      throw divisor;
    }

    division = a / divisor;
  } catch (int ex) {
    cout << "Some exception occured " << ex << " is not allowed";
  }

  cout << division << " results";

  return 0;
}