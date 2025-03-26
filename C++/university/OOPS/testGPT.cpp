#include <iostream>
using namespace std;

class Student {
private:
  int rollNumber;
  string name;
  int marks[5];
  int totalMarks;
  float averageMarks;

  void calculateTotalAndAverage() {
    totalMarks = 0;
    for (int i = 0; i < 5; i++) {
      totalMarks += marks[i];
    }
    averageMarks = totalMarks / 5.0;
  }

public:
  void inputDetails() {
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter marks for 5 subjects: ";
    for (int i = 0; i < 5; i++) {
      cin >> marks[i];
      while (marks[i] < 0 || marks[i] > 100) { // Input validation
        cout << "Invalid marks! Enter again (0-100): ";
        cin >> marks[i];
      }
    }
    calculateTotalAndAverage();
  }

  void displayDetails() const {
    cout << "Roll Number: " << rollNumber << "\n";
    cout << "Name: " << name << "\n";
    cout << "Total Marks: " << totalMarks << "\n";
    cout << "Average Marks: " << averageMarks << "\n";
  }

  bool compareMarks(const Student &other) {
    return totalMarks > other.totalMarks;
  }

  int getTotalMarks() { return totalMarks; }

  static int findTopper(Student arr[], int size) {
    int topperIndex = 0;
    for (int i = 1; i < size; i++) {
      if (arr[i].getTotalMarks() > arr[topperIndex].getTotalMarks()) {
        topperIndex = i;
      }
    }
    return topperIndex;
  }
};

class Classroom {
private:
  Student students[100];
  int studentCount;

public:
  Classroom() : studentCount(0) {}

  void addStudent() {
    if (studentCount < 100) {
      students[studentCount].inputDetails();
      studentCount++;
    } else {
      cout << "Classroom is full!\n";
    }
  }

  void displayAllStudents() {
    for (int i = 0; i < studentCount; i++) {
      students[i].displayDetails();
      cout << "\n";
    }
  }

  void findHighestScorer() {
    if (studentCount == 0) {
      cout << "No students in the class.\n";
      return;
    }
    int topperIndex = Student::findTopper(students, studentCount);
    cout << "Topper Details:\n";
    students[topperIndex].displayDetails();
  }
};

int main() {
  Classroom classroom;
  int choice;

  do {
    cout << "\n1. Add Student\n2. Display All Students\n3. Find Topper\n4. "
            "Exit\nEnter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      classroom.addStudent();
      break;
    case 2:
      classroom.displayAllStudents();
      break;
    case 3:
      classroom.findHighestScorer();
      break;
    case 4:
      cout << "Exit...\n";
      break;
    default:
      cout << "Invalid choice! Try again.\n";
    }
  } while (choice != 4);

  return 0;
}
