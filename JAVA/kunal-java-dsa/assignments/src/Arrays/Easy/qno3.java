// 3. [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)

package Arrays.Easy;

import java.util.Scanner;

public class qno3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] a = new int[4];
        for (int i = 0; i < a.length; i++) {
            a[i] = in.nextInt(); // 1 2 3 4
            runningSum(a);
        }
    }

    static void runningSum(int[] a) {
        int[] b = new int[4];
        b[0] = a[0];
        for (int i = 0; i < a.length; i++) {
            b[i] = b[i - 1] + a[i];
        }
        System.out.println(b);
    }

    // cp solution,
    // 1. can use a var to store the array value in the first then again add that
    // value to the array index again in the same iteration of the for loop
    // 2. or can use two arrays to do so.
    // class Solution {
    // public int[] runningSum(int[] nums) {
    // int res = 0;
    // for(int i=0; i<nums.length;i++){
    // res+=nums[i];
    // nums[i] = res;

    // }
    // return nums;
    // }
    // }

}
