package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno25 {
    public static void main(String[] args) {
        print();
    }

    static void print() {
        Scanner in = new Scanner(System.in);
        int b = 0;
        int a;
        System.out.print("Enter an integer (press 0 to exit): ");
        do {
            a = in.nextInt();
            if (a > b) {
                b = a;
            }
        } while (a != 0);
        System.out.print("The largest no is: " + b);
    }
}
