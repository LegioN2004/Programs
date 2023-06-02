package com.mili;

import java.util.Scanner;

public class largestno {
    public static void main(String[] args) {
        System.out.println("Q: Find the largest of the 3 numbers");
        
        Scanner in = new Scanner(System.in);

        System.out.print("Print the numbers: ");
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        
				// one way to do is this -------------------------------------------
        // int max = a;
        // if (b > max){
        //     max = b;
        // } 
        // if (c > max){
        //     max = c;
        // }
				
				// 2nd way to do is this -------------------------------------------
				// int max = 0;
				// if (a > b) {
				// 		max = a;
				// } else {
				// 		max = b;
				// }

				// if (c > max) {
				// 		max = c;	
				// }
				
				// you can also do by using the math class and change the code acc to needs
				// Math.max
				int max = Math.max(c ,Math.max(a, b)); 
				// System.out.println(Math.max(39, 29));
				System.out.println(max + " is the maximum no");
    }

}
