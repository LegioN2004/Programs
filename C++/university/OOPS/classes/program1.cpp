#include <iostream>
using namespace std;

class great {
private:
  int a, b;

public:
  void big();
};

void great::big() {
  cin >> a >> b;
  if (a > b) {
    cout << "a is the greatest";
  } else {
    cout << "b is the greatest.";
  }
}

int main() {
  great A;
  A.big();
  return 0;
}
