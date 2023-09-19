// Write a program to print the sum of two numbers entered by user by defining your own method.
package functions;

import java.util.Scanner;

public class Qno4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        System.out.println(sum(a, b) + " is the sum of 2 numbers, " + a + " and " + b);
    }

    static  int sum(int a, int b){
        int c = a + b;
        return c;
    }
}
