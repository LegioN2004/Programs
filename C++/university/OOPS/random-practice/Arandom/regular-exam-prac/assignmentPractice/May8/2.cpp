#include <iostream>
using namespace std;

class person {

public:
  person(string name, int age) { cout << "enter the name and age: " << name; }
};

class Employee {
public:
  Employee(int salary) { cout << "\nenter the salary: " << salary; }
};

class Manager : public person, public Employee {
public:
  Manager(string name, int age, int salary) {}

  void showDetails() {
    cout << "\nname: " << name << endl;
    cout << "age: " << age << endl;
    cout << "salary: " << salary << endl;
  }
};

int main() {
  Manager m("name", 12, 1000000);
  return 0;
}