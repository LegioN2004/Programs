package functions.Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno22 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println("The required result is: " + hello(n));
    }

    static int hello(int n) {
        int product = 1, sum = 0;
        while (n > 0) {
            int c = n % 10;
            product = product * c;
            sum = sum + c;
            n = n / 10;
        }
        return product - sum;
    }
}
