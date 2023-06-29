// To calculate Fibonacci Series up to n numbers.
package Assignments;

public class seventh {
    public static void main(String[] args) {
        long n = 10;
        int a = 0, b = 1, c = 0;
        System.out.println("------------ using the while loop ------------");
        System.out.println(c);
        while (c <= n) {
            a = b;
            b = c;
            c = a + b;
            System.out.println(c);
        }
        System.out.println("---------------------------------------------");

        System.out.println("------------ using for loop ------------");
        for (int i = 1; i <= n; i++) {
            System.out.print(a + " ");
            c = a + b;
            a = b;
            b = c;
        }
        System.out.println("--------------------------------------------");
    }
}
