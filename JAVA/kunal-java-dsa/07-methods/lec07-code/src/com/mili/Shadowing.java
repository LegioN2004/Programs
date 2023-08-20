package com.mili;

public class Shadowing {
	static int x = 90; // this will be shadowed when we print it the next time in *2

	public static void main(String[] args) {
		System.out.println(x); // 1 // prints 90
		// int x = 40; // the class variable at line 4 is shadowed by this, after this line whatever you do with x will modify it within this scope
		int x;
		// System.out.println(x); // this line shows error that 'x might not have been initialized'
		// i.e scope will begin only when value is initialized.
		x = 40;
		System.out.println(x); // 2 // prints 40
		// this is called shadowing, the lower level is overriding the upper level
		fun();
	}
	// int x; = declaring a variable or declaring in short
	// x = 90; initializing a value or initializing in short

	static void fun(){
		System.out.println(x); // no error till here
	}
}
