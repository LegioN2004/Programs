// 7. [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)

package Arrays.Easy;

public class qno7 {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 1, 1, 3 };
        System.out.println(func(nums));
    }

    static int func(int[] nums){
        int pairs = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if(nums[i] == nums[j]){
                    pairs += 1;
                    System.out.println(nums[i] + " == " + nums[j]);
                    System.out.println("pairs");
                }
            }
        }
        return pairs;
    }
}
