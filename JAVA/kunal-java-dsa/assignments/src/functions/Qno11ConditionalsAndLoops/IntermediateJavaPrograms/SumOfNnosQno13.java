package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class SumOfNnosQno13 {
	public static void main(String[] args) {
		System.out.println("Finding the Average of N numbers");
		System.out.println("Give the numbers you want to find the avg of");
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		sum(N);
	}

	static void sum(int N) {
		double a = 0, b = 0, c = 0;
		for (int i = 1; i <= N; i++) {
			a = a + i;
		}
		System.out.println("The Average of N numbers is -> " + (a / N));
	}
}
