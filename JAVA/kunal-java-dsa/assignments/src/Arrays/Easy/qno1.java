// 1. [Build Array from Permutation](https://leetcode.com/problems/build-array-from-permutation/)

package Arrays.Easy;

import java.util.Scanner;

public class qno1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] nums = new int[6];
        for (int i = 0; i < nums.length; i++) {
           nums[i] = in.nextInt();
        }
        answer(nums);
    }

    static void answer(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            ans[i] = nums[nums[i]];
            System.out.print(ans[i] + " ");
        }
    }


    // cp answer
//    class Solution {
//        public int[] buildArray(int[] nums) {
//            int[] ans = new int[nums.length];
//            for (int i = 0; i < nums.length; i++) {
//                ans[i] = nums[nums[i]];
//            }
//            return ans;
//        }
//    }
}
