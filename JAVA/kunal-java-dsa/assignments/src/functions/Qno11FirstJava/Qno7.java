package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno7 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number to calculate the fibonacci series upto: ");
        int a = in.nextInt();
        System.out.println(fibonacci(a) + " is the required fibonacci calculated series upto n numbers");
    }

    static int fibonacci(int n) {
        int a = 0, c = 0, b = 1;
        if(n == 0){
            return a;
        }
        for (int i = 2; i <= n ; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}
