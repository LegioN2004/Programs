package com.mili;

import java.util.Scanner;

// TODO: look at the readme file for extending the calculator.java more and convert it to a full fledged gui calculator, good project idea
public class calculator {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = 0, b = 0, c = 0;
        while (true) {
            System.out.println("Also use x or X to break out of this whole operation");
            System.out.print("Print the operator: ");
            char op = in.next().trim().charAt(0);
            if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') { // take the input of operator
                System.out.print("give the numbers to a and b: ");
                a = in.nextInt();
                b = in.nextInt();
                if (op == '+') {
                    c = a + b;
                }
                if (op == '-') {
                    c = a - b;
                }
                if (op == '*') {
                    c = a * b;
                }
                if (op == '/') {
                    c = a / b;
                }
                if (op == '%') {
                    c = a % b;
                }
            } else if (op == 'x' || op == 'X') { // use this at the outside of the top most level if statement
                break;
            } else {
                System.out.println("Invalid operator ");
            }
            System.out.println(c);
        }
    }
}
