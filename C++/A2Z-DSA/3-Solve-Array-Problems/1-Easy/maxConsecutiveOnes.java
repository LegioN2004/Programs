/**
 * maxConsecutiveOnes
 */
public class maxConsecutiveOnes {

    private static void brute() {
        int arr[] = { 1, 1, 0, 1, 1, 1 };
        int max = 0;
        int ones = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 1) {
                ones++;
            }
            if (arr[i] == 0) {
                ones = 0;
            }
            if (ones > max) {
                max += ones;
            }
        }
        System.out.println(max);
    }

    public static void main(String[] args) {
        brute();
    }

}