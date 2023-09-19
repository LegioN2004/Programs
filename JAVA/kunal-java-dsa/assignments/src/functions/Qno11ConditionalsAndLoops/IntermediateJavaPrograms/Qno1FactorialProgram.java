package Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class FactorialProgramQno1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println(print(a));
    }

    static int print(int a) {
        int c = 1;
        for (int i = 1; i <= a; i++) {
            c *= i;
        }
        return c;
    }
}
