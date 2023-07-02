import java.util.Scanner;

public class AreaOfRhombus {
	public static void main(String[] args) {
		System.out.print("Give the length breadth and height with some enters");
		Scanner in = new Scanner(System.in);
		double a = in.nextInt(), b = in.nextInt();
		double c = (a * b) / 2;
		System.out.println("the area of rhombus is: " + c);
	}
}
