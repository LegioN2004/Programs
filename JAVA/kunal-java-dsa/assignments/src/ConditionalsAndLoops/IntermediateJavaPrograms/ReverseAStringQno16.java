package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class ReverseAStringQno16 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter an example string: ");
        String a = in.next();
        int b = a.length();
        for (int i = 1; i <= b; i++) {
            System.out.print(a.charAt(b-i));
        }
    }
}
