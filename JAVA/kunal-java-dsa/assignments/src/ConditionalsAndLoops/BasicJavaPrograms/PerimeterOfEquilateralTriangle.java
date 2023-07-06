package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class PerimeterOfEquilateralTriangle {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Give the side of the equilateral triangle");
        int a = in.nextInt(), b;
        b = 3 * a;
        System.out.println("The perimeter of the equilateral triangle is " + b);
    }
}