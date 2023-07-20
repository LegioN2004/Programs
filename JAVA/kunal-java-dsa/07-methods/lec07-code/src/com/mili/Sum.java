package com.mili;

import java.util.Scanner;

public class Sum {
    public static void main(String[] args) {
        sum();
    }

    // method
    // more about static in later videos, since the main function contains static
    // then anything that is under that static main must also be static
    static void sum() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the 1st number: ");
        int num1 = in.nextInt();
        System.out.print("Enter the 2nd number: ");
        int num2 = in.nextInt();
        int sum = num1 + num2;
        System.out.println("The sum is: " + sum);
    }
}

/*
 * syntax of method
 * access_modifier return_type_name(){
 * // body of the function
 * return statement;
 * }
 * 
 * access modifier(coming later in OOP videos)
 */
