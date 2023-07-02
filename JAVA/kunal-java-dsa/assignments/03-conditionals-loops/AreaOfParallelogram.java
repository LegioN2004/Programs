import java.util.Scanner;

public class AreaOfParallelogram {
	public static void main(String[] args) {
		System.out.print("Give the length breadth and height with some enters");
		Scanner in = new Scanner(System.in);
		double b = in.nextInt(), c = in.nextInt();
		double d = b * c;
		System.out.println("the area of parallelogram is: " + d);
	}
}
