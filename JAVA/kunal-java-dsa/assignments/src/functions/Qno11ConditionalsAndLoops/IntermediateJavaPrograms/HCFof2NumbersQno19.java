package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class HCFof2NumbersQno19 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Print the two numbers to find the HCF of: ");
		int a = in.nextInt(), b = in.nextInt(), hcf = 0;
		hcf(a, b, hcf);
	}

	static void hcf(int a, int b, int hcf) {
		for (int i = 1; i <= a || i <= b; i++) {
			if (a % i == 0 && b % i == 0) {
				hcf = i; // if statement inside of the for loop works because the for loop runs from low
							// to highest no
				// as per the condition and since we need the highest common factor so the hcf
				// automatically gets
				// stored in the i and then to the hcf variable and then the output outside of
				// the for loop is the HCF
			}
		}
		System.out.println("the required HCF is -> " + hcf);
	}
}
