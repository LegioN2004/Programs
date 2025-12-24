// 8. [How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)

package Arrays.Easy;

public class qno8 {
    public static void main(String[] args) {
        int[] nums = { 8, 1, 2, 2, 3 };
        System.out.println(java.util.Arrays.toString(func(nums)));
    }

    static int[] func(int[] nums) {
        // int[] sorted = Arrays.copyOf(nums, nums.length); // this creates a copy of
        // the original array
        // Arrays.sort(sorted); // this sorts the copied one instead of original
        // [ 1, 2, 2, 3, 8]

        int result[] = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
                int count = 0;
            for (int j = 0; j < nums.length; j++) {
                if (nums[i] > nums[j]) {
                    count++;
                    result[i] = count;
                } else
                    result[i] = count;
            }
        }
        return result;
    }
}
