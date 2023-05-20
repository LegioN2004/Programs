// loops 
package com.mili;

import java.util.Scanner;

public class loops {
    public static void main(String[] args) {
        // FOR loops
        // Q1 : Print the numbers from 1 to 5
        // Scanner a = new Scanner(System.in);
        for (int i = 1; i <= 5; i += 1) {
            System.out.println(i);
        }
        System.out.println("for loop 1st eg finished");

        // print numbers from 1 to n where n is the input from user
        Scanner n = new Scanner(System.in);
        System.out.print("input the number: ");
        int num = n.nextInt();
        for (int i = 1; i <= num; i += 1) {
            // System.out.print(i);
            System.out.println("Hello world"); // print hello world n of times
        }
        System.out.println("--------------------for loop 2nd eg finished--------------------");


        System.out.println("--------------------this is while loop part--------------------");

        // WHILE loops
        // here we are converting the for loop into a while loop
        int num2 = 1; // the initialisation of the for loop will come outside of the loop and will be
                      // written first for declaration
        while (num2 <= 5) { // the condition will come here
            System.out.println(num2); // code body will remain in the same position
            num2 += 1; // inc/dec part will come inside the code body
        }
        System.out.println("--------------------this is while loop part finished--------------------");


        System.out.println("--------------------this is do-while loop part finished--------------------");
        // Do-WHILE loops
         int num3 = 1;
        do {
            System.out.println(num3);
            num3++;
        } while (num3 <= 5);
        
    }
}