package com.mili;

import java.util.Scanner;

public class Qno2printArmstrong {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println(isArmstrong(a));
        
    // print all the 3 digit armstrong numbers
        for (int i = 100; i < 1000; i++) { // starting from 3 digit so i = 100 and end till the 1000 since only 3 digit numbers i.e a so i < 1000
           if(isArmstrong(i)){
                System.out.println(i + " ");
            }
        }
    }
    
    // print whether it is armstrong or not
    static boolean isArmstrong(int n){
        int original = n;
        int sum = 0;

        while(n > 0){
            int rem = n % 10;
            n = n / 10;
            sum = sum + rem * rem * rem; // we know we'll be doing cube since we are printing only the 3 digit numbers
        }
        return sum == original; 
    }
}
