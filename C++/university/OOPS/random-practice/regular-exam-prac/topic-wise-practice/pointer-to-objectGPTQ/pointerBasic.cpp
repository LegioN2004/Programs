#include<iostream>
using namespace std;

class Student {

  public:
    string name;
    int age;
    Student() {}
    Student(string n, int a): name(n), age(a){}

    void showDetails() {
      cout << "Name: " << name << "Age: " << age << endl;
    }
};


int main(){
  Student s1("hello", 12);
  s1.showDetails();
  s1.name = "hel";
  s1.age = 22;
  s1.showDetails();

  Student * ptr = &s1;
  ptr->name = "hi";
  ptr->age = 1;
  ptr->showDetails();

    return 0;
}
