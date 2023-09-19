package functions.Qno11FlowOfPrograms;

import java.util.Scanner;

public class Qno4 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("enter two numbers: ");
		int a = in.nextInt();
		int b = in.nextInt();
		hcf(a, b);
		lcm(a, b);
	}

	static void hcf(int a, int b) {
		int c = 0, d = 0;
		for (int i = 1; i <= a; i++) {
			if (a % i == 0) {
				c = i;
			}
			for (int j = 1; j <= b; j++) {
				if (b % j == 0) {
					d = j;
				}
			}
		}
		if (d == c) {
			System.out.println("The hcf is: " + d);
		} else {
			System.out.println("Enter the correct number");
		}
	}

	static void lcm(int a, int b) {
		int lcm = 0;
		if (a > b) {
			lcm = a;
		} else {
			lcm = b;
		}
		while (true) {
			if (lcm % a == 0 && lcm % b == 0) {
				System.out.println("lcm of entered numbers is: " + lcm);
				break;
			}
			++lcm;
		}
	}
}
