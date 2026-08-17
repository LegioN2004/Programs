import java.util.HashMap;
import java.util.Map;

// This is a prefix sum concept problem
public class longestSubarrayPositiveK {

    static void brute() {
        int arr[] = { 1, 2, 3, 1, 1, 1, 1, 4, 2, 3 };
        int count = 0;
        int k = 3;

        for (int i = 0; i < arr.length; i++) {
            int sum = 0;
            for (int j = i; j < arr.length; j++) {
                // O(n^3) solution but n^2 will be the final brute solution
                // for (int l = i; l <= j; l++) {
                // sum += arr[j];
                // }
                sum += arr[j];
                if (sum == k) {
                    count = Math.max(count, j - i + 1);
                }
            }
        }
        System.out.println(count);
    }

    // this will work for both positives only and positives or negatives
    /*
     * TC: O(n^2) | We are iterating so n once and as for using a HashMap if it is
     * the ordered one then it takes log n TC but here it is unordered so it's 1 but
     * due to many constraints nd problems it ends up being n.
     * If there's no collisions unordered map will have TC O(1)
     * SC: O(n) | we are storing every prefixSum and every index will have
     * individual prefixSum explain the edge cases of +ve/-ve and edge cases of
     * zeroes and how this is the optimal solution for positives and negatives
     */

    static void better() {
        int arr[] = { 1, 3, 1, 1, 4, 5, 6 };
        // int arr[] = { 1, 2, 3, 1, 1, 1, 1, 4, 2, 3 };
        HashMap<Long, Integer> prefixSum = new HashMap<>();
        long sum = 0;
        int maxLen = 0;
        int k = 2;

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];

            if (sum == k)
                maxLen = Math.max(maxLen, i + 1);

            long rem = sum - k;
            if (prefixSum.containsKey(rem)) {
                int len = i - prefixSum.get(rem);
                maxLen = Math.max(maxLen, len);
            }
            if (!prefixSum.containsKey(sum))
                prefixSum.put(sum, i);
        }

        System.out.println(maxLen);
    }

    /*
     * if the array contains only positives and zeroes, then the most optimal
     * solution is possible
     */

    // it'll be using 2 pointer approach and greedy approach
    static void optimal() {
        int arr[] = { 1, 3, 1, 1, 4, 5, 6 };
        int left = 0, right = 0;
        long sum = arr[0];
        int maxLen = 0;
        int n = arr.length;
        int k = 6;

        /*
         * The outer loop is running for n times, but the second while loop is running
         * for maybe 0/2/1/3 times. So overall it ran for n times but it's overall. If a
         * new n items is introduced, it gets added so we'll add n items to outer n
         * so TC: O(n + n) = O(2n) | SC: O(1)
         */
        while (right < n) {
            while (left <= right && sum > k) {
                sum -= arr[left];
                left++;
            }
            if (sum == k)
                maxLen = Math.max(maxLen, right - left + 1);
            right++;
            if (right < n)
                sum += arr[right];
        }

        System.out.println(maxLen);
    }

    static void moreOptimal() {
        int nums[] = { 1, 2, 3, 3, 1, 1, 1, 1, 4, 5, 6 };

        Map<Long, Integer> sumSeenIndex = new HashMap<>();
        int res = 0;
        long prefSum = 0;
        int k = 4;

        for (int i = 0; i < nums.length; i++) {
            prefSum += nums[i];

            if (sumSeenIndex.containsKey(prefSum - k)) {
                res = Math.max(res, i - sumSeenIndex.get(prefSum - k));
            }

            if (!sumSeenIndex.containsKey(prefSum)) {
                sumSeenIndex.put(prefSum, i);
            }
        }

        System.out.println(res);

    }

    public static void main(String[] args) {
        // brute();
        // better();
        // optimal();
        moreOptimal();
    }

}
