package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class PerfectNumberQno22 {
    public static void main(String[] args) {
        System.out.print("Give the number you want to find if it is a perfect number or not: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt(), c = 0;
        for(int i = 1; i < a; i++){
            if(a % i == 0){
                c += i;
            }
        }
        System.out.println("The calculated number is " + c);
        if(c == a) {
            System.out.println("Since it is equal to " + a + " so it is a perfect number");
        }else {
            System.out.println("Since it is not equal to " + a + " so it is not a perfect number");
        }
    }
}
