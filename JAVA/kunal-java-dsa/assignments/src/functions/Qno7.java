// Define a method to find out if a number is prime or not.
package functions;

import java.util.Scanner;

public class Qno7 {
    static int count = 0;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        if(isPrime(a)){
            System.out.println("The no " + a + " is prime");
        }
        else
            System.out.println("The no " + a + " is not prime");
    }

    static boolean isPrime(int a){
        if(a <= 1){
            return false;
        }
        for(int i = 1; i <= a; i++){
            if(a % i == 0){
                count++;
            }
        }
        return count == 2;
    }
}