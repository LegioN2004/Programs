// Define a method that returns the product of two numbers entered by user.
package functions;

import java.util.Scanner;

public class Qno5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        System.out.println(product(a, b) + " is the required product");
    }

    static int product(int a, int b){
        int c = a * b;
        return c;
    }
}
