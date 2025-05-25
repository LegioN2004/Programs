#include <iostream>
using namespace std;

class Base {
private:
  int data1;

public:
  int data2;
  void setData();
  int getData1();
  int getData2();
};

// setting the values here
void Base::setData() {
  data1 = 12;
  data2 = 2;
}

int Base::getData1() { return data1; }

int Base::getData2() { return data2; }

// publically derived class
class Derived : private Base {
private:
  int data3;

public:
  void process();
  void display();
};

void Derived ::process() {
  setData();
  data3 = data2 * getData1();
}

void Derived ::display() {
  cout << "The value of data1 is " << getData1() << endl;
  cout << "The value of data2 is " << data2 << endl;
  cout << "The value of data3 is " << data3 << endl;
}

int main() {
  Derived d1;
  // d1.setData(); // since it is a private member function of the base class so
  // can't be accessed here. Instead we can call the process function which will
  // call the setData function.
  d1.process();
  d1.display();
  return 0;
}