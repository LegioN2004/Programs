package Assignments;

import java.util.Scanner;

public class first{
    public static void main(String[] args){
        long c;
        Scanner num = new Scanner(System.in);
        long a = num.nextInt();
        c = a%2;
        if (c==0)
        System.out.print(a + " is an even number");
        else
        System.out.print(a + " is an odd number");
    }
}