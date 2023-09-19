package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the two numbers followed by any one of the operator '+ or - or / or *' at the end only pls");
        int a = in.nextInt();
        int b = in.nextInt();
        char c = in.next().charAt(0);
        System.out.println(calculate(a, b, c));
    }

    static int calculate(int a, int b, char c) {
        int ans = 0;
        if (c == '+') {
            ans = a + b;
        }
        if (c == '-') {
            ans = a - b;
        }
        if (c == '/') {
            ans = a / b;
        }
        if (c == '*') {
            ans = a * b;
        } else {
            System.out.println(
                    "You have entered the wrong operator or your order is not okay please fix it and enter again ");
        }
        return ans;
    }
}
