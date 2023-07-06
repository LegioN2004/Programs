package FirstJava;
// Write a program to input principal, time, and rate (P, T, R) from the user and find Simple Interest.

import java.util.Scanner;

public class third {
    public static void main(String[] args) {
        Scanner a = new Scanner(System.in); // I can use a single input taking declaration line for multiple times using the
        // variable at the new declarations for taking that input into other vars for use like the following a.next___();
        float prin = a.nextFloat();
        int time = a.nextInt();
        float rate = a.nextFloat();

        float interest = (prin * time * rate) / 100;

        System.out.println( interest + " is the simple interest");
    }
}
