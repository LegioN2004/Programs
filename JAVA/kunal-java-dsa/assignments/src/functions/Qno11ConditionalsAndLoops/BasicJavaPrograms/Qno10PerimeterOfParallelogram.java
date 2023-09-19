package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class PerimeterOfParallelogram {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Give the base and side of the parallelogram");
        int a = in.nextInt(), b = in.nextInt(), c = 0;
        System.out.println("The perimeter of the parallelogram is " + perimeter(a, b, c));
    }

    static int perimeter(int a, int b, int c) {
        c = 2 * (a + b);
        return c;
    }

}
