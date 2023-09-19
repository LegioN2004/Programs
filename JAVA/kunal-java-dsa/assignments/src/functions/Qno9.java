// Write a program to print the factorial of a number by defining a method named 'Factorial'.
package functions;

import java.util.Scanner;

public class Qno9 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println(Factorial(a) + " is the factorial value of the number " + a);
    }

    static int Factorial(int n){
        int a = 1;
        // don't forget to add the following which is 0! = 1
        if(n == 0){
            a=1;
            return a;
        }
        do{
            a = n * a;
            n = n - 1;
        } while (n != 0);
        return a;
    }
}
