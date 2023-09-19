package functions.Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno1AreaOfCircle {
    public static void main(String[] args) {
        System.out.print("Print the value of the radius of the circle which you want the area of: ");
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println("the area of circle is: " + area(a));
    }

    static double area(int a) {
        double b = 3.14 * a * a;
        return b;
    }
}
