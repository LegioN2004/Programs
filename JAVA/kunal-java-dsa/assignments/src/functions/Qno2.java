// Define a program to find out whether a given number is even or odd.
package functions;

import java.util.Scanner;

public class Qno2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println(isEvenorOdd(a));
    }

    static String isEvenorOdd(int a){
        String result = " ";
        if(a % 2 == 0){
            result = "no is even";
        }
        else {
            result = "no is odd";
        }
        return result;
    }
}
