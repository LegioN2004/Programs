package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno8PerimeterOfCircle {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        float rad = in.nextInt();
        System.out.println("Mur mur tu PerimeterOfCircle hoi ki hoi " + perimeter(rad));
    }

    static double perimeter(double rad) {
        double c = 2.0 * 3.14 * rad; // we should not convert float to double or atleast take the double value in a
                                     // float type as it may throw the error "incompatible types: possible lossy
                                     // conversion from double to float" because you try to assign a value of type
                                     // double to a variable of type float. It indicates that there may be a loss of
                                     // precision in the conversion from double to float because float has a smaller
                                     // range and precision than double.
        return c;
    }
}
