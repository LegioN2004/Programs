public class checkSortedArray {
    static boolean brute(int[] arr, int n) {
        // TC: O(n^2) | SC: O(1)
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] < arr[i])
                    return false;
            }
        }
        return true; // Return true if no unsorted elements are found
    }

    static boolean optimal(int[] arr, int n) {
        // TC: O(n) | SC: O(1)
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true; // Return true if no unsorted elements are found
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 6, 4, 5 };
        int n = 5;

        if (optimal(arr, n))
            System.out.println("True");
        else
            System.out.println("False");
    }
}
