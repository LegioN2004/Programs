package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class AreaOfCircle {
    public static void main(String[] args) {
        System.out.print("Print the value of the radius of the circle which you want the area of: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        double b = 3.14 * a * a;
        System.out.println("the area of circle is: " + b);
    }
}
