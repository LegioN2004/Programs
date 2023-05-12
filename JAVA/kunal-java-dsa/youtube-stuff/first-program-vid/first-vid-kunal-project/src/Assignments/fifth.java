package Assignments;

import java.util.Scanner;

public class fifth {
    public static void main(String[] args) {
        Scanner no = new Scanner(System.in);
        System.out.print("print the value of a ");
        double a = no.nextDouble();
        System.out.print("print the value of b ");
        double b = no.nextDouble();
        if (a > b)
            System.out.println("a is greater than b");
        else
            System.out.println("b is greater than a");
        System.out.println("finished");
    }
}
