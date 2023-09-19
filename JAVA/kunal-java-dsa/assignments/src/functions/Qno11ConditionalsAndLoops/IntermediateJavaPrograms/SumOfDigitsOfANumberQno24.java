package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class SumOfDigitsOfANumberQno24 {
    public static void main(String[] args) {
        System.out.print("Print the number you want to find the sum of the digits of: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        sum(a);
    }

    static void sum(int a) {
        int b = 0, c = 0;
        while (a != 0) {
            b = a % 10;
            a = a / 10;
            c = c + b;
            System.out.println(b);
        }
        System.out.println("The required answer is -> " + c);
    }
}
