package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class CheckLeapYearQno23 {
    public static void main(String[] args) {
        System.out.print("Give the year to check if it is a Leap year or not: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt(), c = 0;
        leap(a, c);
    }

    static void leap(int a, int c) {
        if (a % 400 == 0) {
            System.out.print("is a leap year ");
        } else if (a % 100 == 0 && a % 400 != 0) {
            System.out.print("is not a leap year ");
        } else if (a % 100 != 0 && a % 4 == 0) {
            System.out.print("is a leap year ");
        } else {
            System.out.print("is not a leap year ");
        }
    }
}
