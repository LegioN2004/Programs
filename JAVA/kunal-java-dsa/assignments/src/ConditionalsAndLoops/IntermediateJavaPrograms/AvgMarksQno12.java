// TODO: extend this program to have if else statement to add as many subjects and theirs marks as desired and when the user
// presses done it auto takes the no of subjects and calculates and  gives the avg

package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class AvgMarksQno12 {
	public static void main(String[] args) {
		System.out.println("Calculating the average marks for some subjects");
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the number of subjects that you have taken: ");
		int n = in.nextInt();
		double c = 0, a = 0;
		// give the subjects for counting the average marks
		for (int i = 1; i <= n; i++) {
			System.out.print("Please enter the name of the subject -> ");
			String subj = in.next();
			System.out.print("and its marks -> ");
			float marks = in.nextFloat();
			System.out.println("Your marks for the subject " + subj + " is " + marks);
			c = c + marks;
		}
		System.out.print("Your average marks for all the subjects is: " + (c / n));
	}
}
