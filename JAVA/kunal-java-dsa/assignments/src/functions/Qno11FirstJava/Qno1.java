package functions.Qno11FirstJava;

import java.util.Scanner;

public class Qno1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        evenOrOdd(a);
    }
    static void evenOrOdd(int a){
        if(a % 2 == 0){
            System.out.println("The number is even");
        }
        else if(a == 0) {
            System.out.println("Enter the correct number");
        }
        else {
            System.out.println("The number is odd");
        }
    }
}
