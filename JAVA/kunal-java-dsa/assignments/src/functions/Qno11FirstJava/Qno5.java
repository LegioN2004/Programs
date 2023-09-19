package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the two numbers");
        int a = in.nextInt();
        int b = in.nextInt();
        largest(a, b);
    }

    static void largest(int a, int b) {
        if (a > b) {
            System.out.println(a + " is the largest no out of the two");
        }
        if (a == b) {
            System.out.println("you have entered the same numberssssss, fix it and rerunnn agaiiiiiiiiiiiin");
        } else {
            System.out.println(b + " is the largest no out of the two");
        }
    }

}
