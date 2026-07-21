public class findSingleOccurence {
    private static void brute() {
        int nums[] = { 4, 1, 1, 3, 2, 3, 4 };
        int number = 0;
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count == 1) {
                number = nums[i];
                break;
            } else
                count = 0;
        }

        System.out.println(number);

    }

    private static void better() {
        int nums[] = { 4, 1, 1, 3, 2, 3, 4 };
        int max = nums[0];
        int number = 0;

        for (int i = 0; i < nums.length; i++) // this loop will take O(n)
            max = Math.max(max, nums[i]);

        int hash[] = new int[max + 1];

        for (int i = 0; i < nums.length; i++) // this loop will take O(n)
            hash[nums[i]]++;

        // for (int i = 0; i < hash.length; i++) // this loop will take O(n)
        // if (hash[i] == 1)
        // number = i;

        // using the following is better because it simply takes care of any unncessary
        // iterations of the form max >> n because array length may be 5 but if there is
        // a number like 10000, max = 10000 will create unncessary iterations
        for (int i = 0; i < nums.length; i++) {
            if (hash[nums[i]] == 1)
                number = nums[i];

        }
        System.out.println(number);
    }

    // every number appears twice and total numbers is n.
    // TODO: not done
    // private static void better2() {
    // int nums[] = { 4, 1, 1, 3, 2, 3, 4 };
    // Map<long long, Integer> mapp = new HashMap<>();
    // for (int i : nums) {
    // mapp.put(nums[i], i);
    // }

    // }

    private static void optimal() {
        int nums[] = { 4, 1, 1, 3, 2, 3, 4 };

        int xor1 = 0;

        for (int i = 0; i < nums.length; i++) {
            xor1 ^= nums[i];
        }

        System.out.println(xor1);
    }

    public static void main(String[] args) {
        // brute();
        // better();
        // better2();
        optimal();
    }

}
