import java.util.Scanner;

public class AreaOfTriangle {
	public static void main(String[] args) {
		System.out.print("Print the base and height of the triangle which you want the area of");
		Scanner in = new Scanner(System.in);
		double a = in.nextInt(), c = in.nextInt();
		double b = (1.0 / 2) * (a * c);
		System.out.println("the area of triangle is: " + b);
	}
}
