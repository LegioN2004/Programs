// Write a program to print the circumference and area of a circle of radius entered by user by defining your own method.
package functions;

import java.util.Scanner;

public class Qno6 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println(circum(a) + " is the required circumference");
        System.out.println(area(a) + " is the required area");
    }

    static double circum(double r){
        double c = 2 * Math.PI * r;
       return c;
    }

    static double area(double r){
        double c = Math.PI * r * r;
        return c;
    }
}
