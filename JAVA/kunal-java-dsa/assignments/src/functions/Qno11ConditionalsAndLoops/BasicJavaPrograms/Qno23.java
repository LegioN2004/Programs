package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno23 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Print the number of which you want the factors of: ");
        int a = in.nextInt(), b = 1;
        for (int i = 1; i <= a; i++) {
            if (a % b == 0) {
                System.out.println(b);
            }
            b++;
        }
    }
}
