package FirstJava;

// To find armstrong number between 2 given number
import java.util.Scanner;

public class ninth {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Print the two numbers you want to find the palindrome of: ");
        // for the first input
        int a = in.nextInt(), b = a, c = 0, d = 0;
        while (a > 0) {
            c = a % 10;
            d = (c * c * c) + d;
            a = a / 10;
        }
        // for the second input
        int x = in.nextInt(), y = x, e = 0, f = 0;
        while (x > 0){
            e = x % 10;

        }
        if(b == c) {
            System.out.println("The number given is an armstrong number");
        }else {
            System.out.println("The number given is an armstrong number");
        }
    }
}
