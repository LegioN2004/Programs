package functions.Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno24 {
    public static void main(String[] args) {
        print();
    }

    static void print() {
        Scanner in = new Scanner(System.in);
        int a = -1, b = 0;
        while (a != 0) {
            System.out.print("Print the numbers or press 0 to exit: ");
            a = in.nextInt();
            b += a;
        }
        System.out.println("Your sum is: " + b);
    }
}
