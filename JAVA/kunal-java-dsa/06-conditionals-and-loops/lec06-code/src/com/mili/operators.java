package com.mili;

public class operators {
	public static void main(String[] args) {
		System.out.println("operators");

		System.out.println("-------- 1.Logical AND '&&' operator --------");
		int a = 10, b = 20;
		if (a == 10 && b == 20) {
			System.out.println("true"); // it'll print true if both the condtions are true
		} else {
			System.out.println("false");
		}

		System.out.println("-------- 2.Logical OR '||' operator --------");
		int c = 10, d = 40;
		if (c == 10 || d == 20) {
			System.out.println("true"); // it'll print true if any one of the condtions are true
		} else {
			System.out.println("false");
		}

		System.out.println("-------- 1.relational NOT equal to '!=' operator --------");
		int e = 10, f = 40;
		if (e != 50) {
			System.out.println("true"); // it'll print true if any one of the condtions are true
		} else {
			System.out.println("false");
		}
	}
}
