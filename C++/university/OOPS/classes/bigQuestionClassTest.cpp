/*

You are tasked with developing a Student Management and Performance Analysis
System using C++ that effectively demonstrates object-oriented programming
principles, data encapsulation, and nested functions while handling multiple
student records. The system should define a student class with private data
members, including rollNumber, name, marks (an array for five subjects),
totalMarks, and averageMarks. It should also include various member functions
such as inputDetails(), which gathers student/data: calculateTotálAndAverage(),
a nested function to compute total and average marks: displayDetails(), which
prints student information; compareMarks(Student other), which allows comparison
between student objects, and a static function findTopper(Student arr[], int
size) which identifies the student with the highest marks.

Additionally, a separate Classroom class should be implemented to manage
multiple students efficiently. This class should contain an array of Student
objects and methods such as addstudent() for adding students.
displayAllstudents() for displaying all stored records, and getTopper() to
determine the highest-scoring student. The main() function should facilitate
user interaction by allowing the input of student data, storing multiple student
records within a Classroom obiect, displaying all student details, and
identifying the topper. The program should enforce encapsulation, ensuring
private data members are accessed only through public methods, and implement
object comparison techniques for ranking students based on performance.

The system should handle user input validation to ensure marks fall within the
valid range of 0-100. It should also demonstrate proper array handling within a
class and make use of nested functions for improved modularity. Additional
features such as operator overloading for student omparisons, file handling for
data persistence, and an automated grading system based on average marks can
further increase the complexity and utility of the program. By implementing
these elements, the system will serve as a comprehensive demonstration of key
C++ concepts while providing a robust solution for managing and analyzing
student performance.
*/


#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[5];
    float totalMarks;
    float averageMarks;

    // Private nested function (helper function)
    float calculateSum() {
        float sum = 0;
        for (int i = 0; i < 5; i++) {
            sum = sum + marks[i];
        }
        return sum;
    }

    // Private helper method for grading
    string getGrade() {
        if (averageMarks >= 90)
            return "A+";
        else if (averageMarks >= 80)
            return "A";
        else if (averageMarks >= 70)
            return "B";
        else if (averageMarks >= 60)
            return "C";
        else if (averageMarks >= 50)
            return "D";
        else
            return "F";
    }

public:
    // Default constructor
    Student() {
        rollNumber = 0;
        name = "";
        totalMarks = 0;
        averageMarks = 0;
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;
        }
    }

    // Parameterized constructor
    Student(int roll, string n) {
        rollNumber = roll;
        name = n;
        totalMarks = 0;
        averageMarks = 0;
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;
        }
    }

    // Input student details
    void inputDetails() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // Clear input buffer

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter marks for 5 subjects (0-100):\n";
        for (int i = 0; i < 5; i++) {
            do {
                cout << "Subject " << (i + 1) << ": ";
                cin >> marks[i];
                if (marks[i] < 0 || marks[i] > 100) {
                    cout << "Invalid marks! Please enter marks between 0-100.\n";
                }
            } while (marks[i] < 0 || marks[i] > 100);
        }

        calculateTotalAndAverage();
    }

    // Calculate total and average marks using nested function
    void calculateTotalAndAverage() {
        totalMarks = calculateSum(); // Calling the private nested function
        averageMarks = totalMarks / 5.0;
    }

    // Display student details
    void displayDetails() {
        cout << "\n--------------------------------------------------\n";
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nTotal Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
        cout << "Grade: " << getGrade() << endl;
        cout << "--------------------------------------------------\n";
    }

    // Compare marks with another student
    int compareMarks(Student other) {
        if (this->totalMarks > other.totalMarks)
            return 1;
        else if (this->totalMarks < other.totalMarks)
            return -1;
        else
            return 0;
    }

    // Static function to find topper from array of students
    static Student findTopper(Student arr[], int size) {
        if (size <= 0) {
            Student empty;
            return empty;
        }

        Student topper = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i].compareMarks(topper) > 0) {
                topper = arr[i];
            }
        }
        return topper;
    }

    // Getter methods for encapsulation
    int getRollNumber() { return rollNumber; }
    string getName() { return name; }
    float getTotalMarks() { return totalMarks; }
    float getAverageMarks() { return averageMarks; }
};

class Classroom {
private:
    Student students[100]; // Array to store students
    int studentCount;

public:
    // Constructor
    Classroom() {
        studentCount = 0;
    }

    // Add a student to the classroom
    void addStudent() {
        if (studentCount >= 100) {
            cout << "Classroom is full! Cannot add more students.\n";
            return;
        }

        cout << "\n=== Adding Student " << (studentCount + 1) << " ===";
        students[studentCount].inputDetails();
        studentCount++;
        cout << "Student added successfully!\n";
    }

    // Display all students
    void displayAllStudents() {
        if (studentCount == 0) {
            cout << "No students in the classroom.\n";
            return;
        }

        cout << "\n=== ALL STUDENTS IN CLASSROOM ===\n";
        for (int i = 0; i < studentCount; i++) {
            cout << "\nStudent " << (i + 1) << ":";
            students[i].displayDetails();
        }
    }

    // Get the topper of the classroom
    void getTopper() {
        if (studentCount == 0) {
            cout << "No students in the classroom.\n";
            return;
        }

        Student topper = Student::findTopper(students, studentCount);
        cout << "\n=== CLASS TOPPER ===";
        topper.displayDetails();
    }

    // Get student count
    int getStudentCount() { return studentCount; }

    // Performance analysis
    void performanceAnalysis() {
        if (studentCount == 0) {
            cout << "No students for analysis.\n";
            return;
        }

        float totalClassAverage = 0;
        int gradeCount[6] = {0, 0, 0, 0, 0, 0}; // A+, A, B, C, D, F

        for (int i = 0; i < studentCount; i++) {
            totalClassAverage = totalClassAverage + students[i].getAverageMarks();

            // Count grades
            float avg = students[i].getAverageMarks();
            if (avg >= 90)
                gradeCount[0]++;
            else if (avg >= 80)
                gradeCount[1]++;
            else if (avg >= 70)
                gradeCount[2]++;
            else if (avg >= 60)
                gradeCount[3]++;
            else if (avg >= 50)
                gradeCount[4]++;
            else
                gradeCount[5]++;
        }

        totalClassAverage = totalClassAverage / studentCount;

        cout << "\n=== PERFORMANCE ANALYSIS ===\n";
        cout << "Total Students: " << studentCount << endl;
        cout << "Class Average: " << totalClassAverage << endl;
        cout << "\nGrade Distribution:\n";
        cout << "A+: " << gradeCount[0] << " students\n";
        cout << "A:  " << gradeCount[1] << " students\n";
        cout << "B:  " << gradeCount[2] << " students\n";
        cout << "C:  " << gradeCount[3] << " students\n";
        cout << "D:  " << gradeCount[4] << " students\n";
        cout << "F:  " << gradeCount[5] << " students\n";
    }
};

// Function to display menu
void displayMenu() {
    cout << "\n=== STUDENT MANAGEMENT SYSTEM ===\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Find Class Topper\n";
    cout << "4. Performance Analysis\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Classroom classroom;
    int choice;

    cout << "Welcome to Student Management and Performance Analysis System!\n";

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            classroom.addStudent();
            break;

        case 2:
            classroom.displayAllStudents();
            break;

        case 3:
            classroom.getTopper();
            break;

        case 4:
            classroom.performanceAnalysis();
            break;

        case 5:
            cout << "Thank you for using the Student Management System!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

        if (choice != 5) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 5);

    return 0;
}