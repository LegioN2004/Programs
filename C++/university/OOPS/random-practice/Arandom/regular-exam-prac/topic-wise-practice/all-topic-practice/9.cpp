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

class Student : public Person {
  int rollno;
  string Class;

public:
  Student() {}
  Student(int r, string c) : Person("name", 12) {
    rollno = r;
    Class = c;
    cout << "Roll no: " << rollno << ", Class: " << Class << endl;
  }
};

class GraduateStudent : public Student {
  string Branch;

public:
  GraduateStudent() : GraduateStudent("CSE") {}
  GraduateStudent(string b) : Student(123, "class 1") {
    Branch = b;
    cout << "Branch: " << Branch << endl;
  }
  // GraduateStudent(string name, int age, int rollno, string Class, string Branch){}
};

int main() {
  GraduateStudent g1;
  return 0;
}