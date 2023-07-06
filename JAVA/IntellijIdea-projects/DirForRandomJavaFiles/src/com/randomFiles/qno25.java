package com.randomFiles;

import java.util.Scanner;

public class qno25 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int b = 0;
        int a;
        do {
            System.out.print("Enter an integer (press 0 to exit): ");
            a = in.nextInt();
            if (a > b) {
                b = a;
            }
        } while (a != 0);
        System.out.print("The largest no is: " + b);
    }
}
