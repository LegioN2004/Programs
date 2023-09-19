package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class FutureInvestmentValueQno18 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Print the present value: ");
		double a = in.nextInt();
		System.out.print("Print the interest paid by the investment: ");
		double b = in.nextInt();
		System.out.print("Print the time in years the investment is held: ");
		double c = in.nextInt();
		future(a, b, c);
	}

	static void future(double a, double b, double c) {
		double d = a * Math.pow((1 + b / 100), c);
		System.out.println("The future investment value is: " + d);
	}
}
