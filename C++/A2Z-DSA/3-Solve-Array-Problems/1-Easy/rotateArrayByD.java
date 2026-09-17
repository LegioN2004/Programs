public class rotateArrayByD {

    /*
     * d = 2 -> 3, 4, 5, 1, 2
     * d = 3 -> 2, 3, 4, 5, 1
     * d = 7 -> 1, 2, 3, 4, 5 (comes to the same place)
     * d = 9 = 7 + 1 -> 2, 3, 4, 5, 1 (
     * d = 15 = 7 + 7 + 1 -> 2, 3, 4, 5, 1
     */

    // d = d % n = 15 % 7

    // doesn't work for k = 3 in leetcode idk why
    static void striverBrute() {
        int nums[] = { 1, 2, 3, 4, 5 };
        int k = 3;
        k = k % nums.length;
        int temp[] = new int[k];
        for (int i = 0; i < k; i++) {
            temp[i] = nums[i];
        }

        for (int i = k; i < nums.length; i++) {
            nums[i - k] = nums[i];
        }

        for (int i = nums.length - k; i < nums.length; i++) {
            nums[i] = temp[i - (nums.length - k)];
        }
    }

    /*
     * 2. O(k)
     * 3. O(n - k - 1) elements transferred
     * 4. O(k)
     * TC: O(n - 1 + k)
     * Extra SC: O(k) because that's the extra sized array created to make the
     * temp[]
     */
    static void brute() {
        int nums[] = { 1, 2, 3, 4, 5 };
        int k = 3;
        int n = nums.length;

        // 1. Handle edge case where k is larger than the array length
        k = k % n;
        if (k == 0)
            return;

        // 2. For a right rotation, we need to save the LAST k elements,
        // because they are going to get overwritten first.
        int temp[] = new int[k];
        int tempIndex = 0;
        for (int i = n - k; i < n; i++) {
            temp[tempIndex] = nums[i];
            tempIndex++;
        }

        // 3. Shift the remaining elements from the front to the back
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // 4. Place the saved temp elements back into the front of the array
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }

        for (int i = 0; i < k; i++) {
            System.out.println(nums[i]);
        }
    }

    // function for reverse
    static void reverse(int arr[], int start, int end) {

        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }

        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
            System.out.println();
    }

    static void optimal() {
        int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
        int k = 3;
        int n = nums.length;
        k = k % n;

        // right reverse
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);

        // left reverse
        // reverse(nums, 0, k - 1);
        // reverse(nums, k, n - 1);
        // reverse(nums, 0, n - 1);

    }

    public static void main(String[] args) {
        optimal();
    }
}
