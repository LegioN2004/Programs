package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno6 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the input in rupees to convert to usd");
        int a = in.nextInt();
        System.out.print(a + "RS converts to " + currency(a));
    }

    static double currency(int a) {
        double orig = a / 82.70;
        System.out.println(orig + "$");
        return orig;
    }
}
