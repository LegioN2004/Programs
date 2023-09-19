package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class Qno25 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Print the no of days in the month of August: ");
        int a = in.nextInt(), b = 0, c = 0;
        for (int i = 1; i <= a; i++){
            if(i % 2 == 0){
                c++;
            }
        }
        System.out.print(c);
    }
}
