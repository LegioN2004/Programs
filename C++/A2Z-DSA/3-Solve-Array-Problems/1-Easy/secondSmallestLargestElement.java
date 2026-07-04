import java.util.Arrays;

public class secondSmallestLargestElement {

    static void optimal() {
        int arr[] = { 2, 2, 5, 11, 11, 3, 3, 10, 10 };
        int big = Integer.MIN_VALUE;
        int small = Integer.MAX_VALUE;
        int secBig = Integer.MIN_VALUE;
        int secSmall = Integer.MAX_VALUE;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > big)
                big = arr[i];
            if (arr[i] < small)
                small = arr[i];
            if (arr[i] > secBig && arr[i] != big)
                secBig = arr[i];
            if (arr[i] < secSmall && arr[i] != small)
                secSmall = arr[i];
        }

        System.out.println("second smallest: " + secSmall);
        System.out.println("second biggest: " + secBig);
    }

    static void brute() {
        int arr[] = { 1, 2, 2, 5, 11, 11, 11, 9, 9, 1, 1, 1 };
        Arrays.sort(arr);

        int secSmall = -1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[0]) {
                secSmall = arr[i];
                break;
            }
        }

        int secBig = -1;
        for (int i = arr.length - 2; i >= 0; i--) {
            if (arr[arr.length - 1] != arr[i]) { //
                secBig = arr[i];
                break;
            }
        }

        System.out.println("second smallest: " + secSmall);
        System.out.println("second biggest: " + secBig);
    }

    public static void main(String[] args) {
        optimal();
    }
}