/*
Create a Student class that holds name, roll number, and marks of 5 subjects.

    Use an array for marks.

    Write functions to calculate total and percentage.

    Create 3 students using an array of objects.
*/

#include <iostream>
using namespace std;

class Student {
public:
  string name;
  int rollno, marks[5];

  void getDetails(string n, int r) {
    name = n;
    rollno = r;
    // for (int i = 0; i < 5; i++) {
    //   marks[i] = m[i];
    // }
  }

  int totalMarks() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
      total += marks[i];
    }
    return total;
  }

  float Percentage() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
      total += marks[i];
    }
    return (total / 500.0) * 100;
  }

  void displayDetails() {
    cout << "Student details" << endl;
    cout << "Name: " << name << ", Roll no: " << rollno
         << ", Total marks: " << totalMarks()
         << " and percentage: " << Percentage() << endl;
  }
};

int main() {
  Student *s[3];
  for (int i = 0; i < 3; i++) {
    s[i] = new Student();
    for (int j = 0; j < 5; j++) {
      cout << "Enter the subjectwise marks";
      cin >> s[i]->marks[j];
    }
    string name;
    int rollno;
    cout << "enter the name ";
    cin >> name;
    cout << "enter the rollno ";
    cin >> rollno;
    s[i]->getDetails(name, rollno);
    s[i]->displayDetails();
  }

  return 0;
}