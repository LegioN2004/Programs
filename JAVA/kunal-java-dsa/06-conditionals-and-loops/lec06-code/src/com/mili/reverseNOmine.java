package com.mili;

public class reverseNOmine {
    public static void main(String[] args) {
        System.out.println(" My version of the reverse a No problem ");
        int n = 28479;
        while (n > 0) {
            int a = n % 10;
            n = n / 10;
            System.out.print(a);
        }
        System.out.println("----------------------------------- ");
    }
    
}
