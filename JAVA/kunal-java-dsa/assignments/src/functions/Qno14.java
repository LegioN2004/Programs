package functions;

import java.util.Scanner;

public class Qno14 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Give the number: ");
        int a = in.nextInt();
        System.out.println(sum(a));
    }

    static int sum(int a) {
        int c = 0;
        for (int i = 1; i <= a; i++) {
            c = c + i;
        }
        return c;
    }
}