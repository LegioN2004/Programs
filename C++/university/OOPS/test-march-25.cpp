#include <iostream>
using namespace std;

class student {
private:
  int rollNumber, marks[5], totalMarks;
  float averageMarks;
  string name;

  void calculateTotalAndAverageMarks() {
    totalMarks = 0;
    for (int i = 0; i < 5; i++) {
      totalMarks += marks[i];
    }
    averageMarks = totalMarks / 5;
  }

public:
  void inputDetails() {
    cout << "enter the name, roll number: ";
    cin >> name >> rollNumber;
    cout << "enter the marks of 5 subjects: ";
    for (int i = 0; i < 5; i++) {
      if (marks[i] >= 0 && marks[i] <= 100) {
        cin >> marks[i];
      } else {
        cout << "Marks is out of bounds \n";
      }
    }
    calculateTotalAndAverageMarks();
  }

  void displayDetails() {
    cout << "The name of the student is " << name << endl;
    cout << "The roll number of the student is " << rollNumber << endl;
    cout << "The total marks of the student is " << totalMarks << endl;
    cout << "The average marks of the student is " << averageMarks << endl;
  }

  static int findTopper(student arr[], int size) {
    int topper = 0;
    for (int i = 0; i < size; i++) {
      if (arr[i].totalMarks > arr[topper].totalMarks) {
        topper = i;
      }
    }
    return topper;
  }
};

class Classroom {
private:
  student Students[100];
  int count = 0;

public:
  void addStudent() {
    if (count <= 99) {
      Students[count].inputDetails();
      count++;
    } else {
      cout << "Classroom is full";
    }
  };

  void displayAllStudents() {
    for (int i = 0; i < count; i++) {
      Students[i].displayDetails();
      cout << endl;
    }
  };

  void getTopper() {
    int topper = 0;
    if (count == 0) {
      cout << "No students in the class.\n";
      return;
    }

    int topperIndex = student::findTopper(Students, count);
    Students[topperIndex].displayDetails();

    // for (int i = 0; i < 5; i++) {
    //   Students[i].calculateTotalAndAverageMarks();
    //   if (topper > Students[i].totalMarks) {
    //     topper = i;
    //   }
    // }
  };
};

int main() {
  Classroom classroom;

  int choice = 0;

  do {

    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Find Topper\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      classroom.addStudent();
      cout << endl;
      break;

    case 2:
      classroom.displayAllStudents();
      cout << endl;
      break;

    case 3: {
      classroom.getTopper();
      cout << endl;
    } break;

    case 4:
      cout << "exit\n";
      break;

    default:
      cout << "Invalid choice, try again\n";
      break;
    }
  } while (choice != 4);

  return 0;
}