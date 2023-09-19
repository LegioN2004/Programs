package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno4AreaOfIsoscelesTriangle {
    public static void main(String[] args) {
        System.out.print("Print the base and height of the isosceles triangle which you want the area of: ");
        Scanner in = new Scanner(System.in);
        double a = in.nextInt(), c = in.nextInt();
        area(a, c);
    }

    static void area(double a, double c) {
        if (a == c) {
            double b = (1.0 / 2) * (a * c);
            System.out.println("the area of isosceles triangle is: " + b);
        } else {
            System.out.println(
                    "Provide same base and height otherwise it'll not be an isosceles triangle for gods sake, you failure");
        }
    }
}
