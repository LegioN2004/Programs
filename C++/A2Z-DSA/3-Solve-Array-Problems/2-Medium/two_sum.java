import java.util.Arrays;
import java.util.HashMap;

public class two_sum {

    /*
     * O(n^2) because we are traversing the array from first to last twice
     */
    static String bruteExists(int nums[], int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return "YES";
                }
            }
        }
        return "NO";
    }

    static int[] bruteIndices(int nums[], int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] { i, j };
                }
            }
        }
        return new int[] { -1, -1 };
    }

    static String betterExists(int nums[], int target) {
        // int[] nums = { 2, 6, 8, 5, 11 };
        // int target = 14;

        HashMap<Integer, Integer> nums2 = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int val = nums[i];
            int complement = target - val;
            if (nums2.containsKey(complement))
                return "YES";
            nums2.put(val, i);
        }

        return "NO";
    }

    static int[] betterIndices(int nums[], int target) {
        HashMap<Integer, Integer> nums2 = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int a = nums[i]; // 2, 7, 11
            int b = target - a; // 14 - 2 = 12

            if (nums2.containsKey(b)) {
                // new int containing earlier and current index
                return new int[] { nums2.get(b), i };
            }
            nums2.put(a, i);
        }
        return new int[] { -1, -1 };
    }

    /*
     * - here we'll be doing the 2 pointer approach or greedy approach and also
     * first sort it. for the variant 1 where we only return yes, it's easy to
     * return yes but for the variant 2 where we need to return the index, we'll
     * need another DS that will store the data as (number, index)
     * - so firstly there will be one left and right ptr, where we need to match the
     * target, so we'll do left + right == target, if true then we return yes or the
     * index from the DS or else no
     * - if the left + right > target, then decrement the right pointer
     * - if the left + right < target, then increment the left pointer
     */
    static int[] optimalIndices(int nums[], int target) {
        int n = nums.length;
        int numsWithIndices[][] = new int[n][2];

        for (int i = 0; i < n; i++) {
            numsWithIndices[i][0] = nums[i];
            numsWithIndices[i][1] = i;
        }

        /*
         * [
         * [ 2, 0 ],
         * [ 6, 1 ],
         * [ 5, 2 ],
         * [ 8, 3 ],
         * [ 11, 4 ],
         * ]
         */

        Arrays.sort(numsWithIndices, (a, b) -> Integer.compare(a[0], b[0]));

        int left = 0, right = n - 1;

        while (left < right) {
            if (target == numsWithIndices[left][0] + numsWithIndices[right][0])
                return new int[] { numsWithIndices[left][1], numsWithIndices[right][1] };
            else if (target > numsWithIndices[left][0] + numsWithIndices[right][0])
                left++;
            else
                right--;
        }
        return new int[] { -1, -1 };
    }

    static String optimalExists(int nums[], int target) {
        int n = nums.length;
        int result[][] = new int[n][2];

        for (int i = 0; i < n; i++) {
            result[i][0] = nums[i];
            result[i][1] = i;
        }

        Arrays.sort(result, (a, b) -> Integer.compare(a[0], b[0]));

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = result[left][0] + result[right][0];
            if (sum == target)
                return "YES";
            else if (sum < target)
                left++;
            else
                right--;
        }
        return "NO";
    }

    public static void main(String[] args) {
        int[] nums = { 2, 6, 8, 5, 11 };
        int target = 14;

        // System.out.println(bruteExists(nums, target));
        // System.out.println(betterExists(nums, target));
        System.out.println(optimalExists(nums, target));

        for (int j = 0; j < 2; j++) {
            // System.out.println(bruteIndices(nums, target)[j]);
            // System.out.println(betterIndices(nums, target)[j]);
            System.out.println(optimalIndices(nums, target)[j]);
        }
    }
}
