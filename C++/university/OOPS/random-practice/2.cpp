#include <iostream>
using std::cin, std::cout, std::string, std::endl;

class Student {
private:
  string name;
  int rollno, marks[5];

public:
  int total = 0;
  void inputDetails();
  void calculateMarks();
  void displayDetails();
};

void Student::inputDetails() {
  cout << "Enter the name\n";
  cin >> name;

  cout << "Enter the rollno\n";
  cin >> rollno;

  cout << "Enter the marks\n";
  for (int i = 0; i < 5; i++) {
    cin >> marks[i];
  }
}

void Student::calculateMarks() {
  for (int i = 0; i < 5; i++) {
    total += marks[i];
  }
}

void Student::displayDetails() {
  cout << "The student's name is " << name << " and roll no is " << rollno
       << " and their marks are as follows\n";

  cout << "Total is: " << total << endl;

  cout << "Average is: " << total / 5;
}

int main() {
  Student a;
  a.inputDetails();
  a.calculateMarks();
  a.displayDetails();
  return 0;
}