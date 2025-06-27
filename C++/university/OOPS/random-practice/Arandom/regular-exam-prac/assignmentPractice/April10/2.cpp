#include <iostream>
using namespace std;

class Numbers {
private:
  int a;

public:
  Numbers(int a) { this->a = a; }

  int add() { return a; }
};

int main() {

  int a, b, c;
  cin >> a >> b >> c;
  Numbers r1(a), r2(b), r3(c);

  int result = r1.add();
  cout << result;

  return 0;
}
