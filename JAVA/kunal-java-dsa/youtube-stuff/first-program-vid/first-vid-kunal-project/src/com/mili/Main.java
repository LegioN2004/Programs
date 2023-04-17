package com.mili; // com.mili it's the folder in which the java file will lie

// more info stuff in the org notes of java

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.print("hello world"); //print doesn't add a new line in the output
        System.out.println("a new line will be added after this");
        System.out.println("using the aliases or shortcut written code"); // println prints a line and creates a new line
        System.out.println(10274); // doesn't need apostrophes for numbers
        Scanner input = new Scanner(System.in); // taking input look into note2.org for more details
        System.out.println(input.nextInt());
    }
}
