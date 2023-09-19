package functions.Qno11FlowOfPrograms;

import java.util.Scanner;

import javax.sound.sampled.SourceDataLine;

public class Qno3 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("enter the number: ");
		int a = in.nextInt();
		System.out.print("enter the no of times you want to show the multiplication table for the number: ");
		int b = in.nextInt();
		sum(a, b);
	}

	static void sum(int a, int b) {
		int c = 0;
		for (int i = 1; i <= b; i++) {
			c = i * a;
			System.out.println(a + " * " + i + " = " + c);
		}
	}
}
