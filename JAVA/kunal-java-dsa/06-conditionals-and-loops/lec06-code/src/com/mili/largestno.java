package com.mili;

import java.util.Scanner;

public class largestno {
    public static void main(String[] args) {
        System.out.println("Q: Find the largest of the 3 numbers");
        
        Scanner in = new Scanner(System.in);
        System.out.print("Print the numbers: ");
        System.out.println("aorisntat");
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        
        int max = a;
        if (b > max){
            max = b;
        } 
        if (c > max){
            max = c;
        }
        System.out.println("The max no is " + max);
    }

}