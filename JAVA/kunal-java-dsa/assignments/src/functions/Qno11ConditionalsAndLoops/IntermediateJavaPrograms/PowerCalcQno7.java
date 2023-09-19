package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class PowerCalcQno7 {
    public static void main(String[] args) {
        System.out.println("Power calculation!!!");

        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number you want the power of: ");
        float a = in.nextFloat();
        System.out.print("Enter the power that you want to calculate: ");
        float b = in.nextInt();
        double d = Math.pow(a, b); // using the Math class's function
        System.out.println("The calculated value of the power of the number using Math.pow() is: " + d);
        float c = 0;
        float e = a;
        for(int i = 1; i < b; i++){
             c = a * e;
             a = c;
        }
        System.out.println("The calculated value of the power of the number is: " + c);
    }
}
