class Solution {
    // Function to check if the array is sorted
    boolean isSorted(int[] arr, int n) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[i])
                    return false;
            }
        }
        return true;
    }
}

public class sortedArray {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };
        int n = 5;
        Solution obj = new Solution();

        boolean ans = obj.isSorted(arr, n);

        // Output result
        if (ans)
            System.out.println("True");
        else
            System.out.println("False");
    }
}
