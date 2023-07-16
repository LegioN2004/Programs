package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class PalindromeORnotQno17 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Print the number you want the palindrome of: ");
        int a = in.nextInt(), b = 0, c = 0, d = a;
        while (a > 0) {
            b = a % 10;
            c = (c * 10) + b;
            a = a / 10;
        }
        System.out.println("The number found after the calculation the palindrome number: " + c);
        if (d == c) {
            System.out.println("The number is palindrome");
        } else {
            System.out.println("The number is not palindrome");
        }
    }
}
