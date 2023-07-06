package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class PerimeterOfRectangle {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Give the length and breadth of the parallelogram");
        int a = in.nextInt(), b = in.nextInt(), c;
        c = 2 * (a + b);
        System.out.println("The perimeter of the parallelogram is " + c);
    }
}