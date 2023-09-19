package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class AreaOfParallelogram {
    public static void main(String[] args) {
        System.out.print("Give the length breadth and height with some enters");
        Scanner in = new Scanner(System.in);
        double b = in.nextInt(), c = in.nextInt();
        System.out.println("the area of parallelogram is: " + area(b, c));
    }

    static double area(double b, double c) {
        double d = b * c;
        return d;
    }
}
