/*
Java program to create a class Student with the following data members: rollNo, name, and marks in three subjects. The program should:
Accept the student details from the user.
Calculate the total marks and percentage.
Determine the grade according to the following criteria:
Percentage ≥ 90: Grade A+
Percentage ≥ 80: Grade A
Percentage ≥ 70: Grade B
Percentage ≥ 60: Grade C
Percentage ≥ 50: Grade D
Percentage < 50: Grade F
Display all student details along with total marks, percentage, and grade.
*/

// total marks 100

import java.util.Scanner;

class Student {
    int total;

    Student (int total) {
        this.total = total;
    }

    void percentage() {
        float val = (total / 300f) * 100;
        System.out.println("percentage is: " + val);
        System.out.println(total);

        if (val >= 90) {
            System.out.println("Grade A+");
        } else if (val >= 80) {
            System.out.println("Grade A");
        } else if (val >= 70) {
            System.out.println("Grade B");
        } else if (val >= 60) {
            System.out.println("Grade C");
        } else if (val >= 50) {
            System.out.println("Grade D");
        } else if (val < 50) {
            System.out.println("Grade F");
        }
    }
}

public class StudentJava {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int rollno, marks1, marks2, marks3;
        String name;

        System.out.println("name: ");
        name = in.next();

        System.out.println("roll no: ");
        rollno = in.nextInt();

        System.out.println("Enter the marks: ");
        marks1 = in.nextInt();
        marks2 = in.nextInt();
        marks3 = in.nextInt();

        int marks = marks1 + marks2 + marks3;
        Student obj = new Student(marks);
    }
}