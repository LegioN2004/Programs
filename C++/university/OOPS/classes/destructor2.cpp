#include <iostream>
using namespace std;

class Vehicle {
public:
  // first vehicle run hoise
  Vehicle() { cout << "Vehicle constructor\n"; }
  ~Vehicle() { cout << "Vehicle destructor\n"; }
};

class SportsCar : public Vehicle {
  // then SportsCar public inherit korise so it's constructor will run
public:
  SportsCar() { cout << "SportsCar constructor\n"; }
  ~SportsCar() { cout << "SportsCar destructor\n"; }
};

int main() {
  cout << "Constructor will be created now" << endl;
  SportsCar mySportsCar;
  cout << "Destructor will be executed now" << endl;
  return 0;
}
