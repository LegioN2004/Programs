// todo: fix the if else statement for showing the
package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class PermutationAndCombinationQno15 {
    public static void main(String[] args) {
        System.out.println("Printing Ncr and Ncr");
        // solving these with a problem for both the types
        Scanner in = new Scanner(System.in);
        System.out.print("Print what do you want to do, for permutation write 'per' and for combination type 'com': ");
        String todo = in.next().trim();
        if (todo.equals("per")) {
            per();
        } else if (todo.equals("com")) {
            com();
        }
    }

    static void per() {
        Scanner in = new Scanner(System.in);
        // firstly npr
        System.out.println("First nPr : Q) how to choose 2 objects from a set of 5 objects?");
        System.out.print("Enter the value of n -> ");
        int n = in.nextInt();
        System.out.print("Enter the value of r -> ");
        int r = in.nextInt();
        int a = 1;
        for (int i = 1; i <= n; i++) {
            a = a * i;
        }
        System.out.println(a);
        // calculating the denominator i.e factorial of n - r
        int e = n - r;
        int c = 1;
        for (int i = 1; i <= e; i++) {
            c = c * i;
        }
        System.out.println("The value of permutation of " + n + "P" + r + ": " + (a / c));
    }

    static void com() {
        Scanner in = new Scanner(System.in);
        System.out.println("Secondly nCr: Q) Find the combination of 4 objects from the set of 6? -> ");
        // firstly numerator
        System.out.print("Enter the value of n -> ");
        int n = in.nextInt();
        int a = 1;
        for (int i = 1; i <= n; i++) {
            a = a * i;
        }
        System.out.println(n + "! = " + a);
        // denominator
        // firstly r! and then (n-r)!
        System.out.print("Enter the value of r -> ");
        int r = in.nextInt();
        int x = 1;
        for (int i = 1; i <= r; i++) {
            x = x * i;
        }
        System.out.println(r + "! = " + x);
        // calculating the denominator i.e factorial of n - r
        int e = n - r;
        int c = 1;
        for (int i = 1; i <= e; i++) {
            c = c * i;
        }
        System.out.println("(" + n + " - " + r + ")! = " + c);
        int f = c * x;
        System.out.println("The value of combination of " + n + "C" + r + ": " + (a / c * x));
    }
}
