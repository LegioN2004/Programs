#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void getPersonDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
};

class Employee {
protected:
    long double salary;
public:
    void getEmployeeDetails() {
        cout << "Enter salary: ";
        cin >> salary;
    }
};

class Manager : public Person, public Employee {
public:
    void displayDetails() {
        cout << "\n--- Manager Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Manager m;
    m.getPersonDetails();
    m.getEmployeeDetails();
    m.displayDetails();
    return 0;
}