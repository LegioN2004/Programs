package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class DepreciationValueQno8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Calculating the depreciation value");
        System.out.print("Give the initial value after a certain time t: ");
        double v1 = in.nextDouble();
        System.out.print("Give the rate of the depreciation per year: ");
        double r = in.nextDouble();
        System.out.print("And give the year at which the rate of depreciation happens: ");
        int t = in.nextInt();
        depreciation(v1, r, t);
    }

    static void depreciation(double v1, double r, double t) {
        double v2 = v1 * Math.pow((1 - r / 100), t);
        System.out.println("The depreciation value is: " + v2);
    }
}
