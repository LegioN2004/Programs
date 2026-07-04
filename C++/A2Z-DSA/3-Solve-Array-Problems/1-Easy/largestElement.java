import java.util.Arrays;

public class largestElement {

    // O(n)
    static void optimal() {
        int arr[] = { 2, 5, 1, 3, 10 };
        int big = 0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > big)
                big = arr[i];
        }

        System.out.println("biggest: " + big);
    }

    // O(n log(n))
    static void brute() {
        int arr[] = { 2, 5, 11, 9, 1 };
        Arrays.sort(arr);
        System.out.println("biggest: " + arr[arr.length - 1]);

    }

    public static void main(String[] args) {
        brute();
    }
}