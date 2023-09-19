package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

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

		// subject and their marks
		double gradePts1 = 0, gradePts2 = 0, gradePts3 = 0, gradePts4 = 0, gradePts5 = 0;
		System.out.print("Enter the name of subject and the marks obtained (consecutively pls): ");

		System.out.print("1st -> ");
		String sub1 = in.next();
		int marks1 = in.nextInt();
		if (marks1 <= 100 && marks1 >= 91) {
			System.out.println("You have got an A grade with grade points 10");
			gradePts1 = 10;
		} else if (marks1 >= 81 && marks1 <= 90) {
			System.out.println("You have got an B grade with grade points 9");
			gradePts1 = 9;
		} else if (marks1 >= 71 && marks1 <= 80) {
			System.out.println("You have got an C grade with grade points 8");
			gradePts1 = 8;
		} else if (marks1 >= 61 && marks1 <= 70) {
			System.out.println("You have got an D grade with grade points 7");
			gradePts1 = 7;
		} else if (marks1 >= 51 && marks1 <= 60) {
			System.out.println("You have got an D grade with grade points 6");
			gradePts1 = 6;
		} else {
			System.out.println("You have failed the exam so grade points will be 0");
			gradePts1 = 0;
		}
		System.out.println(
				"So the 1st subject, " + sub1 + "'s marks is: " + marks1 + " and its grade point is -> " + gradePts1);

		System.out.print("2st -> ");
		String sub2 = in.next();
		int marks2 = in.nextInt();
		if (marks2 <= 100 && marks2 >= 91) {
			System.out.println("You have got an A grade with grade points 10");
			gradePts2 = 10;
		} else if (marks2 >= 81 && marks2 <= 90) {
			System.out.println("You have got an B grade with grade points 9");
			gradePts2 = 9;
		} else if (marks2 >= 71 && marks2 <= 80) {
			System.out.println("You have got an C grade with grade points 8");
			gradePts2 = 8;
		} else if (marks2 >= 61 && marks2 <= 70) {
			System.out.println("You have got an D grade with grade points 7");
			gradePts2 = 7;
		} else if (marks2 >= 51 && marks2 <= 60) {
			System.out.println("You have got an D grade with grade points 6");
			gradePts2 = 6;
		} else {
			System.out.println("You have failed the exam so grade points will be 0");
			gradePts2 = 0;
		}
		System.out.println(
				"So the 2st subject, " + sub2 + "'s marks is: " + marks2 + " and its grade point is -> " + gradePts2);

		System.out.print("3th -> ");
		String sub3 = in.next();
		int marks3 = in.nextInt();
		if (marks3 <= 100 && marks3 >= 91) {
			System.out.println("You have got an A grade with grade points 10");
			gradePts3 = 10;
		} else if (marks3 >= 81 && marks3 <= 90) {
			System.out.println("You have got an B grade with grade points 9");
			gradePts3 = 9;
		} else if (marks3 >= 71 && marks3 <= 80) {
			System.out.println("You have got an C grade with grade points 8");
			gradePts3 = 8;
		} else if (marks3 >= 61 && marks3 <= 70) {
			System.out.println("You have got an D grade with grade points 7");
			gradePts3 = 7;
		} else if (marks3 >= 51 && marks3 <= 60) {
			System.out.println("You have got an D grade with grade points 6");
			gradePts3 = 6;
		} else {
			System.out.println("You have failed the exam so grade points will be 0");
			gradePts3 = 0;
		}
		System.out.println(
				"So the 3st subject, " + sub3 + "'s marks is: " + marks3 + " and its grade point is -> " + gradePts3);

		System.out.print("4th -> ");
		String sub4 = in.next();
		int marks4 = in.nextInt();
		if (marks4 <= 100 && marks4 >= 91) {
			System.out.println("You have got an A grade with grade points 10");
			gradePts4 = 10;
		} else if (marks4 >= 81 && marks4 <= 90) {
			System.out.println("You have got an B grade with grade points 9");
			gradePts4 = 9;
		} else if (marks4 >= 71 && marks4 <= 80) {
			System.out.println("You have got an C grade with grade points 8");
			gradePts4 = 8;
		} else if (marks4 >= 61 && marks4 <= 70) {
			System.out.println("You have got an D grade with grade points 7");
			gradePts4 = 7;
		} else if (marks4 >= 51 && marks4 <= 60) {
			System.out.println("You have got an D grade with grade points 6");
			gradePts4 = 6;
		} else {
			System.out.println("You have failed the exam so grade points will be 0");
			gradePts4 = 0;
		}
		System.out.println(
				"So the 4st subject, " + sub4 + "'s marks is: " + marks4 + " and its grade point is -> " + gradePts4);

		System.out.print("5th -> ");
		String sub5 = in.next();
		int marks5 = in.nextInt();
		if (marks5 <= 100 && marks5 >= 91) {
			System.out.println("You have got an A grade with grade points 10");
			gradePts5 = 10;
		} else if (marks5 >= 81 && marks5 <= 90) {
			System.out.println("You have got an B grade with grade points 9");
			gradePts5 = 9;
		} else if (marks5 >= 71 && marks5 <= 80) {
			System.out.println("You have got an C grade with grade points 8");
			gradePts5 = 8;
		} else if (marks5 >= 61 && marks5 <= 70) {
			System.out.println("You have got an D grade with grade points 7");
			gradePts5 = 7;
		} else if (marks5 >= 51 && marks5 <= 60) {
			System.out.println("You have got an D grade with grade points 6");
			gradePts5 = 6;
		} else {
			System.out.println("You have failed the exam so grade points will be 0");
			gradePts5 = 0;
		}
		System.out.println(
				"So the 5st subject, " + sub5 + "'s marks is: " + marks5 + " and its grade point is -> " + gradePts5);

		double cgpa = (gradePts1 + gradePts2 + gradePts3 + gradePts4 + gradePts5) / 5;
		System.out.println("The cgpa is -> " + cgpa);
	}
}
