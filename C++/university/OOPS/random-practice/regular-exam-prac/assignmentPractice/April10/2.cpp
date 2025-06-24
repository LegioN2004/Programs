#include <iostream>
using namespace std;

class numbers {
private:
  int a;

public:
  numbers(int a) { this->a = a; }

  int add() { return a; }
};

int main() {

  int a, b, c;
  cin >> a >> b >> c;
  numbers r1(a), r2(b), r3(c);

  int result = r1.add(), ;

  return 0;
}
