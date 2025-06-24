#include <iostream>
using namespace std;

class Person {
  string name;
  int age;

public:
  Person() {}
  Person(string n, int a) : name(n), age(a) {
    cout << "Name: " << name << ", Age: " << age << endl;
  }
};
class Employee : public Person {
  string empID;
  int salary;

public:
  Employee() : Employee("ABC123", 10000) {}
  Employee(string e, int s) : Person("name", 12) {
    empID = e;
    salary = s;
    cout << "Employee ID: " << empID << ", Salary: " << salary << endl;
  }
};

int main() {
  Employee e1;
  return 0;
}