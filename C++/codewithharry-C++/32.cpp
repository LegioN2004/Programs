#include <iostream>
using namespace std;

class Simple {
private:
  int data1, data2;

public:
  // this is a default constructor, Why? Just like default values in the
  // functions, we can provide default values in the constructor that will take
  // this value when we don't give any value as well and this creates a default
  // constructor
  Simple(int a = 0, int b = 0) {
    data1 = a;
    data2 = b;
  }

  void printData();
};

void Simple::printData() {
  // cout << "The value of data1 is: " << data1 << endl;
  // cout << "The value of data2 is: " << data2 << endl;
  // we can do this also
  cout << "The value of data1 and data2 is: " << data1 << " & " << data2
       << endl;
}

int main() {
  Simple s1(4, 5);
  s1.printData();

  Simple s2(2);
  s2.printData();

  Simple s3;
  s3.printData();

  return 0;
}