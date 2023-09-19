package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno6AreaOfRhombus {
    public static void main(String[] args) {
        System.out.print("Give the length breadth and height with some enters");
        Scanner in = new Scanner(System.in);
        double a = in.nextInt(), b = in.nextInt();
        System.out.println("the area of rhombus is: " + area(a, b));
    }

    static double area(double a, double b) {
        double c = (a * b) / 2;
        return c;
    }
}
