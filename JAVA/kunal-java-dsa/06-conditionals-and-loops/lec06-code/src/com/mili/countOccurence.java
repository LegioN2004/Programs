package com.mili;

public class countOccurence {
	public static void main(String[] args) {
		int n = 13857597;
		int c = 0;
		for (int i = 0; i <= 10; i++) {
			c = n % 10;
			n = n / 10;
			if (c == 7) {
				System.out.println("This is an occurence of 7");
			}
		}
	}
}
