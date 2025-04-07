#include <iostream>
using namespace std;

class Static {
private:
  static int count;
  int number;

public:
  void getData(int a) {
    count = a;
    number = a;
  }
  void getValue() {
    cout << "count at the very end " << count << endl;
    cout << "number at the very end " << number << endl;
  }
};

int Static::count;

int main() {
  Static s1, s2, s3;
  s1.getData(100);
  s2.getData(200);
  s3.getData(300);

  s1.getValue();
  s1.getData(100);
  s1.getValue();
  s2.getValue();
  s3.getValue();

  return 0;
}