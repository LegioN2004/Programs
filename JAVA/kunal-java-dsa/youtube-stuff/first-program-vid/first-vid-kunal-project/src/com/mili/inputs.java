package com.mili;

import java.util.Scanner;

public class inputs {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // System.in takes keyb input
        System.out.print("enter the input = "); // prints output
        int rollno = input.nextInt(); // rollno takes value from keyb using input.nextInt
        System.out.println("your roll no is " + rollno ); // + is used to join together the sentence string in "" as well as the value of the variable
    }
}