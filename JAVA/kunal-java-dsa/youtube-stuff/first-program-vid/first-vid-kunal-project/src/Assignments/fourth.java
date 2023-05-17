//Take in two numbers and an operator (+, -, *, /) and calculate the value. (Use if conditions)::
package Assignments;
import java.util.Scanner;
public class fourth {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);

        System.out.print("give the first number ");
        float a = x.nextFloat();

        System.out.print("give the second number ");
        float b = x.nextFloat();

        System.out.print("choose the operator(+, -, *, /) ");
        char oper = x.next().charAt(0);// also try the 1th and 2th index to check if it rep the cmd line array index

        double c;

        if (oper == '+') {
            c = a + b;
        } else if (oper == '-') {
            c = a - b;
        } else if (oper == '*') {
            c = a * b;
        } else if (oper == '/') {
            c = a / b;
        } else {
            System.out.println("invalid");
            return; // to go out of the program
        }

        System.out.println(c + " is the result after taking the operator");
    }
}