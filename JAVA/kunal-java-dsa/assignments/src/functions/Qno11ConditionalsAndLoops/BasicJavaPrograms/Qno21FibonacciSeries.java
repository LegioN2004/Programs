package ConditionalsAndLoops.BasicJavaPrograms;// To calculate Fibonacci Series up to n numbers.

// it goes like this 0 1 1 2 3 5 8 13 21 34 .......

import java.util.Scanner;

public class Qno21FibonacciSeries {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // int n = in.nextInt();
        int n = 0; // no of times the loop should run
        int a = 0, b = 1, c = 0;
        Fibonacci(n, a, b, c);
    }

    static void Fibonacci(int n, int a, int b, int c) {
        while (n < 10) {
            a = b; // 1 0 1 1
            b = c; // 0 1 1 2
            c = a + b; // 1 1 2 3
            n++;
            System.out.println(b);
        }
    }
}
