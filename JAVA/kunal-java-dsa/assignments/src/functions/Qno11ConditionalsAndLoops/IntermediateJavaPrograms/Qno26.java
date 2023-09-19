package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class Qno26 {
    public static void main(String[] args) {
        System.out.println("Give the numbers");
        num();
    }

    static void num() {
        Scanner in = new Scanner(System.in);
        int b = 0, c = 0, d = 0;
        while (true) {
            int a = in.nextInt();
            if (a == 0) {
                break;
            } else if (a % 2 == 0 && a > 0) {
                b = a + b;
            } else if (a <= 0) {
                c = c + a;
            } else if (a % 2 != 0 && a > 0) {
                d = d + a;
            }
        }
        System.out.print("The required result is -> " + (b + c + d));
    }
}
