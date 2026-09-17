// you are supposed to find the element that appears more than n/2 times, where n is the size of the array.

import java.util.HashMap;
import java.util.Map;

class majority_element {

    static int brute(int nums[]) {

        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            for (int j = 0; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count > (nums.length / 2)) {
                return nums[i];
            }
        }
        return -1;
    }

    // here keys are in sorted order
    //
    static int better(int nums[]) {
        // SC: O(n log n)
        Map<Integer, Integer> map = new HashMap<>();

        // { 2, 2, 3, 3, 1, 2, 2 }
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                int value = map.get(nums[i]);
                map.replace(nums[i], value + 1);
            } else {
                map.put(nums[i], 1);
            }

            if (map.get(nums[i]) > (nums.length / 2)) {
                return nums[i];
            }
        }
        return -1;
    }

    static int optimal(int nums[]) {

        int element = nums[0], count = 0;

        for (int i = 0; i < nums.length; i++) {
            if (element == nums[i]) {
                count++;
                element = nums[i];
            } else {
                count--;
            }
        }

        if (count > (nums.length / 2)) {
            return element;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] nums = { 2, 2, 3, 3, 1, 2, 2 }; // n / 2 = 3

        // System.out.println(brute(nums));
        // System.out.println(better(nums));
        // System.out.println(better(nums)[j]);
        System.out.println(optimal(nums));
    }

}