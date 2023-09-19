package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class ArmstrongNumberQno14 {
    public static void main(String[] args) {
        System.out.println("Armstrong number");
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number you want to find the armstrong of: ");
        int a = in.nextInt();
        armstrong(a);
    }

    static void armstrong(int a) {
        int c = 0, d = a;
        // this is the program after changing it with the easy version from youtube
        while (a > 0) {
            int rem = a % 10;
            c = (rem * rem * rem) + c;
            a = a / 10;
        }
        if (d == c) {
            System.out.println(
                    "So after the calculation we get the number " + c + " and it is equal to " + d
                            + " so the number is armstrong");
        } else {
            System.out.println("The number is not armstrong");
        }
    }
}
