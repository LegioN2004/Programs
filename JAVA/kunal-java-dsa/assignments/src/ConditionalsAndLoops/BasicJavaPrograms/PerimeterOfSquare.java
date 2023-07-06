package ConditionalsAndLoops.BasicJavaPrograms;
import java.util.Scanner;

public class PerimeterOfSquare {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Give the side of the square ");
        int a = in.nextInt(), c;
        c = 4 * a;
        System.out.println("The perimeter of the parallelogram is " + c);
    }
}
