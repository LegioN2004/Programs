package com.mili;

import java.util.Scanner;

public class fibonacci {
	public static void main(String[] args) {
		System.out.println("Q3) Find the fibonacci numbers till the nth term");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a = 0, b = 1, count = 1;

		while (count < n) {
			int temp = b;
			b = b + a;
			a = temp;
			count++;
		}
		System.out.println(b);
	}
}