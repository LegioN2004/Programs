import java.util.Scanner;

public class first {
    static void namePrint(int i, int n) {
        if (i > n) return;
        System.out.println("G ILY");
        namePrint(i + 1, n);
    }

    static void noPrint(int i, int n) {
        if (i > n) {
            return;
        }
        System.out.println(i);
        noPrint(i + 1, n);
    }

    static void noReversePrint(int i, int n) {
        if (i < 1) {
            return;
        }
        System.out.println(i);
        noReversePrint(i - 1, n);
    }

    static void noStraightBacktracking(int i, int n) {
        if (i < 1) {
            return;
        }
        noStraightBacktracking(i - 1, n);// 3, 4; 2, 4; 1, 4; then comes back and prints serially
        System.out.println(i);
    }

    static void noReverseBacktracking(int i, int n) {
        // print 4, 3, 2, 1 using backtracking
        if (i > n) {
            return;
        }
        noReverseBacktracking(i + 1, n);// 4, 4; 3, 4; 2, 4; then comes back and prints serially
        System.out.println(i);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        noReverseBacktracking(1, n);
    }
}