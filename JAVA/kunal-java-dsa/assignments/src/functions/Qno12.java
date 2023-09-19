package functions;

import java.util.Scanner;

public class Qno11 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        triplet(a, b, c);
    }

    static void triplet(int a, int b, int c) {
         if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            System.out.println("The given numbers form a Pythagorean triplet.");
        } else {
            System.out.println("The given numbers do not form a Pythagorean triplet.");
        }
    }
}
