package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class qno22 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), c = 0, product = 1, sum = 0;
        while (n > 0) {
            c = n % 10;
            product = product * c;
            sum = sum + c;
            n = n / 10;
        }
        System.out.println("The required result is: " + (product - sum));
    }
}
