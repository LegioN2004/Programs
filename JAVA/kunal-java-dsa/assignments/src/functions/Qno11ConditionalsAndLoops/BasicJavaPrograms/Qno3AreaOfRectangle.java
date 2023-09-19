package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno3AreaOfRectangle {
    public static void main(String[] args) {
        System.out.print("Give the length breadth and height with some enters ");
        Scanner in = new Scanner(System.in);
        double a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
        System.out.println("the area of rectangle is: " + area(a, b, c));
    }

    static double area(double a, double b, double c) {
        double d = a * b * c;
        return d;
    }
}
