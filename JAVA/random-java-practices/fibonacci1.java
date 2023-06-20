public class fibonacci1 {
	public static void main(String[] args) {
		int n = 100;
		int a = 0, b = 1, c = 0;
		while (c <= n) {
			c = a + b;
			a = b;
			c = b;
			System.out.println(c);
		}
	}
}
