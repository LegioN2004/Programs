package functions.Qno11FlowOfPrograms;

import java.util.Scanner;

public class Qno1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        if (isLeap(a)) {
            System.out.println("year is leap");
        } else {
            System.out.println("year is not leap");
        }
    }

    static boolean isLeap(int a) {
        return a % 400 == 0 || (a % 4 == 0 && a % 100 != 0);
    }
}
