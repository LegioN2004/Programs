public class MoveZeroToEnd {
    /*
     * Input: nums = [0,1,0,3,12]
     * Output: [1,3,12,0,0]
     */

    static void brute(int nums[]) {
        int temp[] = new int[nums.length];
        int zeroes = 0;

        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                temp[j] = nums[i];
                j++;
            }
            if (nums[i] == 0)
                zeroes++;
        }

        // nums.length - 1 = 5 - 1 = 4 - zeroes = 4 - 2 = 2;
        for (int i = nums.length - 1; i > ((nums.length - 1) - zeroes); i--) {
            temp[i] = 0;
        }

        for (int i = 0; i < temp.length; i++) {
            nums[i] = temp[i];
            System.out.println(nums[i]);
        }
    }

    static void optimal(int nums[]) {
        if (nums.length == 0)
            return;
        if (nums.length == 1)
            System.out.println("give proper input");
        ;

        int j = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        j = 0; // to avoid any index out of bounds error
        for (int i = j; i < nums.length; i++) {
            if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }

        for (int i = 0; i < nums.length; i++) {
            System.out.println(nums[i]);
        }

    }

    public static void main(String[] args) {
        int nums[] = { 0, 1, 0, 3, 12 };
        // brute(nums);
        optimal(nums);
    }
}
