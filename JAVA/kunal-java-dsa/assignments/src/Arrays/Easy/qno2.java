package Arrays.Easy;

import java.util.ArrayList;
import java.util.Scanner;

public class qno2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] nums = new int[1000];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = in.nextInt();
        }
        hello(nums);
    }
    static void hello(int[] nums){
        int n = nums.length - 1;
        int[] ans = new int[2 * n];
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        System.out.println(ans);
    }
}
