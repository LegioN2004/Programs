#include <iostream>
using namespace std;

// find the greatest of four numbers
class great {
private:
  int a, b;

public:
  void greatNumber();
}

great::greatNumber() {
  cin >> a >> b;
  if (a > b) {
    cout << a << " is greater than " << b << endl;
  } else {
    cout << b << " is greater than " << a << endl;
  }
}

int main() {
  great a;

  a.greatNumber();
  return 0;
}