package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno9PerimeterOfEquilateralTriangle {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Give the side of the equilateral triangle: ");
        int a = in.nextInt(), b = 0;
        System.out.println("The perimeter of the equilateral triangle is " + perimeter(a, b));
    }

    static int perimeter(int a, int b) {
        b = 3 * a;
        return b;
    }
}
