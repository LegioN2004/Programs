import java.util.Scanner;

public class cpThirdoubt {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] a = new int[4];
        for (int i = 0; i < a.length; i++) {
            a[i] = in.nextInt(); // 1 2 3 4
            runningSum(a);
        }
    }

    static void runningSum(int[] a) {
        int[] b = new int[4];
        b[0] = a[0];
        for (int i = 0; i < a.length; i++) {
            b[i] = b[i - 1] + a[i];
        }
        System.out.println(b);
    }



    // cp solution

}