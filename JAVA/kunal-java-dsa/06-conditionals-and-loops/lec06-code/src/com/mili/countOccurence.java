package com.mili;

public class countOccurence {
	public static void main(String[] args) {
		int n = 400000;
		int count = 0;
		while(n > 0){
			int rem = n % 10; // last digit
			if (rem == 0){
				count++;
			}
			n = n / 10; // use this n /= 10 to make it shorter
		}
		System.out.println(count);
	}
}
