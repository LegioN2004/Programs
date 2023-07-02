import java.util.Scanner;

public class AreaOfRectangle {
	public static void main(String[] args) {
		System.out.print("Give the length breadth and height with some enters");
		Scanner in = new Scanner(System.in);
		double a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
		double d = a * b * c;
		System.out.println("the area of rectangle is: " + d);
	}
}
