package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class PerimeterOfCircle {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        float rad = in.nextInt();
        double c = 2.0 * 3.14 * rad;  // we should not convert float to double or atleast take the double value in a float type as it may throw the error "incompatible types: possible lossy conversion from double to float" because you try to assign a value of type double to a variable of type float. It indicates that there may be a loss of precision in the conversion from double to float because float has a smaller range and precision than double.
        System.out.println("Mur mur tu PerimeterOfCircle hoi ki hoi " + c);
    }
}
