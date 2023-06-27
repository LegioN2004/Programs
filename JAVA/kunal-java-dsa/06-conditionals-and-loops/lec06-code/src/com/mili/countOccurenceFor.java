package com.mili;

public class countOccurenceFor {
    public static void main(String[] args) {
		int n = 333300000; // 4 must be the output here
		int c = 0;
		int count = 0;
		for (int i = 0; i <= 4; i++) {
			c = n % 10; // this c will get remainder of the number till the last division of the input from n and  
			n = n / 10; // this will make the number short by one digit from the last and overwrite n
			if (c == 0) {
				count++ ;
			}
		}
			System.out.println(count);
    }
}
