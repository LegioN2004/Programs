package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

// this is too big to be converted to functions from the simple if else statements, pretty mendoksaiiiiiiiiiiii

public class CalcCGPAQno10 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("CGPA calculator for 5 subjects");
		// made the 5 subject one with simple i/o statements after getting frustrated by
		// the boilerplate and big chunks of code for some small logic if
		// else statements included inside of some switch case statements, see the
		// failed on in MissionFailed package
		// we'll get 'em next time

		// name
		System.out.print("Enter your name: ");
		String name = in.next();
		System.out.println("Calculating CGPA for the student: " + name);

		System.out.println("Print the marks and subject for which the marks is being provided");
		float marks = in.nextFloat();

		// subject and their marks
		double cgpa = cgpa(name, marks) / 5;
		System.out.println("The cgpa is -> " + cgpa);
	}

	static double cgpa(String sub1, double marks) {
		// subject and their marks
		double gradePts = 0;
		System.out.print("Enter the name of subject and the marks obtained (consecutively pls): ");

		System.out.print("1st -> ");
		if (marks <= 100 && marks >= 91) {
			System.out.println("You have got an A grade with grade points 10");
			gradePts = 10;
		} else if (marks >= 81 && marks <= 90) {
			System.out.println("You have got an B grade with grade points 9");
			gradePts = 9;
		} else if (marks >= 71 && marks <= 80) {
			System.out.println("You have got an C grade with grade points 8");
			gradePts = 8;
		} else if (marks >= 61 && marks <= 70) {
			System.out.println("You have got an D grade with grade points 7");
			gradePts = 7;
		} else if (marks >= 51 && marks <= 60) {
			System.out.println("You have got an D grade with grade points 6");
			gradePts = 6;
		} else {
			System.out.println("You have failed the exam so grade points will be 0");
			gradePts = 0;
		}
		System.out.println(
				"So the 1st subject, " + sub1 + "'s marks is: " + marks + " and its grade point is -> " + gradePts);
	}
}
