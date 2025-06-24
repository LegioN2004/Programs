#include <iostream>
using namespace std;

class Vehicle {
protected:
  string fuel;

public:
  Vehicle() : fuel("nothing") {}
  virtual void fuelType() { cout << "Fuel Type: " << fuel << endl; }
};

class Bus : public Vehicle {
public:
  Bus() { fuel = "Diesel"; }
  void fuelType() override { cout << "Fuel Type: " << fuel << endl; }
};

class Bike : public Vehicle {
public:
  Bike() { fuel = "Petrol"; }
  void fuelType() override { cout << "Fuel Type: " << fuel << endl; }
};

class Car : public Vehicle {
public:
  Car() { fuel = "Octane"; }
  void fuelType() override { cout << "Fuel Type: " << fuel << endl; }
};

int main() {
  Bus bus;
  bus.fuelType();

  Bike bike;
  bike.fuelType();

  Car car;
  car.fuelType();

  Vehicle *v;
  v = &bus;
  v->fuelType();

  v = &bike;
  v->fuelType();

  v = &car;
  v->fuelType();


  return 0;
}