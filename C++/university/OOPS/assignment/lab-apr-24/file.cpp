#include <iostream>
#include <string>
using namespace std;

class person {
public:
  string name;
  int age;

  person(string n, int a) : name(n), age(a) {}

  void showDetails() {
    cout << "The name is " << name << " and age is " << age << endl;
  }
};

class student : public person {
public:
  string roll, course;

  student(string n, int a, string r, string c)
      : person(n, a), roll(r), course(c) {}

  void showDetails() {
    person::showDetails();
    cout << "Course is " << course << endl;
    cout << "Roll is " << roll << endl;
  }
};

int main() {
  person p1("milinda", 21);
  cout << "Person details: ";
  p1.showDetails();

  student s1("milinda", 21, "cse-23-41", "CSE");
  cout << "Student details: ";
  s1.showDetails();

  return 0;
}
