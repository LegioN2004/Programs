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
class Derived : public Base {
private:
  int data3;

public:
  void process();
  void display();
};

/*
 Here we have the process function which is a public member function of the
 Derived class that inherits publicly from the Base class, so it has access to
 data2 of Base(public) and it's functions so in that way Base's public functions
 can access private data1 and then those public functions are accessible by
 Derived. So this is how it works. Also make sure to modify accessibility
 according to the way it is derived
*/

void Derived ::process() { data3 = data2 * getData1(); }
void Derived ::display() {
  cout << "The value of data1 is " << getData1() << endl;
  cout << "The value of data2 is " << data2 << endl;
  cout << "The value of data3 is " << data3 << endl;
}

int main() {
  Derived d1;
  d1.setData();
  d1.process();
  d1.display();

  return 0;
}
