package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno12PerimeterOfSquare {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Give the side of the square ");
        int a = in.nextInt(), c = 0;
        System.out.println("The perimeter of the parallelogram is " + perimeter(a, c));
    }

    static int perimeter(int a, int c) {
        c = 4 * a;
        return c;
    }

}
