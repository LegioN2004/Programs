package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the principal, time and rate serially to calculate the S.I. ");
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        System.out.println(simpleInterest(a, b, c));
    }

    static int simpleInterest(int a, int b, int c) {
        int si = 0;
        si = (a * b * c) / 100;
        return si;
    }
}