// you are supposed to find the element that appears more than n/2 times, where n is the size of the array.
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

    public static void main(String[] args) {
        int[] nums = { 2, 2, 3, 3, 1, 2, 2 };

        System.out.println(brute(nums));
        // System.out.println(better(nums)[j]);
        // System.out.println(optimal(nums)[j]);
    }

}