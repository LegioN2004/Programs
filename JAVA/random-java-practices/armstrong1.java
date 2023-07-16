import java.util.Scanner;

public class armstrong1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt(), b = a, c = 0, d = 0;
        while (a > 0) {
            c = a % 10;
            d = (c * c * c) + d;
            a = a / 10;
        }
        if (b == c) {
            System.out.println("The number given is an armstrong number");
        } else {
            System.out.println("The number given is an armstrong number");
        }
    }
}
