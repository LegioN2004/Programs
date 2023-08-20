import java.util.Scanner;

public class primeNumber {
    static int count = 0;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println(isPrime(a));
    }

    // here the logic goes like, between the no and 1 the no of times the prime no
    // can get a remainder 0 is two, so we write the code to check that only.
    static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count == 2) {
            return true;
        } else {
            return false;
        }
    }
}
