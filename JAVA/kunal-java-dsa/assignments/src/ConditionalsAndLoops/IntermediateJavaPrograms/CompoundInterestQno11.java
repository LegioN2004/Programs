package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class CompoundInterestQno11 {
    public static void main(String[] args) {
        System.out.println("Finding the CompoundInterest of the program");
        // we need future value of investment = Amount A, principal amount = P, interest
        // rate = r , no of times per year that
        // interest is compunded = n, no of years the money is invested = t

        Scanner in = new Scanner(System.in);

        System.out.print("Please enter the principal amount invested -> ");
        double prinAmt = in.nextInt(); // P

        System.out.print("Please enter the interest rate -> ");
        double intRate = in.nextDouble(); // r

        System.out.print("Please enter the no years the money is invested -> ");
        int years = in.nextInt(); // t

        // don't know if the following lines are required in the calculation of the
        // compound interest
        // System.out.print("Please enter the no of times per year that interest is
        // compounded -> ");
        // int cmpdYrs = in.nextInt(); // n

        double futValue = prinAmt * Math.pow((1 + intRate / 100), years); // A

        // System.out.println("The future value is: " + futValue); // don't know even if
        // this is required or not
        System.out.println("The compound interest is: " + (futValue - prinAmt));
    }
}
