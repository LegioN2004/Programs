import java.util.Arrays;

public class sort_array012 {
    static int[] brute(int[] nums) {
        // TC: n log n | SC: n or 1
        // if an extra array is used to store the array given in the question
        Arrays.sort(nums);
        return nums;
    }

    // TC: O(2n) | SC: O(1)
    // because there is no extra space used here
    static int[] better(int[] nums) {
        int zeroes = 0, ones = 0, twos = 0;

        // takes n time
        for (int i : nums) {
            if (i == 0)
                zeroes++;
            else if (i == 1) {
                ones++;
            } else
                twos++;
        }

        // takes n time for all the three for loops
        for (int i = 0; i < zeroes; i++) { // 0 - 4
            nums[i] = 0;
        }
        for (int i = zeroes; i < ones + zeroes; i++) { // 5 - 8
            nums[i] = 1;
        }
        for (int i = ones + zeroes; i < twos + ones + zeroes; i++) { // 9 - 11
            nums[i] = 2;
        }

        return nums;
    }

    static void swap(int nums[], int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    // Dutch National Flag Algorithm
    static int[] optimal(int nums[]) {

        int low = 0, mid = 0, high = nums.length - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums, low, mid);
                low++;
                mid++;
            } else if (nums[mid] == 1)
                mid++;
            else {
                swap(nums, mid, high);
                // mid++;
                high--;
            }

        }
        return nums;
    }

    public static void main(String[] args) {
        int[] nums = { 0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1 };

        for (int j = 0; j < nums.length; j++) {
            // System.out.println(brute(nums)[j]);
            // System.out.println(better(nums)[j]);
            System.out.println(optimal(nums)[j]);
        }
    }

}
