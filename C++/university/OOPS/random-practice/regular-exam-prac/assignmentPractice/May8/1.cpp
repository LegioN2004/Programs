#include <iostream>
using namespace std;

class person {
protected:
  string name;
  int age;

public:
  void sendDetails() {
    cout << "enter the name and age";
    cin >> name >> age;
  }
};

class Employee {
protected:
  int salary;

public:
  void sendDetails() {
    cout << "\nenter the salary";
    cin >> salary;
  }
};

class Manager : public person, public Employee {
public:
  void inputDetails(){
    person::sendDetails();
    Employee::sendDetails();
  }

  void showDetails() {
    cout << "\nname: " << name << endl;
    cout << "age: " << age << endl;
    cout << "salary: " << salary << endl;
  }
};

int main() {
  Manager m;
  m.inputDetails();
  m.showDetails();
  return 0;
}