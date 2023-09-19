package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class CommissionPercentageQno6 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the sales amount: ");
        double salesAmt = in.nextDouble();
        System.out.print("Enter the commission rate: ");
        double comRate = in.nextDouble();
        comPercen(salesAmt, comRate);
    }

    static void comPercen(double salesAmt, double comRate) {
        double comAmt = (comRate * salesAmt) / 100;
        System.out.println("The commission amount is: " + comAmt);
        double comPercentage = comRate / 100;
        System.out.println("The commission percentage is: " + comPercentage);
    }
}
