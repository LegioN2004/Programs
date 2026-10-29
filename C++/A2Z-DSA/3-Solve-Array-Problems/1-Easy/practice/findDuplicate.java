package practice;

public class findDuplicate {

    static boolean brute(int nums[]) {

        int n = nums.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        int nums[] = { 1, 3, 3, 1, 2, 2, 7, 7 };
        System.out.println(brute(nums));
    }
}
