#include <iostream>
using namespace std;

class Car {
private:
  int a = 1, b = 2;

public:
  Car();
  ~Car();
  void print();
};

Car::Car() { cout << "constructor called: " << a / b << endl; }

Car::~Car() { cout << "destructor called: " << a / b << endl; }

void Car::print() { cout << "faltu ka print \n"; }

class vehicle : public Car {
public:
  vehicle() { cout << "vehicle constructor called \n"; }
  void vehicleFunction() { cout << "vehicle function called \n"; }
  ~vehicle() { cout << "vehicle destructor called \n"; }
};

int main() {
  Car c;
  c.print();

  vehicle v;
  v.vehicleFunction();
  return 0;
}