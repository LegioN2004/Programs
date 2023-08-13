package com.mili;

import java.util.Scanner;

public class Sum {
    public static void main(String[] args) {
        // sum();
        // sum(); // add this a no of times to make it repeat that many amount of times.
        // System.out.println(sum2());
        // sum2();
        // int ans = sum2();
        int ans1 = sum3(20, 40);
        System.out.println(ans1);
    }

    // pass the value of the numbers when you are calling the method in main()
    static int sum3(int a, int b) {
        int sum = a + b;
        return sum;
    }

    // now we're returning the value, not just printing it.
    // using the int type in the function since the value returned to be int
    static int sum2() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the 1st number: ");
        int num1 = in.nextInt();
        System.out.print("Enter the 2nd number: ");
        int num2 = in.nextInt();
        int sum = num1 + num2;
        return sum; // here "return" is used to return the value of this sum which is the return
                    // this function to the function call
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
