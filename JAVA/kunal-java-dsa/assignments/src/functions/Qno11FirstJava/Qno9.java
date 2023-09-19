package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno8 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter two numbers: ");
		int a = in.nextInt(), i = 0, orig = a, c = 0;
		for (i = 1; i <= a; i++) {
			c = a % 10;
			a = a / 10;
		}
		armstrong(orig, i);
		// armstrong(orig);
		// if (armstrong(a, b)) {
		// System.out.println(" no is armstrong ");
		// } else {
		// System.out.println(" no is not armstrong ");
		// }
	}

	static void armstrong(double a, double b) {
		// finding the no of digits
		double c = 0, d = 0;
		while (a > 0) {
			c = a % 10;
			d = Math.pow(c, b) + d;
			a = a / 10;
		}
		System.out.println(d);
	}
}
