package com.mili;

import java.util.Scanner;

public class StringExample {
	public static void main(String[] args) {
		// String a = greet();
		// System.out.println(a);

		Scanner in = new Scanner(System.in);
		System.out.println("Enter your name ");
		String name = in.next();
		String personalized = myGreet(name);
		System.out.println(personalized);
	}

	static String myGreet(String name) {
		String message = "Hello, " + name;
		return message;
	}

	static String greet() {
		String greet = "This is a string";
		return greet;
	}
}
