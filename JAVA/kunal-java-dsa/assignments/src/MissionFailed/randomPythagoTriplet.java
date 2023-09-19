import java.util.Scanner;

// This program prompts the user to enter a limit and then checks all possible combinations of three numbers up to that limit.

public class randomPythagoTriplet {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the limit: ");
        int limit = in.nextInt();
        in.close();

        for (int a = 1; a <= limit; a++) {
            for (int b = a + 1; b <= limit; b++) {
                for (int c = b + 1; c <= limit; c++) {
                    if (a * a + b * b == c * c) {
                        System.out.printf("(%d, %d, %d) is a Pythagorean triplet.%n", a, b, c);
                    }
                }
            }
        }
    }
}